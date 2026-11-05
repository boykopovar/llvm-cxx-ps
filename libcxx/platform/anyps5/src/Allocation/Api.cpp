#include "Allocation/Heap.hpp"
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include "Allocation/Api.hpp"
#include <string.h>
#include <limits>
namespace AnyLibcxx::Allocation {
void* Malloc(size_t size) noexcept {
    auto* pointer = AnyLibcxx::Allocation::Allocate(size, alignof(max_align_t));
    if (!pointer) errno = ENOMEM;
    return pointer;
}
void Free(void* pointer) noexcept { AnyLibcxx::Allocation::Release(pointer); }
void* Calloc(size_t count, size_t size) noexcept {
    if (size && count > std::numeric_limits<size_t>::max() / size) { errno = ENOMEM; return nullptr; }
    auto* pointer = Malloc(count * size);
    if (pointer) memset(pointer, 0, count * size);
    return pointer;
}
void* Realloc(void* pointer, size_t size) noexcept {
    if (!pointer) return Malloc(size);
    if (!size) { Free(pointer); return nullptr; }
    const auto previous = AnyLibcxx::Allocation::Size(pointer);
    auto* replacement = Malloc(size);
    if (!replacement) return nullptr;
    memcpy(replacement, pointer, previous < size ? previous : size);
    Free(pointer);
    return replacement;
}
void* AlignedAlloc(size_t alignment, size_t size) noexcept {
    if (!alignment || (alignment & (alignment - 1)) || size % alignment) { errno = EINVAL; return nullptr; }
    auto* pointer = AnyLibcxx::Allocation::Allocate(size, alignment);
    if (!pointer) errno = ENOMEM;
    return pointer;
}
}
