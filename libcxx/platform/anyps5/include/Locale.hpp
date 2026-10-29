#ifndef ANYLIBCXX_LOCALE_HPP
#define ANYLIBCXX_LOCALE_HPP

#include <__config>
#include <cerrno>
#include <climits>
#include <clocale>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <utility>

#define _LIBCPP_COLLATE_MASK 1
#define _LIBCPP_CTYPE_MASK 2
#define _LIBCPP_MONETARY_MASK 4
#define _LIBCPP_NUMERIC_MASK 8
#define _LIBCPP_TIME_MASK 16
#define _LIBCPP_MESSAGES_MASK 32
#define _LIBCPP_ALL_MASK 63
#define _LIBCPP_LC_ALL LC_ALL

extern "C" int AnyLibcxxScan(const char* source, const char* format, ...) __asm__("sscanf");

_LIBCPP_BEGIN_NAMESPACE_STD
namespace __locale {
struct LocaleToken {};
inline LocaleToken ClassicLocale;
using __locale_t = LocaleToken*;
struct LocaleConventions {
    char* decimal_point;
    char* thousands_sep;
    char* grouping;
    char* int_curr_symbol;
    char* currency_symbol;
    char* mon_decimal_point;
    char* mon_thousands_sep;
    char* mon_grouping;
    char* positive_sign;
    char* negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    char int_p_cs_precedes;
    char int_p_sep_by_space;
    char int_n_cs_precedes;
    char int_n_sep_by_space;
    char int_p_sign_posn;
    char int_n_sign_posn;
};
using __lconv_t = LocaleConventions;

inline __locale_t __newlocale(int mask, const char* name, __locale_t base) {
    if (name == nullptr || (mask & ~_LIBCPP_ALL_MASK) != 0 || (base != nullptr && base != &ClassicLocale)) return nullptr;
    if (name[0] != 0 && std::strcmp(name, "C") != 0) return nullptr;
    return &ClassicLocale;
}
inline void __freelocale(__locale_t) {}
inline char* __setlocale(int category, const char* name) { return std::setlocale(category, name); }
inline __lconv_t* __localeconv(__locale_t&) {
    static char empty[] = "";
    static char decimal[] = ".";
    static __lconv_t value = [] {
        __lconv_t result{};
        result.decimal_point = decimal;
        result.thousands_sep = empty;
        result.grouping = empty;
        result.int_curr_symbol = empty;
        result.currency_symbol = empty;
        result.mon_decimal_point = empty;
        result.mon_thousands_sep = empty;
        result.mon_grouping = empty;
        result.positive_sign = empty;
        result.negative_sign = empty;
        result.int_frac_digits = result.frac_digits = CHAR_MAX;
        result.p_cs_precedes = result.p_sep_by_space = result.n_cs_precedes = result.n_sep_by_space = CHAR_MAX;
        result.p_sign_posn = result.n_sign_posn = CHAR_MAX;
        result.int_p_cs_precedes = result.int_p_sep_by_space = result.int_n_cs_precedes = result.int_n_sep_by_space = CHAR_MAX;
        result.int_p_sign_posn = result.int_n_sign_posn = CHAR_MAX;
        return result;
    }();
    return &value;
}
inline float __strtof(const char* value, char** end, __locale_t) { return std::strtof(value, end); }
inline double __strtod(const char* value, char** end, __locale_t) { return std::strtod(value, end); }
inline long double __strtold(const char* value, char** end, __locale_t) { return std::strtold(value, end); }
inline long long __strtoll(const char* value, char** end, int base, __locale_t) { return std::strtoll(value, end, base); }
inline unsigned long long __strtoull(const char* value, char** end, int base, __locale_t) { return std::strtoull(value, end, base); }
inline int __islower(int value, __locale_t) { return value >= 0 && value < 128 && (value >= 'a' && value <= 'z'); }
inline int __isupper(int value, __locale_t) { return value >= 0 && value < 128 && (value >= 'A' && value <= 'Z'); }
inline int __isdigit(int value, __locale_t) { return value >= 0 && value < 128 && (value >= '0' && value <= '9'); }
inline int __isxdigit(int value, __locale_t) { return value >= 0 && value < 128 && (__isdigit(value, nullptr) || (value >= 'a' && value <= 'f') || (value >= 'A' && value <= 'F')); }
inline int __isspace(int value, __locale_t) { return value >= 0 && value < 128 && (value == ' ' || (value >= '\t' && value <= '\r')); }
inline int __isprint(int value, __locale_t) { return value >= 0 && value < 128 && (value >= 32 && value <= 126); }
inline int __iscntrl(int value, __locale_t) { return value >= 0 && value < 128 && (value < 32 || value == 127); }
inline int __isalpha(int value, __locale_t) { return value >= 0 && value < 128 && (__islower(value, nullptr) || __isupper(value, nullptr)); }
inline int __isblank(int value, __locale_t) { return value >= 0 && value < 128 && (value == ' ' || value == '\t'); }
inline int __ispunct(int value, __locale_t) { return value >= 0 && value < 128 && (__isprint(value, nullptr) && !__isalpha(value, nullptr) && !__isdigit(value, nullptr) && value != ' '); }
inline int __iswlower(wint_t value, __locale_t locale) { return value < 128 && __islower(static_cast<int>(value), locale); }
inline int __iswupper(wint_t value, __locale_t locale) { return value < 128 && __isupper(static_cast<int>(value), locale); }
inline int __iswdigit(wint_t value, __locale_t locale) { return value < 128 && __isdigit(static_cast<int>(value), locale); }
inline int __iswxdigit(wint_t value, __locale_t locale) { return value < 128 && __isxdigit(static_cast<int>(value), locale); }
inline int __iswspace(wint_t value, __locale_t locale) { return value < 128 && __isspace(static_cast<int>(value), locale); }
inline int __iswprint(wint_t value, __locale_t locale) { return value < 128 && __isprint(static_cast<int>(value), locale); }
inline int __iswcntrl(wint_t value, __locale_t locale) { return value < 128 && __iscntrl(static_cast<int>(value), locale); }
inline int __iswalpha(wint_t value, __locale_t locale) { return value < 128 && __isalpha(static_cast<int>(value), locale); }
inline int __iswblank(wint_t value, __locale_t locale) { return value < 128 && __isblank(static_cast<int>(value), locale); }
inline int __iswpunct(wint_t value, __locale_t locale) { return value < 128 && __ispunct(static_cast<int>(value), locale); }
inline int __toupper(int value, __locale_t locale) { return __islower(value, locale) ? value - 'a' + 'A' : value; }
inline int __tolower(int value, __locale_t locale) { return __isupper(value, locale) ? value - 'A' + 'a' : value; }
inline wint_t __towupper(wint_t value, __locale_t locale) { return __iswlower(value, locale) ? value - L'a' + L'A' : value; }
inline wint_t __towlower(wint_t value, __locale_t locale) { return __iswupper(value, locale) ? value - L'A' + L'a' : value; }
inline int __strcoll(const char* left, const char* right, __locale_t) { return std::strcmp(left, right); }
inline int __wcscoll(const wchar_t* left, const wchar_t* right, __locale_t) { return std::wcscmp(left, right); }
inline size_t __strxfrm(char* target, const char* source, size_t size, __locale_t) {
    const auto length = std::strlen(source);
    if (length < size) std::memcpy(target, source, length + 1);
    return length;
}
inline size_t __wcsxfrm(wchar_t* target, const wchar_t* source, size_t size, __locale_t) {
    const auto length = std::wcslen(source);
    if (length < size) std::memcpy(target, source, (length + 1) * sizeof(wchar_t));
    return length;
}
inline size_t __strftime(char* target, size_t size, const char* format, const tm* time, __locale_t) { return std::strftime(target, size, format, time); }
inline size_t __mb_len_max(__locale_t) { return 1; }
inline wint_t __btowc(int value, __locale_t) { return value >= 0 && value < 128 ? static_cast<wint_t>(value) : WEOF; }
inline int __wctob(wint_t value, __locale_t) { return value < 128 ? static_cast<int>(value) : EOF; }
inline size_t __mbrtowc(wchar_t* target, const char* source, size_t size, mbstate_t* state, __locale_t) {
    if (state) std::memset(state, 0, sizeof(*state));
    if (!source) return 0;
    if (!size) return static_cast<size_t>(-2);
    const auto value = static_cast<unsigned char>(*source);
    if (value >= 128) { errno = EILSEQ; return static_cast<size_t>(-1); }
    if (target) *target = value;
    return value != 0;
}
inline size_t __wcrtomb(char* target, wchar_t value, mbstate_t* state, __locale_t) {
    if (state) std::memset(state, 0, sizeof(*state));
    if (!target) return 1;
    if (static_cast<unsigned int>(value) >= 128) { errno = EILSEQ; return static_cast<size_t>(-1); }
    *target = static_cast<char>(value);
    return 1;
}
inline size_t __mbsnrtowcs(wchar_t* target, const char** source, size_t input, size_t capacity, mbstate_t* state, __locale_t locale) {
    const auto* current = *source;
    size_t count = 0;
    while (input != 0 && (!target || count < capacity)) {
        wchar_t value;
        const auto result = __mbrtowc(&value, current, input, state, locale);
        if (result == static_cast<size_t>(-1)) { if (target) *source = current; return result; }
        if (target) target[count] = value;
        if (value == 0) { if (target) *source = nullptr; return count; }
        ++count; ++current; --input;
    }
    if (target) *source = current;
    return count;
}
inline size_t __wcsnrtombs(char* target, const wchar_t** source, size_t input, size_t capacity, mbstate_t* state, __locale_t locale) {
    const auto* current = *source;
    size_t count = 0;
    while (input != 0 && (!target || count < capacity)) {
        char value;
        const auto result = __wcrtomb(&value, *current, state, locale);
        if (result == static_cast<size_t>(-1)) { if (target) *source = current; return result; }
        if (target) target[count] = value;
        if (value == 0) { if (target) *source = nullptr; return count; }
        ++count; ++current; --input;
    }
    if (target) *source = current;
    return count;
}
inline int __mbtowc(wchar_t* target, const char* source, size_t size, __locale_t locale) {
    const auto result = __mbrtowc(target, source, size, nullptr, locale);
    return result > 1 ? -1 : static_cast<int>(result);
}
inline size_t __mbrlen(const char* source, size_t size, mbstate_t* state, __locale_t locale) { return __mbrtowc(nullptr, source, size, state, locale); }
inline size_t __mbsrtowcs(wchar_t* target, const char** source, size_t size, mbstate_t* state, __locale_t locale) { return __mbsnrtowcs(target, source, static_cast<size_t>(-1), size, state, locale); }

template<typename... TArguments>
int __snprintf(char* target, size_t size, __locale_t, const char* format, TArguments&&... arguments) { return std::snprintf(target, size, format, std::forward<TArguments>(arguments)...); }
template<typename... TArguments>
int __asprintf(char** target, __locale_t locale, const char* format, TArguments&&... arguments) {
    const auto size = __snprintf(nullptr, 0, locale, format, arguments...);
    if (size < 0) return -1;
    *target = static_cast<char*>(std::malloc(static_cast<size_t>(size) + 1));
    if (!*target) return -1;
    const auto result = __snprintf(*target, static_cast<size_t>(size) + 1, locale, format, std::forward<TArguments>(arguments)...);
    if (result < 0) { std::free(*target); *target = nullptr; }
    return result;
}
template<typename... TArguments>
int __sscanf(const char* source, __locale_t, const char* format, TArguments&&... arguments) { return ::AnyLibcxxScan(source, format, std::forward<TArguments>(arguments)...); }
}
_LIBCPP_END_NAMESPACE_STD

#endif
