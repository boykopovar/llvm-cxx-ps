#include "Allocation/Heap.hpp"
#include <atomic>
#include <bit>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <iterator>
#include <new>
extern "C" {
std::size_t __attribute__((sysv_abi)) sceKernelGetDirectMemorySize();
int __attribute__((sysv_abi)) sceKernelAllocateDirectMemory(std::int64_t start, std::int64_t end, std::size_t size, std::size_t alignment, int type, std::int64_t* physical);
int __attribute__((sysv_abi)) sceKernelMapDirectMemory(void** address, std::size_t size, int protection, int flags, std::int64_t physical, std::size_t alignment);
int __attribute__((sysv_abi)) sceKernelMunmap(std::uintptr_t address, std::size_t size);
int __attribute__((sysv_abi)) sceKernelReleaseDirectMemory(std::int64_t physical, std::size_t size);
}
namespace AnyLibcxx::Allocation {
namespace {
constexpr std::size_t Alignment = alignof(std::max_align_t);
constexpr std::size_t PageSize = 131072;
constexpr std::size_t ArenaSize = 2097152;
constexpr std::uintptr_t Signature = 0x41444b414c4c4f43;
struct alignas(std::max_align_t) Arena {
    std::size_t Size;
    std::size_t Active;
    std::int64_t Physical;
};
struct alignas(std::max_align_t) Block {
    std::size_t Size;
    std::size_t PreviousSize;
    Block* PreviousFree;
    Block* NextFree;
    Arena* Owner;
    bool Free;
};
struct alignas(std::max_align_t) Allocation {
    std::uintptr_t Magic;
    Block* Storage;
    std::size_t Size;
};
constinit std::atomic_flag gate = ATOMIC_FLAG_INIT;
constinit Block* bins[std::numeric_limits<std::size_t>::digits]{};
class Guard final {
public:
    Guard() noexcept { while (gate.test_and_set(std::memory_order_acquire)) {} }
    ~Guard() { gate.clear(std::memory_order_release); }
};
void require(bool condition) noexcept { if (!condition) std::abort(); }
std::size_t bin(std::size_t size) noexcept { return std::bit_width(size) - 1; }
std::byte* end(const Arena* arena) noexcept { return reinterpret_cast<std::byte*>(const_cast<Arena*>(arena)) + arena->Size; }
Block* next(Block* block) noexcept {
    auto* address = reinterpret_cast<std::byte*>(block) + block->Size;
    return address == end(block->Owner) ? nullptr : reinterpret_cast<Block*>(address);
}
void insert(Block* block) noexcept {
    const auto index = bin(block->Size);
    block->Free = true;
    block->PreviousFree = nullptr;
    block->NextFree = bins[index];
    if (bins[index]) bins[index]->PreviousFree = block;
    bins[index] = block;
}
void remove(Block* block) noexcept {
    if (block->PreviousFree) block->PreviousFree->NextFree = block->NextFree;
    else bins[bin(block->Size)] = block->NextFree;
    if (block->NextFree) block->NextFree->PreviousFree = block->PreviousFree;
    block->PreviousFree = nullptr;
    block->NextFree = nullptr;
    block->Free = false;
}
Block* create(std::size_t size) noexcept {
    constexpr auto Maximum = std::numeric_limits<std::size_t>::max();
    if (size > Maximum - sizeof(Arena) - (PageSize - 1)) return nullptr;
    auto total = (size + sizeof(Arena) + PageSize - 1) & ~(PageSize - 1);
    if (total < ArenaSize) total = ArenaSize;
    std::int64_t physical = 0;
    if (sceKernelAllocateDirectMemory(0, sceKernelGetDirectMemorySize(), total, PageSize, 12, &physical) != 0) return nullptr;
    void* address = nullptr;
    if (sceKernelMapDirectMemory(&address, total, 3, 0, physical, PageSize) != 0) {
        require(sceKernelReleaseDirectMemory(physical, total) == 0);
        return nullptr;
    }
    auto* arena = ::new (address) Arena{total, 0, physical};
    auto* block = ::new (static_cast<std::byte*>(address) + sizeof(Arena)) Block{total - sizeof(Arena), 0, nullptr, nullptr, arena, true};
    insert(block);
    return block;
}
Allocation* allocation(const void* pointer) noexcept {
    auto* result = reinterpret_cast<Allocation*>(reinterpret_cast<std::uintptr_t>(pointer) - sizeof(Allocation));
    require(result->Magic == Signature && result->Storage && !result->Storage->Free);
    return result;
}
}
void* Allocate(std::size_t size, std::size_t alignment) noexcept {
    if (!std::has_single_bit(alignment)) return nullptr;
    if (alignment < Alignment) alignment = Alignment;
    if (!size) size = 1;
    constexpr auto Maximum = std::numeric_limits<std::size_t>::max();
    constexpr auto Overhead = sizeof(Block) + sizeof(Allocation) + Alignment - 1;
    if (alignment - 1 > Maximum - Overhead || size > Maximum - Overhead - (alignment - 1)) return nullptr;
    const auto needed = (size + Overhead + alignment - 1) & ~(Alignment - 1);
    const Guard guard;
    Block* block = nullptr;
    for (auto index = bin(needed); index < std::size(bins) && !block; ++index) {
        for (auto* current = bins[index]; current; current = current->NextFree) {
            if (current->Size >= needed) { block = current; break; }
        }
    }
    if (!block) block = create(needed);
    if (!block) return nullptr;
    remove(block);
    if (block->Size - needed >= sizeof(Block) + sizeof(Allocation) + Alignment) {
        auto* remainder = ::new (reinterpret_cast<std::byte*>(block) + needed) Block{block->Size - needed, needed, nullptr, nullptr, block->Owner, true};
        block->Size = needed;
        if (auto* following = next(remainder)) following->PreviousSize = remainder->Size;
        insert(remainder);
    }
    ++block->Owner->Active;
    const auto begin = reinterpret_cast<std::uintptr_t>(block) + sizeof(Block) + sizeof(Allocation);
    const auto address = (begin + alignment - 1) & ~(alignment - 1);
    ::new (reinterpret_cast<void*>(address - sizeof(Allocation))) Allocation{Signature, block, size};
    return reinterpret_cast<void*>(address);
}
void Release(void* pointer) noexcept {
    if (!pointer) return;
    const Guard guard;
    auto* record = allocation(pointer);
    auto* block = record->Storage;
    auto* arena = block->Owner;
    record->Magic = 0;
    require(arena->Active != 0);
    --arena->Active;
    if (auto* following = next(block); following && following->Free) {
        remove(following);
        block->Size += following->Size;
    }
    if (block->PreviousSize) {
        auto* previous = reinterpret_cast<Block*>(reinterpret_cast<std::byte*>(block) - block->PreviousSize);
        if (previous->Free) {
            remove(previous);
            previous->Size += block->Size;
            block = previous;
        }
    }
    if (auto* following = next(block)) following->PreviousSize = block->Size;
    if (!arena->Active) {
        const auto size = arena->Size;
        const auto physical = arena->Physical;
        require(sceKernelMunmap(reinterpret_cast<std::uintptr_t>(arena), size) == 0);
        require(sceKernelReleaseDirectMemory(physical, size) == 0);
    } else insert(block);
}
std::size_t Size(const void* pointer) noexcept { return allocation(pointer)->Size; }
}
