#include <stddef.h>
#include <climits>
#include <ctime>
#include <stdexcept>
#include <cerrno>
#include <stdio.h>
#include <wchar.h>

extern "C" {
float __attribute__((sysv_abi)) strtof_nid_postfix(const char* value, char** end);
float strtof(const char* value, char** end) { return strtof_nid_postfix(value, end); }
double __attribute__((sysv_abi)) strtod_nid_postfix(const char* value, char** end);
double strtod(const char* value, char** end) { return strtod_nid_postfix(value, end); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_strtold(const char* value, char** end);
long double strtold(const char* value, char** end) { return AnyLibcxxGuest_strtold(value, end); }
long long __attribute__((sysv_abi)) strtoll_nid_postfix(const char* value, char** end, int base);
long long strtoll(const char* value, char** end, int base) { return strtoll_nid_postfix(value, end, base); }
unsigned long long __attribute__((sysv_abi)) strtoull_nid_postfix(const char* value, char** end, int base);
unsigned long long strtoull(const char* value, char** end, int base) { return strtoull_nid_postfix(value, end, base); }
float __attribute__((sysv_abi)) wcstof_nid_postfix(const wchar_t* value, wchar_t** end);
float wcstof(const wchar_t* value, wchar_t** end) { return wcstof_nid_postfix(value, end); }
double __attribute__((sysv_abi)) wcstod_nid_postfix(const wchar_t* value, wchar_t** end);
double wcstod(const wchar_t* value, wchar_t** end) { return wcstod_nid_postfix(value, end); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_wcstold(const wchar_t* value, wchar_t** end);
long double wcstold(const wchar_t* value, wchar_t** end) { return AnyLibcxxGuest_wcstold(value, end); }
long long __attribute__((sysv_abi)) wcstoll_nid_postfix(const wchar_t* value, wchar_t** end, int base);
long long wcstoll(const wchar_t* value, wchar_t** end, int base) { return wcstoll_nid_postfix(value, end, base); }
unsigned long long __attribute__((sysv_abi)) wcstoull_nid_postfix(const wchar_t* value, wchar_t** end, int base);
unsigned long long wcstoull(const wchar_t* value, wchar_t** end, int base) { return wcstoull_nid_postfix(value, end, base); }
char* __attribute__((sysv_abi)) setlocale_nid_postfix(int category, const char* name);
char* setlocale(int category, const char* name) { return setlocale_nid_postfix(category, name); }
char* __attribute__((sysv_abi)) strerror_nid_postfix(int error);
char* strerror(int error) { return strerror_nid_postfix(error); }
int __attribute__((sysv_abi)) fegetround_nid_postfix();
int fegetround() { return fegetround_nid_postfix(); }
int __attribute__((sysv_abi)) isalnum_nid_postfix(int value);
int isalnum(int value) { return isalnum_nid_postfix(value); }
int __attribute__((sysv_abi)) isalpha_nid_postfix(int value);
int isalpha(int value) { return isalpha_nid_postfix(value); }
int __attribute__((sysv_abi)) isblank_nid_postfix(int value);
int isblank(int value) { return isblank_nid_postfix(value); }
int __attribute__((sysv_abi)) iscntrl_nid_postfix(int value);
int iscntrl(int value) { return iscntrl_nid_postfix(value); }
int __attribute__((sysv_abi)) isdigit_nid_postfix(int value);
int isdigit(int value) { return isdigit_nid_postfix(value); }
int __attribute__((sysv_abi)) isgraph_nid_postfix(int value);
int isgraph(int value) { return isgraph_nid_postfix(value); }
int __attribute__((sysv_abi)) islower_nid_postfix(int value);
int islower(int value) { return islower_nid_postfix(value); }
int __attribute__((sysv_abi)) isprint_nid_postfix(int value);
int isprint(int value) { return isprint_nid_postfix(value); }
int __attribute__((sysv_abi)) ispunct_nid_postfix(int value);
int ispunct(int value) { return ispunct_nid_postfix(value); }
int __attribute__((sysv_abi)) isspace_nid_postfix(int value);
int isspace(int value) { return isspace_nid_postfix(value); }
int __attribute__((sysv_abi)) isupper_nid_postfix(int value);
int isupper(int value) { return isupper_nid_postfix(value); }
int __attribute__((sysv_abi)) isxdigit_nid_postfix(int value);
int isxdigit(int value) { return isxdigit_nid_postfix(value); }
int __attribute__((sysv_abi)) tolower_nid_postfix(int value);
int tolower(int value) { return tolower_nid_postfix(value); }
int __attribute__((sysv_abi)) toupper_nid_postfix(int value);
int toupper(int value) { return toupper_nid_postfix(value); }

int* __attribute__((sysv_abi)) __error_nid_postfix();
int* _errno() { return __error_nid_postfix(); }
double __strtod(const char* value, char** end) { return strtod_nid_postfix(value, end); }
long strtol(const char* value, char** end, int base) {
    const auto result = strtoll_nid_postfix(value, end, base);
    if (result < LONG_MIN) { *_errno() = ERANGE; return LONG_MIN; }
    if (result > LONG_MAX) { *_errno() = ERANGE; return LONG_MAX; }
    return static_cast<long>(result);
}
unsigned long strtoul(const char* value, char** end, int base) {
    const int previous = *_errno();
    *_errno() = 0;
    const auto result = strtoull_nid_postfix(value, end, base);
    if (*_errno() != 0) return static_cast<unsigned long>(result);
    *_errno() = previous;
    const auto* sign = value;
    while (*sign == ' ' || (*sign >= '\t' && *sign <= '\r')) ++sign;
    const auto magnitude = *sign == '-' ? 0ULL - result : result;
    if (magnitude > ULONG_MAX) { *_errno() = ERANGE; return ULONG_MAX; }
    return static_cast<unsigned long>(result);
}
long wcstol(const wchar_t* value, wchar_t** end, int base) {
    const auto result = wcstoll_nid_postfix(value, end, base);
    if (result < LONG_MIN) { *_errno() = ERANGE; return LONG_MIN; }
    if (result > LONG_MAX) { *_errno() = ERANGE; return LONG_MAX; }
    return static_cast<long>(result);
}
unsigned long wcstoul(const wchar_t* value, wchar_t** end, int base) {
    const int previous = *_errno();
    *_errno() = 0;
    const auto result = wcstoull_nid_postfix(value, end, base);
    if (*_errno() != 0) return static_cast<unsigned long>(result);
    *_errno() = previous;
    const auto* sign = value;
    while (*sign == ' ' || (*sign >= '\t' && *sign <= '\r')) ++sign;
    const auto magnitude = *sign == '-' ? 0ULL - result : result;
    if (magnitude > ULONG_MAX) { *_errno() = ERANGE; return ULONG_MAX; }
    return static_cast<unsigned long>(result);
}
[[noreturn]] void __attribute__((sysv_abi)) abort_nid_postfix();
[[noreturn]] void abort() { abort_nid_postfix(); }

__uint128_t __attribute__((sysv_abi)) __udivti3_nid_postfix(__uint128_t left, __uint128_t right);
__uint128_t __attribute__((sysv_abi)) __umodti3_nid_postfix(__uint128_t left, __uint128_t right);
__uint128_t __udivti3(__uint128_t left, __uint128_t right) { return __udivti3_nid_postfix(left, right); }
__uint128_t __umodti3(__uint128_t left, __uint128_t right) { return __umodti3_nid_postfix(left, right); }
struct GuestTm {
    int Seconds;
    int Minutes;
    int Hours;
    int MonthDay;
    int Month;
    int Year;
    int WeekDay;
    int YearDay;
    int DaylightSaving;
    long long GmtOffset;
    const char* Zone;
};
size_t __attribute__((sysv_abi)) strftime_nid_postfix(char* target, size_t capacity, const char* format, const GuestTm* time);
size_t strftime(char* target, size_t capacity, const char* format, const tm* time) {
    if (!time) throw std::invalid_argument("Null time");
    const GuestTm converted{time->tm_sec, time->tm_min, time->tm_hour, time->tm_mday, time->tm_mon, time->tm_year, time->tm_wday, time->tm_yday, time->tm_isdst, 0, nullptr};
    return strftime_nid_postfix(target, capacity, format, &converted);
}
}
