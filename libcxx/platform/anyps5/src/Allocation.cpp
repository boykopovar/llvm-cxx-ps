#include "Allocation/Api.hpp"
#include <stdlib.h>
extern "C" {
void* malloc(size_t size) noexcept(noexcept(::malloc(size))) { return AnyLibcxx::Allocation::Malloc(size); }
void free(void* pointer) noexcept(noexcept(::free(pointer))) { AnyLibcxx::Allocation::Free(pointer); }
void* calloc(size_t count, size_t size) noexcept(noexcept(::calloc(count, size))) { return AnyLibcxx::Allocation::Calloc(count, size); }
void* realloc(void* pointer, size_t size) noexcept(noexcept(::realloc(pointer, size))) { return AnyLibcxx::Allocation::Realloc(pointer, size); }
void* aligned_alloc(size_t alignment, size_t size) noexcept(noexcept(::aligned_alloc(alignment, size))) { return AnyLibcxx::Allocation::AlignedAlloc(alignment, size); }
}
