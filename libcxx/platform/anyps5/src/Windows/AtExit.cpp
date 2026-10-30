#include <memory>
#include <stdexcept>

namespace {
using Callback = void (*)();
void __attribute__((sysv_abi)) invoke(void* argument) {
    const auto callback = *static_cast<Callback*>(argument);
    delete static_cast<Callback*>(argument);
    callback();
}
}

extern "C" {
int __attribute__((sysv_abi)) __cxa_atexit_nid_postfix(void (__attribute__((sysv_abi)) *callback)(void*), void* argument, void* module);
int atexit(Callback callback) {
    if (!callback) throw std::invalid_argument("Null exit callback");
    auto value = std::make_unique<Callback>(callback);
    const auto result = __cxa_atexit_nid_postfix(invoke, value.get(), nullptr);
    if (result == 0) value.release();
    return result;
}
}
