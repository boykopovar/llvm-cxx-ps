#ifndef ANYLIBCXX_RUNTIME_FORMATARGUMENTS_HPP
#define ANYLIBCXX_RUNTIME_FORMATARGUMENTS_HPP

#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

namespace AnyLibcxx {

struct GuestArguments {
    unsigned GpOffset = 48;
    unsigned FpOffset = 176;
    void* Overflow = nullptr;
    void* Registers = nullptr;
};

template<typename TCharacter>
class FormatArguments {
public:
    FormatArguments(const TCharacter* format, va_list arguments, bool scanning) {
        if (!format) throw std::invalid_argument("Null format");
        parse(format, scanning);
        storage.resize(types.size());
        std::size_t offset = 0;
        for (const auto type : types) {
            switch (type) {
                case Type::Signed: append(offset, va_arg(arguments, int)); break;
                case Type::Unsigned: append(offset, va_arg(arguments, unsigned)); break;
                case Type::SignedLong: append(offset, va_arg(arguments, long)); break;
                case Type::UnsignedLong: append(offset, va_arg(arguments, unsigned long)); break;
                case Type::SignedWide: append(offset, va_arg(arguments, long long)); break;
                case Type::UnsignedWide: append(offset, va_arg(arguments, unsigned long long)); break;
                case Type::Pointer: append(offset, va_arg(arguments, void*)); break;
                case Type::Double: append(offset, va_arg(arguments, double)); break;
                case Type::LongDouble: append(offset, va_arg(arguments, long double)); break;
                default: throw std::invalid_argument("Noncontiguous positional arguments");
            }
        }
        guest.Overflow = storage.data();
    }

    const TCharacter* GetFormat() const { return converted.c_str(); }
    GuestArguments* GetArguments() { return &guest; }

private:
    enum class Type { Unset, Signed, Unsigned, SignedLong, UnsignedLong, SignedWide, UnsignedWide, Pointer, Double, LongDouble };
    struct alignas(16) Slot { std::byte Data[16]{}; };
    std::basic_string<TCharacter> converted;
    std::vector<Type> types;
    std::vector<Slot> storage;
    GuestArguments guest;
    std::size_t next = 0;
    bool positional = false;
    bool sequential = false;

    static bool digit(TCharacter value) { return value >= '0' && value <= '9'; }

    std::size_t position(const TCharacter*& cursor) {
        const auto* begin = cursor;
        std::size_t value = 0;
        while (digit(*cursor)) {
            if (value > (std::numeric_limits<std::size_t>::max() - 9) / 10) throw std::invalid_argument("Argument index overflow");
            value = value * 10 + static_cast<unsigned>(*cursor++ - '0');
        }
        if (*cursor != '$') { cursor = begin; return std::numeric_limits<std::size_t>::max(); }
        if (value == 0) throw std::invalid_argument("Zero argument index");
        ++cursor;
        return value - 1;
    }

    void add(Type type, std::size_t index) {
        if (index == std::numeric_limits<std::size_t>::max()) { sequential = true; index = next++; }
        else positional = true;
        if (positional && sequential) throw std::invalid_argument("Mixed argument indexing");
        if (index >= types.max_size()) throw std::length_error("Argument index out of range");
        if (types.size() <= index) types.resize(index + 1, Type::Unset);
        if (types[index] != Type::Unset && types[index] != type) throw std::invalid_argument("Conflicting argument types");
        types[index] = type;
    }

    void parse(const TCharacter* cursor, bool scanning) {
        while (*cursor) {
            if (*cursor != '%') { converted += *cursor++; continue; }
            converted += *cursor++;
            if (*cursor == '%') { converted += *cursor++; continue; }
            const auto* indexBegin = cursor;
            const auto index = position(cursor);
            converted.append(indexBegin, cursor);
            bool suppressed = false;
            if (scanning && *cursor == '*') { suppressed = true; converted += *cursor++; }
            while (*cursor && std::basic_string<TCharacter>{'-', '+', ' ', '#', '0', '\''}.find(*cursor) != std::basic_string<TCharacter>::npos) converted += *cursor++;
            if (!scanning && *cursor == '*') {
                converted += *cursor++;
                const auto* begin = cursor;
                add(Type::Signed, position(cursor));
                converted.append(begin, cursor);
            } else while (digit(*cursor)) converted += *cursor++;
            if (*cursor == '.') {
                converted += *cursor++;
                if (*cursor == '*') {
                    if (scanning) throw std::invalid_argument("Invalid scan precision");
                    converted += *cursor++;
                    const auto* begin = cursor;
                    add(Type::Signed, position(cursor));
                    converted.append(begin, cursor);
                } else while (digit(*cursor)) converted += *cursor++;
            }
            std::basic_string<TCharacter> length;
            if (*cursor && std::basic_string<TCharacter>{'h', 'l', 'j', 'z', 't', 'L'}.find(*cursor) != std::basic_string<TCharacter>::npos) {
                length += *cursor++;
                if ((length[0] == 'h' || length[0] == 'l') && *cursor == length[0]) length += *cursor++;
            }
            if (!*cursor) throw std::invalid_argument("Incomplete format conversion");
            const auto conversion = *cursor++;
            Type type = Type::Unset;
            const bool integer = std::basic_string<TCharacter>{'d', 'i', 'u', 'o', 'x', 'X', 'n'}.find(conversion) != std::basic_string<TCharacter>::npos;
            if (integer) {
                const bool wide = (length.size() == 2 && length[0] == 'l') || length == std::basic_string<TCharacter>{'j'} || length == std::basic_string<TCharacter>{'z'} || length == std::basic_string<TCharacter>{'t'};
                const bool signedValue = conversion == 'd' || conversion == 'i';
                type = conversion == 'n' ? Type::Pointer : wide ? (signedValue ? Type::SignedWide : Type::UnsignedWide) : (signedValue ? Type::Signed : Type::Unsigned);
                if (length == std::basic_string<TCharacter>{'l'}) {
                    if (conversion != 'n') type = signedValue ? Type::SignedLong : Type::UnsignedLong;
                    length.clear();
                }
            } else if (std::basic_string<TCharacter>{'a', 'A', 'e', 'E', 'f', 'F', 'g', 'G'}.find(conversion) != std::basic_string<TCharacter>::npos) type = length == std::basic_string<TCharacter>{'L'} ? Type::LongDouble : Type::Double;
            else if (conversion == 's' || conversion == 'p' || conversion == '[') type = Type::Pointer;
            else if (conversion == 'c') type = Type::Signed;
            else throw std::invalid_argument("Unsupported format conversion");
            converted += length;
            converted += conversion;
            if (conversion == '[') {
                if (!scanning) throw std::invalid_argument("Scanset in output format");
                if (*cursor == '^') converted += *cursor++;
                if (*cursor == ']') converted += *cursor++;
                while (*cursor && *cursor != ']') converted += *cursor++;
                if (*cursor != ']') throw std::invalid_argument("Unterminated scanset");
                converted += *cursor++;
            }
            if (!suppressed) add(scanning ? Type::Pointer : type, index);
        }
    }

    template<typename TValue>
    void append(std::size_t& offset, TValue value) {
        if constexpr (sizeof(TValue) > 8) offset = (offset + 15) & ~std::size_t{15};
        std::memcpy(reinterpret_cast<std::byte*>(storage.data()) + offset, &value, sizeof(value));
        offset += sizeof(TValue) > 8 ? 16 : 8;
    }
};

}

#endif
