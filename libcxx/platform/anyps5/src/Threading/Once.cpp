#include "Runtime/Kernel.hpp"

#include <__external_threading>
#include <atomic>
#include <exception>

_LIBCPP_BEGIN_NAMESPACE_STD

int __libcpp_execute_once(__libcpp_exec_once_flag* flag, void (*initialize)()) {
    atomic_ref state(*flag);
    for (;;) {
        auto value = state.load(memory_order_acquire);
        if (value == 2) return 0;
        if (value > 2) terminate();
        if (value == 0 && state.compare_exchange_strong(value, 1, memory_order_acq_rel, memory_order_acquire)) {
            try {
                initialize();
            } catch (...) {
                state.store(0, memory_order_release);
                throw;
            }
            state.store(2, memory_order_release);
            return 0;
        }
        scePthreadYield();
    }
}

_LIBCPP_END_NAMESPACE_STD

