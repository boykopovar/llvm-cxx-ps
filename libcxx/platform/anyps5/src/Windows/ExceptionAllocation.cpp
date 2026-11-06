#include <cstddef>
#include <cstdlib>
#include <exception>

namespace __cxxabiv1 {
void* __aligned_malloc_with_fallback(std::size_t size) {
    auto* pointer = std::malloc(size);
    if (pointer == nullptr) std::terminate();
    return pointer;
}
void* __calloc_with_fallback(std::size_t count, std::size_t size) {
    auto* pointer = std::calloc(count, size);
    if (pointer == nullptr) std::terminate();
    return pointer;
}
void __aligned_free_with_fallback(void* pointer) { std::free(pointer); }
void __free_with_fallback(void* pointer) { std::free(pointer); }
}
