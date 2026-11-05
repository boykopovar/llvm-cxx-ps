#ifndef ANYLIBCXX_ALLOCATION_HEAP_HPP
#define ANYLIBCXX_ALLOCATION_HEAP_HPP
#include <cstddef>
namespace AnyLibcxx::Allocation {
void* Allocate(std::size_t size, std::size_t alignment) noexcept;
void Release(void* pointer) noexcept;
std::size_t Size(const void* pointer) noexcept;
}
#endif
