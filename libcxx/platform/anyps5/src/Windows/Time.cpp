#define __CRT__NO_INLINE 1
#include <time.h>
#include <limits.h>
#include <stdexcept>

static_assert(sizeof(tm) == 56);

extern "C" {
long long __attribute__((sysv_abi)) time_nid_postfix(long long* value);
long long __attribute__((sysv_abi)) clock_nid_postfix();
tm* __attribute__((sysv_abi)) gmtime_nid_postfix(const long long* value);
tm* __attribute__((sysv_abi)) localtime_nid_postfix(const long long* value);
long long __attribute__((sysv_abi)) mktime_nid_postfix(tm* value);
char* __attribute__((sysv_abi)) asctime_nid_postfix(const tm* value);
char* __attribute__((sysv_abi)) ctime_nid_postfix(const long long* value);
size_t __attribute__((sysv_abi)) wcsftime_nid_postfix(wchar_t* target, size_t capacity, const wchar_t* format, const tm* value);
__time64_t _time64(__time64_t* value) { return time_nid_postfix(value); }
clock_t clock() {
    const auto value = clock_nid_postfix();
    if (value < 0 || value / (1000000 / CLOCKS_PER_SEC) > LONG_MAX) return static_cast<clock_t>(-1);
    return static_cast<clock_t>(value / (1000000 / CLOCKS_PER_SEC));
}
double __attribute__((sysv_abi)) difftime_nid_postfix(long long left, long long right);
double _difftime64(__time64_t left, __time64_t right) { return difftime_nid_postfix(left, right); }
tm* _gmtime64(const __time64_t* value) { return gmtime_nid_postfix(value); }
tm* _localtime64(const __time64_t* value) { return localtime_nid_postfix(value); }
__time64_t _mktime64(tm* value) { return mktime_nid_postfix(value); }
char* asctime(const tm* value) { return asctime_nid_postfix(value); }
char* _ctime64(const __time64_t* value) { return ctime_nid_postfix(value); }
size_t wcsftime(wchar_t* target, size_t capacity, const wchar_t* format, const tm* value) { return wcsftime_nid_postfix(target, capacity, format, value); }
}
