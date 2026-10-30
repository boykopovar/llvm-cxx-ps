#include <array>
#include <bit>
#include <cmath>
#include <cfenv>
#include <cerrno>
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <limits>

extern "C" {
long double nextafterl(long double value, long double direction) {
    static_assert(sizeof(long double) == 16 && std::numeric_limits<long double>::digits == 64);
    if (std::isnan(value) || std::isnan(direction)) return value + direction;
    if (value == direction) return direction;
    std::array<std::uint64_t, 2> bits{};
    std::uint16_t signExponent;
    std::memcpy(&bits[0], &value, sizeof(bits[0]));
    std::memcpy(&signExponent, reinterpret_cast<const std::byte*>(&value) + sizeof(bits[0]), sizeof(signExponent));
    bits[1] = signExponent;
    auto exponent = static_cast<unsigned>(bits[1] & 0x7fff);
    const auto negative = (bits[1] & 0x8000) != 0;
    if (value == 0) {
        bits = {1, std::signbit(direction) ? 0x8000u : 0u};
    } else if ((direction > value) != negative) {
        if (++bits[0] == 0) {
            bits[0] = 0x8000000000000000ull;
            ++exponent;
        } else if (exponent == 0 && bits[0] == 0x8000000000000000ull) exponent = 1;
        bits[1] = (negative ? 0x8000u : 0u) | exponent;
    } else {
        if (bits[0] == 0x8000000000000000ull && exponent > 1) {
            --exponent;
            bits[0] = 0xffffffffffffffffull;
        } else {
            --bits[0];
            if (exponent == 1 && bits[0] < 0x8000000000000000ull) exponent = 0;
        }
        bits[1] = (negative ? 0x8000u : 0u) | exponent;
    }
    const auto result = std::bit_cast<long double>(bits);
    if ((bits[1] & 0x7fff) == 0) { errno = ERANGE; std::feraiseexcept(FE_UNDERFLOW | FE_INEXACT); }
    else if ((bits[1] & 0x7fff) == 0x7fff) { errno = ERANGE; std::feraiseexcept(FE_OVERFLOW | FE_INEXACT); }
    return result;
}
long double nexttowardl(long double value, long double direction) { return nextafterl(value, direction); }
float nexttowardf(float value, long double direction) {
    if (std::isnan(value) || std::isnan(direction)) return value + static_cast<float>(direction);
    if (value == direction) return static_cast<float>(direction);
    return std::nextafter(value, direction > value ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity());
}
double nexttoward(double value, long double direction) {
    if (std::isnan(value) || std::isnan(direction)) return value + static_cast<double>(direction);
    if (value == direction) return static_cast<double>(direction);
    return std::nextafter(value, direction > value ? std::numeric_limits<double>::infinity() : -std::numeric_limits<double>::infinity());
}
}
