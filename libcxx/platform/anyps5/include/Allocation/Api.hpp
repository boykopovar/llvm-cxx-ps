#ifndef ANYLIBCXX_ALLOCATION_API_HPP
#define ANYLIBCXX_ALLOCATION_API_HPP
#include <cstddef>
namespace AnyLibcxx::Allocation {
void* Malloc(std::size_t size) noexcept;
void Free(void* pointer) noexcept;
void* Calloc(std::size_t count, std::size_t size) noexcept;
void* Realloc(void* pointer, std::size_t size) noexcept;
void* AlignedAlloc(std::size_t alignment, std::size_t size) noexcept;
}
#endif
