#include <stddef.h>
#include <memory>
#include <stdexcept>
#define atexit AnyLibcxxTestAtExit
#include "../../src/Windows/AtExit.cpp"
#undef atexit

namespace {
using GuestDestructor = void (__attribute__((sysv_abi)) *)(void*);
using GuestCallback = void (__attribute__((sysv_abi)) *)();
using GuestCompare = int (__attribute__((sysv_abi)) *)(const void*, const void*, void*);
struct Destructor { GuestDestructor Function; void* Argument; };
Destructor destructors[32];
GuestCallback quickCallbacks[32];
unsigned destructorCount;
unsigned quickCount;
unsigned sequence;
void first() { sequence = sequence * 10 + 1; }
void second() { sequence = sequence * 10 + 2; }
int compare(const void* left, const void* right) {
    const auto a = *static_cast<const int*>(left);
    const auto b = *static_cast<const int*>(right);
    return (a > b) - (a < b);
}
}

extern "C" {
int AnyLibcxxTestAtExit(void (*callback)());
int at_quick_exit(void (*callback)());
void qsort(void* data, size_t count, size_t size, int (*callback)(const void*, const void*));
void* bsearch(const void* key, const void* data, size_t count, size_t size, int (*callback)(const void*, const void*));
void __attribute__((sysv_abi)) ClobberVolatileRegisters();
int __attribute__((sysv_abi)) __cxa_atexit_nid_postfix(GuestDestructor callback, void* argument, void* module) {
    if (module || destructorCount == 32) return 1;
    destructors[destructorCount++] = {callback, argument};
    ClobberVolatileRegisters();
    return 0;
}
int __attribute__((sysv_abi)) at_quick_exit_nid_postfix(GuestCallback callback) {
    if (quickCount == 32) return 1;
    quickCallbacks[quickCount++] = callback;
    ClobberVolatileRegisters();
    return 0;
}
int __attribute__((sysv_abi)) qsort_s_nid_postfix(void* data, size_t count, size_t size, GuestCompare callback, void* context) {
    if (size != sizeof(int)) return 1;
    auto* values = static_cast<int*>(data);
    for (size_t i = 0; i < count; ++i) {
        for (size_t j = i + 1; j < count; ++j) {
            if (callback(values + i, values + j, context) > 0) {
                const auto value = values[i];
                values[i] = values[j];
                values[j] = value;
            }
        }
    }
    ClobberVolatileRegisters();
    return 0;
}
void* __attribute__((sysv_abi)) bsearch_s_nid_postfix(const void* key, const void* data, size_t count, size_t size, GuestCompare callback, void* context) {
    if (size != sizeof(int)) return nullptr;
    const auto* values = static_cast<const int*>(data);
    for (size_t i = 0; i < count; ++i) {
        if (callback(key, values + i, context) == 0) {
            ClobberVolatileRegisters();
            return const_cast<int*>(values + i);
        }
    }
    return nullptr;
}
}

int main() {
    const auto initial = destructorCount;
    if (AnyLibcxxTestAtExit(first) != 0 || AnyLibcxxTestAtExit(second) != 0 || destructorCount != initial + 2) return 1;
    while (destructorCount > initial) {
        const auto value = destructors[--destructorCount];
        value.Function(value.Argument);
    }
    if (sequence != 21) return 2;
    sequence = 0;
    if (at_quick_exit(first) != 0 || at_quick_exit(second) != 0 || quickCount != 2) return 3;
    while (quickCount) quickCallbacks[--quickCount]();
    if (sequence != 21) return 4;
    int values[]{5, 1, 3, 2, 4};
    qsort(values, 5, sizeof(int), compare);
    for (int i = 0; i < 5; ++i) if (values[i] != i + 1) return 5;
    const int key = 3;
    return bsearch(&key, values, 5, sizeof(int), compare) == values + 2 ? 0 : 6;
}
