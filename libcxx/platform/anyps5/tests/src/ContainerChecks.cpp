#include "ContainerChecks.hpp"

#include <algorithm>
#include <array>
#include <cstdint>
#include <exception>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>

namespace {

void require(bool condition, const char* message) {
    if (!condition) throw std::runtime_error(message);
}

template<typename TException, typename TAction>
void expectException(TAction action) {
    bool caught = false;
    try {
        action();
    } catch (const TException& error) {
        require(error.what() != nullptr && error.what()[0] != 0, "Empty exception message");
        caught = true;
    }
    require(caught, "Expected exception was not thrown");
}

struct CollisionHash {
    std::size_t operator()(unsigned int value) const noexcept { return value % 7; }
};

struct alignas(64) AlignedValue { std::array<std::uint64_t, 8> Data{}; };

struct UnwindObserver {
    bool& Destroyed;
    int& Count;
    ~UnwindObserver() {
        Count = std::uncaught_exceptions();
        Destroyed = true;
    }
};

}

void RunContainerChecks(unsigned int seed) {
    require(std::uncaught_exceptions() == 0, "Unexpected initial exception count");
    {
        std::vector<unsigned int> values;
        for (unsigned int index = 0; index < 4096; ++index) values.push_back(seed ^ index);
        auto copied = values;
        auto moved = std::move(copied);
        require(moved == values, "Vector copy or move failed");
        values.erase(values.begin(), values.begin() + 2048);
        require(values.size() == 2048 && std::equal(values.begin(), values.end(), moved.begin() + 2048), "Vector erase failed");
        values.resize(4096, seed);
        require(values.back() == seed, "Vector resize failed");
        std::ranges::sort(values);
        require(std::ranges::is_sorted(values), "Vector sorting failed");
        expectException<std::out_of_range>([&] { static_cast<void>(values.at(values.size())); });
        expectException<std::length_error>([&] { values.reserve(values.max_size() + 1); });
    }
    {
        using Value = std::variant<std::uint64_t, std::string>;
        std::unordered_map<unsigned int, Value, CollisionHash> entries;
        for (unsigned int index = 0; index < 1024; ++index) entries.emplace(index, static_cast<std::uint64_t>(seed ^ index));
        entries.reserve(4096);
        for (unsigned int index = 0; index < 1024; ++index) {
            const auto found = entries.find(index);
            require(found != entries.end(), "Map lookup failed after rehash");
            require(std::get<std::uint64_t>(found->second) == (seed ^ index), "Map value changed after rehash");
            found->second = std::string(80, static_cast<char>('a' + index % 26));
            require(std::get<std::string>(found->second).size() == 80, "Variant string allocation failed");
        }
        auto copied = entries;
        auto moved = std::move(copied);
        require(moved == entries, "Map copy or move failed");
        for (unsigned int index = 0; index < 1024; index += 2) require(entries.erase(index) == 1, "Map erase failed");
        require(entries.size() == 512 && moved.size() == 1024, "Map ownership failed");
        for (unsigned int index = 1; index < 1024; index += 2) require(entries.contains(index), "Map collision chain damaged");
        auto node = entries.extract(1);
        require(!node.empty(), "Map extract failed");
        node.key() = 2048;
        require(entries.insert(std::move(node)).inserted && entries.contains(2048), "Map node insertion failed");
        expectException<std::out_of_range>([&] { static_cast<void>(entries.at(4096)); });
        expectException<std::bad_variant_access>([&] { static_cast<void>(std::get<std::uint64_t>(entries.at(3))); });
        const auto length = std::visit([](const auto& value) -> std::size_t {
            using TValue = std::remove_cvref_t<decltype(value)>;
            if constexpr (std::is_same_v<TValue, std::string>) return value.size();
            else return static_cast<std::size_t>(value);
        }, entries.at(3));
        require(length == 80, "Variant visitation failed");
    }
    {
        const std::optional<int> empty;
        expectException<std::bad_optional_access>([&] { static_cast<void>(empty.value()); });
        auto aligned = std::make_unique<AlignedValue>();
        require(reinterpret_cast<std::uintptr_t>(aligned.get()) % alignof(AlignedValue) == 0, "Aligned allocation failed");
        aligned->Data.fill(seed);
        require(aligned->Data.back() == seed, "Aligned storage failed");
    }
    {
        bool destroyed = false;
        int count = 0;
        std::exception_ptr saved;
        try {
            UnwindObserver observer{destroyed, count};
            throw std::runtime_error(std::string(128, 'x'));
        } catch (const std::runtime_error& error) {
            require(std::string(error.what()) == std::string(128, 'x'), "Exception message corrupted");
            saved = std::current_exception();
        }
        require(destroyed && count == 1 && std::uncaught_exceptions() == 0, "Exception unwinding failed");
        require(saved != nullptr, "Exception capture failed");
        auto copy = saved;
        saved = nullptr;
        expectException<std::runtime_error>([&] { std::rethrow_exception(copy); });
        auto created = std::make_exception_ptr(std::invalid_argument("created exception"));
        expectException<std::invalid_argument>([&] { std::rethrow_exception(created); });
    }
    require(std::uncaught_exceptions() == 0, "Exception state leaked");
}
