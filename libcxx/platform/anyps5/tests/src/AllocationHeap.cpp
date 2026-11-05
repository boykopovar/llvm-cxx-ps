#include "Allocation/Api.hpp"
#include "Allocation/Heap.hpp"
#include <array>
#include <atomic>
#include <cstdlib>
#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <limits>
#include <thread>
#include <vector>
namespace {
void require(bool condition) { if (!condition) std::abort(); }
constexpr std::size_t PageSize = 131072;
constexpr std::size_t StorageSize = 128 * 1024 * 1024;
alignas(64) std::byte backing[StorageSize + PageSize];
auto* storage = reinterpret_cast<std::byte*>((reinterpret_cast<std::uintptr_t>(backing) + PageSize - 1) & ~(PageSize - 1));
std::array<bool, StorageSize / PageSize> pages{};
std::size_t livePages = 0;
bool failNextMapping = false;
struct Record { void* Pointer; std::size_t Size; unsigned char Value; };
void check(const Record& record) {
    const auto* bytes = static_cast<const unsigned char*>(record.Pointer);
    for (std::size_t i = 0; i < record.Size; ++i) require(bytes[i] == record.Value);
}
Record create(std::size_t size, std::size_t alignment, unsigned char value) {
    auto* pointer = AnyLibcxx::Allocation::Allocate(size, alignment);
    require(pointer && reinterpret_cast<std::uintptr_t>(pointer) % alignment == 0);
    require(AnyLibcxx::Allocation::Size(pointer) == (size ? size : 1));
    auto* bytes = static_cast<unsigned char*>(pointer);
    for (std::size_t i = 0; i < size; ++i) bytes[i] = value;
    return {pointer, size, value};
}
}
extern "C" {
std::size_t __attribute__((sysv_abi)) sceKernelGetDirectMemorySize() { return StorageSize; }
int __attribute__((sysv_abi)) sceKernelAllocateDirectMemory(std::int64_t, std::int64_t, std::size_t size, std::size_t alignment, int type, std::int64_t* physical) {
    require(size % PageSize == 0 && alignment == PageSize && type == 12);
    const auto count = size / PageSize;
    for (std::size_t i = 0; count <= pages.size() && i <= pages.size() - count; ++i) {
        bool available = true;
        for (std::size_t j = 0; j < count; ++j) if (pages[i + j]) { available = false; i += j; break; }
        if (!available) continue;
        for (std::size_t j = 0; j < count; ++j) pages[i + j] = true;
        livePages += count;
        *physical = static_cast<std::int64_t>(i * PageSize);
        return 0;
    }
    return -1;
}
int __attribute__((sysv_abi)) sceKernelMapDirectMemory(void** address, std::size_t size, int protection, int flags, std::int64_t physical, std::size_t alignment) {
    require(protection == 3 && flags == 0 && alignment == PageSize);
    if (failNextMapping) { failNextMapping = false; return -1; }
    require(physical >= 0 && static_cast<std::size_t>(physical) + size <= StorageSize);
    *address = storage + physical;
    return 0;
}
int __attribute__((sysv_abi)) sceKernelMunmap(std::uintptr_t address, std::size_t size) {
    require(address >= reinterpret_cast<std::uintptr_t>(storage) && address + size <= reinterpret_cast<std::uintptr_t>(storage) + StorageSize);
    return 0;
}
int __attribute__((sysv_abi)) sceKernelReleaseDirectMemory(std::int64_t physical, std::size_t size) {
    for (auto i = static_cast<std::size_t>(physical) / PageSize; i < (static_cast<std::size_t>(physical) + size) / PageSize; ++i) { require(pages[i]); pages[i] = false; --livePages; }
    return 0;
}
}
int main() {
    using namespace AnyLibcxx::Allocation;
    failNextMapping = true;
    require(!Allocate(128, 16));
    require(livePages == 0);
    auto* bytes = static_cast<unsigned char*>(Calloc(17, 3));
    require(bytes);
    for (unsigned i = 0; i < 51; ++i) { require(bytes[i] == 0); bytes[i] = static_cast<unsigned char>(i); }
    auto* grown = static_cast<unsigned char*>(Realloc(bytes, 100000));
    require(grown);
    for (unsigned i = 0; i < 51; ++i) require(grown[i] == i);
    require(!Realloc(grown, std::numeric_limits<std::size_t>::max()));
    for (unsigned i = 0; i < 51; ++i) require(grown[i] == i);
    require(!Realloc(grown, 0));
    require(!Calloc(std::numeric_limits<std::size_t>::max(), 2) && errno == ENOMEM);
    require(!AlignedAlloc(64, 65) && errno == EINVAL);
    auto* aligned = AlignedAlloc(4096, 8192);
    require(aligned && reinterpret_cast<std::uintptr_t>(aligned) % 4096 == 0);
    Free(aligned);
    Free(Malloc(0));
    Free(nullptr);
    require(!Allocate(std::numeric_limits<std::size_t>::max(), 16));
    require(!Allocate(16, 3));
    require(!Allocate(256 * 1024 * 1024, 16));
    Release(nullptr);
    for (std::size_t alignment = 1; alignment <= 1048576; alignment *= 2) {
        auto value = create(alignment + 7, alignment, 0x5a);
        check(value); Release(value.Pointer);
    }
    std::array<Record, 256> records{};
    std::uint32_t random = 13817;
    for (unsigned i = 0; i < 20000; ++i) {
        random = random * 1664525 + 1013904223;
        auto& value = records[(random >> 16) % records.size()];
        if (value.Pointer) { check(value); Release(value.Pointer); value = {}; }
        const auto size = (random % 16384) + (i % 137 == 0 ? 1048576 : 0);
        value = create(size, std::size_t{1} << ((random >> 24) % 13), static_cast<unsigned char>(i));
    }
    for (const auto& value : records) if (value.Pointer) { check(value); Release(value.Pointer); }
    require(livePages == 0);
    std::vector<std::thread> threads;
    for (unsigned thread = 0; thread < 4; ++thread) threads.emplace_back([thread] {
        for (unsigned i = 0; i < 2000; ++i) {
            auto first = create(31 + (i * 79) % 8192, 64, static_cast<unsigned char>(thread));
            auto second = create(193 + (i * 131) % 16384, 256, static_cast<unsigned char>(i));
            check(first); Release(first.Pointer); check(second); Release(second.Pointer);
        }
    });
    for (auto& thread : threads) thread.join();
    require(livePages == 0);
    std::puts("allocation heap: alignment, exhaustion, coalescing, contents and concurrency passed");
}
