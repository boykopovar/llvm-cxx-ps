#include <stddef.h>
#include <stdexcept>

namespace {
using Compare = int (*)(const void*, const void*);
int __attribute__((sysv_abi)) compare(const void* left, const void* right, void* context) {
    return (*static_cast<Compare*>(context))(left, right);
}
}

extern "C" {
int __attribute__((sysv_abi)) qsort_s_nid_postfix(void* data, size_t count, size_t size, int (__attribute__((sysv_abi)) *callback)(const void*, const void*, void*), void* context);
void* __attribute__((sysv_abi)) bsearch_s_nid_postfix(const void* key, const void* data, size_t count, size_t size, int (__attribute__((sysv_abi)) *callback)(const void*, const void*, void*), void* context);
void qsort(void* data, size_t count, size_t size, Compare callback) {
    if (qsort_s_nid_postfix(data, count, size, compare, &callback) != 0) throw std::runtime_error("qsort failed");
}
void* bsearch(const void* key, const void* data, size_t count, size_t size, Compare callback) {
    return bsearch_s_nid_postfix(key, data, count, size, compare, &callback);
}
}
