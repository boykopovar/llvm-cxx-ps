#include <mutex>
#include <stdexcept>
#include <type_traits>

static_assert(std::is_nothrow_default_constructible_v<std::mutex>);
static_assert(std::is_nothrow_destructible_v<std::mutex>);
static_assert(!std::is_copy_constructible_v<std::mutex>);
static_assert(!std::is_move_constructible_v<std::mutex>);
static_assert(noexcept(std::declval<std::mutex&>().try_lock()));
static_assert(noexcept(std::declval<std::mutex&>().unlock()));

constinit std::mutex GlobalMutex;

void RunMutexChecks() {
    std::mutex unused;
    std::mutex mutex;
    if (!mutex.try_lock()) throw std::runtime_error("Uncontended mutex was not acquired");
    {
        std::lock_guard<std::mutex> guard(mutex, std::adopt_lock);
        if (!*mutex.native_handle()) throw std::runtime_error("Missing native mutex handle");
    }
    bool caught = false;
    try {
        std::lock_guard guard(mutex);
        throw 17;
    } catch (int value) {
        caught = value == 17;
    }
    if (!caught || !mutex.try_lock()) throw std::runtime_error("Exception unwinding did not release the mutex");
    mutex.unlock();
    std::lock_guard guard(GlobalMutex);
}
