#include "Runtime/Kernel.hpp"
#include "Threading/Handles.hpp"

#include <__external_threading>
#include <algorithm>
#include <atomic>
#include <cerrno>
#include <exception>
#include <limits>

namespace AnyLibcxx {

int InitializeCondition(void** storage) {
    std::atomic_ref handle(*storage);
    auto current = handle.load(std::memory_order_acquire);
    if (current) return 0;

    void* created = nullptr;
    const auto result = scePthreadCondInit(&created, nullptr, "libc++");
    if (result != 0) return KernelError(result);
    if (!created) std::terminate();
    if (!handle.compare_exchange_strong(current, created, std::memory_order_acq_rel, std::memory_order_acquire)) RequireKernel(scePthreadCondDestroy(&created));
    return 0;
}

}

_LIBCPP_BEGIN_NAMESPACE_STD

int __libcpp_condvar_signal(__libcpp_condvar_t* condition) {
    AnyLibcxx::RequireKernel(AnyLibcxx::InitializeCondition(condition));
    AnyLibcxx::RequireKernel(scePthreadCondSignal(condition));
    return 0;
}

int __libcpp_condvar_broadcast(__libcpp_condvar_t* condition) {
    AnyLibcxx::RequireKernel(AnyLibcxx::InitializeCondition(condition));
    AnyLibcxx::RequireKernel(scePthreadCondBroadcast(condition));
    return 0;
}

int __libcpp_condvar_wait(__libcpp_condvar_t* condition, __libcpp_mutex_t* mutex) {
    const auto result = AnyLibcxx::InitializeCondition(condition);
    if (result != 0) return result;
    return AnyLibcxx::KernelError(scePthreadCondWait(condition, mutex));
}

int __libcpp_condvar_timedwait(__libcpp_condvar_t* condition, __libcpp_mutex_t* mutex, __libcpp_timespec_t* deadline) {
    const auto result = AnyLibcxx::InitializeCondition(condition);
    if (result != 0) return result;
    if (deadline->tv_nsec < 0 || deadline->tv_nsec >= 1000000000) return EINVAL;

    for (;;) {
        AnyLibcxx::KernelTimespec now{};
        AnyLibcxx::RequireKernel(sceKernelClockGettime(0, &now));
        const bool expired = deadline->tv_sec < now.Seconds || (deadline->tv_sec == now.Seconds && deadline->tv_nsec <= now.Nanoseconds);
        unsigned int microseconds = 0;
        if (!expired) {
            auto seconds = static_cast<uint64_t>(deadline->tv_sec) - static_cast<uint64_t>(now.Seconds);
            auto nanoseconds = deadline->tv_nsec - now.Nanoseconds;
            if (nanoseconds < 0) { --seconds; nanoseconds += 1000000000; }
            constexpr auto maximum = numeric_limits<unsigned int>::max();
            microseconds = seconds > maximum / 1000000u ? maximum : static_cast<unsigned int>(min<uint64_t>(maximum, seconds * 1000000u + (nanoseconds + 999) / 1000));
        }

        const auto waited = AnyLibcxx::KernelError(scePthreadCondTimedwait(condition, mutex, microseconds));
        if (waited != ETIMEDOUT || expired) return waited;
    }
}

int __libcpp_condvar_destroy(__libcpp_condvar_t* condition) {
    const auto handle = atomic_ref(*condition).load(memory_order_relaxed);
    if (handle) AnyLibcxx::RequireKernel(scePthreadCondDestroy(condition));
    return 0;
}

_LIBCPP_END_NAMESPACE_STD

