#include <atomic>
#include <memory>
#include <stdexcept>

namespace {
using Callback = void (*)();
struct Entry { Callback Function; Entry* Next; };
std::atomic<Entry*> callbacks;
void __attribute__((sysv_abi)) invoke() {
    auto* entry = callbacks.load();
    do {
        if (!entry) throw std::runtime_error("Missing quick exit callback");
    } while (!callbacks.compare_exchange_weak(entry, entry->Next));
    const auto callback = entry->Function;
    delete entry;
    callback();
}
}

extern "C" {
int __attribute__((sysv_abi)) at_quick_exit_nid_postfix(void (__attribute__((sysv_abi)) *callback)());
int at_quick_exit(Callback callback) {
    if (!callback) throw std::invalid_argument("Null quick exit callback");
    auto entry = std::make_unique<Entry>(Entry{callback, nullptr});
    const auto result = at_quick_exit_nid_postfix(invoke);
    if (result != 0) return result;
    entry->Next = callbacks.load();
    while (!callbacks.compare_exchange_weak(entry->Next, entry.get())) {}
    entry.release();
    return 0;
}
}
