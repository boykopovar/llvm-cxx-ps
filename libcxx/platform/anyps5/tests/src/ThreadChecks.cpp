#include "ThreadChecks.hpp"

#include <atomic>
#include <barrier>
#include <chrono>
#include <condition_variable>
#include <future>
#include <latch>
#include <mutex>
#include <semaphore>
#include <shared_mutex>
#include <stdexcept>
#include <system_error>
#include <thread>
#include <vector>

namespace {

void require(bool condition, const char* message) {
    if (!condition) throw std::runtime_error(message);
}

}

void RunThreadChecks() {
    using namespace std::chrono_literals;
    require(std::thread::hardware_concurrency() > 0, "Missing guest CPU count");
    require(std::this_thread::get_id() != std::thread::id{}, "Missing current thread identity");

    const auto before = std::chrono::steady_clock::now();
    const auto system = std::chrono::system_clock::now();
    std::this_thread::sleep_for(2ms);
    require(std::chrono::steady_clock::now() - before >= 2ms, "Monotonic sleep completed early");
    require(std::chrono::system_clock::now() >= system, "System clock moved backwards during the check");
    std::this_thread::sleep_until(std::chrono::steady_clock::now() + 1ms);

    {
        std::thread empty;
        bool rejected = false;
        try { empty.join(); } catch (const std::system_error& error) {
            rejected = error.code() == std::errc::invalid_argument && error.what()[0] != 0;
        }
        require(rejected, "Invalid thread join did not report a system error");
    }

    {
        std::mutex mutex;
        int counter = 0;
        std::vector<std::thread> threads;
        for (int index = 0; index < 4; ++index) threads.emplace_back([&] {
            for (int step = 0; step < 1000; ++step) { std::lock_guard lock(mutex); ++counter; }
        });
        for (auto& thread : threads) thread.join();
        require(counter == 4000, "Mutex did not serialize concurrent increments");

        std::recursive_mutex recursive;
        std::lock_guard first(recursive);
        std::lock_guard second(recursive);
        require(recursive.try_lock(), "Recursive mutex did not permit recursive ownership");
        recursive.unlock();
    }

    {
        std::mutex mutex;
        std::condition_variable condition;
        bool ready = false;
        std::thread worker([&] {
            { std::lock_guard lock(mutex); ready = true; }
            condition.notify_all();
        });
        std::unique_lock lock(mutex);
        require(condition.wait_for(lock, 2s, [&] { return ready; }), "Condition notification was lost");
        lock.unlock();
        worker.join();
        lock.lock();
        const auto timeoutStart = std::chrono::steady_clock::now();
        require(!condition.wait_for(lock, 2ms, [] { return false; }) && std::chrono::steady_clock::now() - timeoutStart >= 2ms, "Condition timeout was not reported");
    }

    {
        std::timed_mutex mutex;
        mutex.lock();
        auto result = std::async(std::launch::async, [&] { return mutex.try_lock_for(2ms); });
        require(!result.get(), "Timed mutex ignored another thread's ownership");
        mutex.unlock();
        require(mutex.try_lock_for(2ms), "Timed mutex failed after release");
        mutex.unlock();

        std::shared_mutex shared;
        std::shared_lock read(shared);
        auto reader = std::async(std::launch::async, [&] { std::shared_lock other(shared); return 42; });
        require(reader.get() == 42, "Shared mutex rejected concurrent readers");

        std::recursive_timed_mutex recursive;
        std::lock_guard first(recursive);
        require(recursive.try_lock_for(2ms), "Recursive timed mutex did not preserve ownership");
        recursive.unlock();

        std::shared_timed_mutex timedShared;
        timedShared.lock();
        auto blocked = std::async(std::launch::async, [&] { return timedShared.try_lock_shared_for(2ms); });
        require(!blocked.get(), "Timed shared mutex ignored exclusive ownership");
        timedShared.unlock();
    }

    {
        std::once_flag flag;
        std::atomic<int> attempts{0};
        int initialized = 0;
        const auto initialize = [&] {
            if (attempts.fetch_add(1) == 0) throw std::runtime_error("Retry initialization");
            ++initialized;
        };
        try { std::call_once(flag, initialize); } catch (const std::runtime_error&) {}
        std::thread worker([&] { std::call_once(flag, initialize); });
        std::call_once(flag, initialize);
        worker.join();
        require(attempts == 2 && initialized == 1, "call_once did not recover from an exception");
    }

    {
        std::atomic<int> value{0};
        std::latch started(1);
        std::thread worker([&] { started.count_down(); value.wait(0); value.store(2); });
        started.wait();
        std::this_thread::sleep_for(2ms);
        value.store(1);
        value.notify_one();
        worker.join();
        require(value == 2, "Atomic wait was not released");

        std::binary_semaphore semaphore(0);
        std::thread signaller([&] { semaphore.release(); });
        require(semaphore.try_acquire_for(2s), "Semaphore notification was lost");
        signaller.join();

        std::barrier barrier(2);
        std::thread participant([&] { barrier.arrive_and_wait(); });
        barrier.arrive_and_wait();
        participant.join();
    }

    {
        std::promise<int> promise;
        auto value = promise.get_future();
        std::thread worker([&] { promise.set_value_at_thread_exit(42); });
        require(value.get() == 42, "Thread exit did not make the future ready");
        worker.join();

        std::promise<std::thread::id> identity;
        auto identified = identity.get_future();
        std::thread detached([&] { identity.set_value_at_thread_exit(std::this_thread::get_id()); });
        const auto expected = detached.get_id();
        detached.detach();
        require(!detached.joinable() && identified.get() == expected, "Detached thread identity or cleanup failed");
    }

    {
        std::mutex mutex;
        std::condition_variable_any condition;
        std::latch started(1);
        bool stopped = false;
        std::jthread worker([&](std::stop_token token) {
            std::unique_lock lock(mutex);
            started.count_down();
            stopped = !condition.wait(lock, token, [] { return false; });
        });
        started.wait();
        worker.request_stop();
        worker.join();
        require(stopped, "jthread stop did not interrupt the condition wait");
    }
}

