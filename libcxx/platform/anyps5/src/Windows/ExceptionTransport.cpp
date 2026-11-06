#include <stddef.h>
#include <exception>
#include <stdio.h>
#include <wchar.h>

extern "C" {
void __attribute__((sysv_abi)) __cxa_increment_exception_refcount_nid_postfix(void* object);
void __cxa_increment_exception_refcount(void* object) { return __cxa_increment_exception_refcount_nid_postfix(object); }
void __attribute__((sysv_abi)) __cxa_decrement_exception_refcount_nid_postfix(void* object);
void __cxa_decrement_exception_refcount(void* object) { return __cxa_decrement_exception_refcount_nid_postfix(object); }
void* __attribute__((sysv_abi)) __cxa_current_primary_exception_nid_postfix();
void* __cxa_current_primary_exception() { return __cxa_current_primary_exception_nid_postfix(); }
void __attribute__((sysv_abi)) __cxa_rethrow_primary_exception_nid_postfix(void* object);
void __cxa_rethrow_primary_exception(void* object) { return __cxa_rethrow_primary_exception_nid_postfix(object); }
int __attribute__((sysv_abi)) __cxa_guard_acquire_nid_postfix(unsigned long long* guard);
int __cxa_guard_acquire(unsigned long long* guard) { return __cxa_guard_acquire_nid_postfix(guard); }
void __attribute__((sysv_abi)) __cxa_guard_release_nid_postfix(unsigned long long* guard);
void __cxa_guard_release(unsigned long long* guard) { return __cxa_guard_release_nid_postfix(guard); }
void __attribute__((sysv_abi)) __cxa_guard_abort_nid_postfix(unsigned long long* guard);
void __cxa_guard_abort(unsigned long long* guard) { return __cxa_guard_abort_nid_postfix(guard); }
[[noreturn]] void __cxa_pure_virtual() { std::terminate(); }
}
