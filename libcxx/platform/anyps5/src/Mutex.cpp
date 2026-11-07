#include "Runtime/Kernel.hpp"
#include "Threading/Handles.hpp"

#include <__external_threading>
#include <atomic>
#include <cerrno>
#include <exception>

namespace AnyLibcxx {

int InitializeMutex(void** storage) {
    std::atomic_ref handle(*storage);
    auto current = handle.load(std::memory_order_acquire);
    if (current) return 0;

    void* created = nullptr;
    const auto result = scePthreadMutexInit(&created, nullptr, "libc++");
    if (result != 0) return KernelError(result);
    if (!created) std::terminate();
    if (!handle.compare_exchange_strong(current, created, std::memory_order_acq_rel, std::memory_order_acquire)) RequireKernel(scePthreadMutexDestroy(&created));
    return 0;
}

}

_LIBCPP_BEGIN_NAMESPACE_STD

int __libcpp_mutex_lock(__libcpp_mutex_t* mutex) {
    const auto result = AnyLibcxx::InitializeMutex(mutex);
    if (result != 0) return result;
    return AnyLibcxx::KernelError(scePthreadMutexLock(mutex));
}

bool __libcpp_mutex_trylock(__libcpp_mutex_t* mutex) {
    AnyLibcxx::RequireKernel(AnyLibcxx::InitializeMutex(mutex));
    const auto result = AnyLibcxx::KernelError(scePthreadMutexTrylock(mutex));
    if (result == EBUSY) return false;
    AnyLibcxx::RequireKernel(result);
    return true;
}

int __libcpp_mutex_unlock(__libcpp_mutex_t* mutex) {
    const auto handle = atomic_ref(*mutex).load(memory_order_acquire);
    if (!handle) terminate();
    AnyLibcxx::RequireKernel(scePthreadMutexUnlock(mutex));
    return 0;
}

int __libcpp_mutex_destroy(__libcpp_mutex_t* mutex) {
    const auto handle = atomic_ref(*mutex).load(memory_order_relaxed);
    if (handle) AnyLibcxx::RequireKernel(scePthreadMutexDestroy(mutex));
    return 0;
}

int __libcpp_recursive_mutex_init(__libcpp_recursive_mutex_t* mutex) {
    void* attributes = nullptr;
    auto result = scePthreadMutexattrInit(&attributes);
    if (result != 0) return AnyLibcxx::KernelError(result);

    result = scePthreadMutexattrSettype(&attributes, 2);
    if (result == 0) result = scePthreadMutexInit(mutex, &attributes, "libc++ recursive");
    AnyLibcxx::RequireKernel(scePthreadMutexattrDestroy(&attributes));
    return AnyLibcxx::KernelError(result);
}

int __libcpp_recursive_mutex_lock(__libcpp_recursive_mutex_t* mutex) { return __libcpp_mutex_lock(mutex); }
bool __libcpp_recursive_mutex_trylock(__libcpp_recursive_mutex_t* mutex) { return __libcpp_mutex_trylock(mutex); }
int __libcpp_recursive_mutex_unlock(__libcpp_recursive_mutex_t* mutex) { return __libcpp_mutex_unlock(mutex); }
int __libcpp_recursive_mutex_destroy(__libcpp_recursive_mutex_t* mutex) { return __libcpp_mutex_destroy(mutex); }

_LIBCPP_END_NAMESPACE_STD

