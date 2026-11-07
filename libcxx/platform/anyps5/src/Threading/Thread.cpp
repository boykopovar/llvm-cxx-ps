#include "Threading/Callbacks.hpp"

#include <__external_threading>
#include <bit>
#include <cerrno>
#include <exception>
#include <memory>
#include <new>

namespace {

struct ThreadStart {
    void* (*Entry)(void*);
    void* Argument;
};

struct ThreadValue {
    void (*Destructor)(void*);
    void* Value;
};

}

namespace AnyLibcxx {

void* RunThread(void* argument) noexcept {
    auto start = std::unique_ptr<ThreadStart>(static_cast<ThreadStart*>(argument));
    const auto entry = start->Entry;
    const auto value = start->Argument;
    start.reset();
    return entry(value);
}

void DestroyValue(void* argument) noexcept {
    auto node = std::unique_ptr<ThreadValue>(static_cast<ThreadValue*>(argument));
    const auto destructor = node->Destructor;
    const auto value = node->Value;
    node.reset();
    if (destructor) destructor(value);
}

}

_LIBCPP_BEGIN_NAMESPACE_STD

bool __libcpp_thread_id_equal(__libcpp_thread_id left, __libcpp_thread_id right) { return left == right; }
bool __libcpp_thread_id_less(__libcpp_thread_id left, __libcpp_thread_id right) { return reinterpret_cast<uintptr_t>(left) < reinterpret_cast<uintptr_t>(right); }
bool __libcpp_thread_isnull(const __libcpp_thread_t* thread) { return *thread == nullptr; }
__libcpp_thread_id __libcpp_thread_get_current_id() { return scePthreadSelf(); }
__libcpp_thread_id __libcpp_thread_get_id(const __libcpp_thread_t* thread) { return *thread; }

int __libcpp_thread_create(__libcpp_thread_t* thread, void* (*entry)(void*), void* argument) {
    auto start = unique_ptr<ThreadStart>(new (nothrow) ThreadStart{entry, argument});
    if (!start) return ENOMEM;
    const auto result = scePthreadCreate(thread, nullptr, AnyLibcxx::ThreadEntry, start.get(), "libc++ thread");
    if (result == 0) start.release();
    return AnyLibcxx::KernelError(result);
}

int __libcpp_thread_join(__libcpp_thread_t* thread) { return AnyLibcxx::KernelError(scePthreadJoin(*thread, nullptr)); }
int __libcpp_thread_detach(__libcpp_thread_t* thread) { return AnyLibcxx::KernelError(scePthreadDetach(*thread)); }
void __libcpp_thread_yield() { scePthreadYield(); }

unsigned int __libcpp_thread_hardware_concurrency() {
    uint64_t mask = 0;
    AnyLibcxx::RequireKernel(scePthreadGetaffinity(scePthreadSelf(), &mask));
    if (mask == 0) terminate();
    return static_cast<unsigned int>(popcount(mask));
}

void __libcpp_thread_sleep_for(const chrono::nanoseconds& duration) {
    const auto seconds = chrono::duration_cast<chrono::seconds>(duration);
    AnyLibcxx::KernelTimespec requested{seconds.count(), (duration - seconds).count()};
    for (;;) {
        AnyLibcxx::KernelTimespec remaining{};
        const auto result = AnyLibcxx::KernelError(sceKernelNanosleep(&requested, &remaining));
        if (result == 0) return;
        if (result != EINTR) terminate();
        requested = remaining;
    }
}

int __libcpp_tls_create(__libcpp_tls_key* key, void (*destructor)(void*)) {
    const auto result = scePthreadKeyCreate(&key->Key, AnyLibcxx::TlsDestructor);
    if (result == 0) key->Destructor = destructor;
    return AnyLibcxx::KernelError(result);
}

void* __libcpp_tls_get(__libcpp_tls_key key) {
    const auto node = static_cast<ThreadValue*>(scePthreadGetspecific(key.Key));
    return node ? node->Value : nullptr;
}

int __libcpp_tls_set(__libcpp_tls_key key, void* value) {
    const auto previous = static_cast<ThreadValue*>(scePthreadGetspecific(key.Key));
    auto replacement = unique_ptr<ThreadValue>(value ? new (nothrow) ThreadValue{key.Destructor, value} : nullptr);
    if (value && !replacement) return ENOMEM;
    const auto result = scePthreadSetspecific(key.Key, replacement.get());
    if (result == 0) {
        replacement.release();
        delete previous;
    }
    return AnyLibcxx::KernelError(result);
}

_LIBCPP_END_NAMESPACE_STD

