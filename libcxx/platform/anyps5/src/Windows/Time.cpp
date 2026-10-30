#define __CRT__NO_INLINE 1
#include "Runtime/Time.hpp"
#include <time.h>
#include <limits.h>
#include <stdexcept>

namespace {
GuestTm toGuest(const tm& value) {
    return {value.tm_sec, value.tm_min, value.tm_hour, value.tm_mday, value.tm_mon, value.tm_year, value.tm_wday, value.tm_yday, value.tm_isdst, 0, nullptr};
}
void fromGuest(tm& target, const GuestTm& value) {
    target = {value.Seconds, value.Minutes, value.Hours, value.MonthDay, value.Month, value.Year, value.WeekDay, value.YearDay, value.DaylightSaving};
}
tm convertedTime;
}

extern "C" {
long long __attribute__((sysv_abi)) time_nid_postfix(long long* value);
long long __attribute__((sysv_abi)) clock_nid_postfix();
GuestTm* __attribute__((sysv_abi)) gmtime_nid_postfix(const long long* value);
GuestTm* __attribute__((sysv_abi)) localtime_nid_postfix(const long long* value);
long long __attribute__((sysv_abi)) mktime_nid_postfix(GuestTm* value);
char* __attribute__((sysv_abi)) asctime_nid_postfix(const GuestTm* value);
char* __attribute__((sysv_abi)) ctime_nid_postfix(const long long* value);
size_t __attribute__((sysv_abi)) wcsftime_nid_postfix(wchar_t* target, size_t capacity, const wchar_t* format, const GuestTm* value);
__time64_t _time64(__time64_t* value) { return time_nid_postfix(value); }
clock_t clock() {
    const auto value = clock_nid_postfix();
    if (value < 0 || value / (1000000 / CLOCKS_PER_SEC) > LONG_MAX) return static_cast<clock_t>(-1);
    return static_cast<clock_t>(value / (1000000 / CLOCKS_PER_SEC));
}
double _difftime64(__time64_t left, __time64_t right) { return static_cast<double>(left) - static_cast<double>(right); }
tm* _gmtime64(const __time64_t* value) {
    const auto* result = gmtime_nid_postfix(value);
    if (!result) return nullptr;
    fromGuest(convertedTime, *result);
    return &convertedTime;
}
tm* _localtime64(const __time64_t* value) {
    const auto* result = localtime_nid_postfix(value);
    if (!result) return nullptr;
    fromGuest(convertedTime, *result);
    return &convertedTime;
}
__time64_t _mktime64(tm* value) {
    if (!value) throw std::invalid_argument("Null calendar time");
    auto converted = toGuest(*value);
    const auto result = mktime_nid_postfix(&converted);
    fromGuest(*value, converted);
    return result;
}
char* asctime(const tm* value) {
    if (!value) throw std::invalid_argument("Null calendar time");
    const auto converted = toGuest(*value);
    return asctime_nid_postfix(&converted);
}
char* _ctime64(const __time64_t* value) { return ctime_nid_postfix(value); }
size_t wcsftime(wchar_t* target, size_t capacity, const wchar_t* format, const tm* value) {
    if (!value) throw std::invalid_argument("Null calendar time");
    const auto converted = toGuest(*value);
    return wcsftime_nid_postfix(target, capacity, format, &converted);
}
}
