#include <atomic>
#include <cstdint>
#include <exception>
#include <mutex>
#include <system_error>

extern "C" {
int __attribute__((sysv_abi)) scePthreadMutexInit(void** mutex, void* const* attributes, const char* name);
int __attribute__((sysv_abi)) scePthreadMutexDestroy(void** mutex);
int __attribute__((sysv_abi)) scePthreadMutexLock(void** mutex);
int __attribute__((sysv_abi)) scePthreadMutexTrylock(void** mutex);
int __attribute__((sysv_abi)) scePthreadMutexUnlock(void** mutex);
}

namespace {
void require(int result) noexcept {
    if (result != 0) std::terminate();
}

void* initialize(void*& storage) {
    std::atomic_ref<void*> handle(storage);
    auto current = handle.load(std::memory_order_acquire);
    if (current) return current;
    void* created = nullptr;
    const auto result = scePthreadMutexInit(&created, nullptr, "libc++");
    if (result != 0) throw std::system_error(result, std::system_category(), "scePthreadMutexInit");
    if (!created) std::terminate();
    if (handle.compare_exchange_strong(current, created, std::memory_order_acq_rel, std::memory_order_acquire)) return created;
    require(scePthreadMutexDestroy(&created));
    return current;
}
}

_LIBCPP_BEGIN_NAMESPACE_STD
mutex::~mutex() noexcept {
    auto handle = atomic_ref<void*>(__m_).load(memory_order_relaxed);
    if (handle) require(scePthreadMutexDestroy(&handle));
}

void mutex::lock() {
    auto handle = initialize(__m_);
    const auto result = scePthreadMutexLock(&handle);
    if (result != 0) {
        if (static_cast<uint32_t>(result) == 0x8002000b) throw system_error(make_error_code(errc::resource_deadlock_would_occur), "scePthreadMutexLock");
        throw system_error(result, system_category(), "scePthreadMutexLock");
    }
}

bool mutex::try_lock() noexcept {
    auto handle = initialize(__m_);
    const auto result = scePthreadMutexTrylock(&handle);
    if (static_cast<uint32_t>(result) == 0x80020010) return false;
    require(result);
    return true;
}

void mutex::unlock() noexcept {
    auto handle = atomic_ref<void*>(__m_).load(memory_order_acquire);
    if (!handle) terminate();
    require(scePthreadMutexUnlock(&handle));
}
_LIBCPP_END_NAMESPACE_STD
