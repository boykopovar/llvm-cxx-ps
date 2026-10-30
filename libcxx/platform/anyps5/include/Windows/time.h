#ifndef ANYLIBCXX_WINDOWS_TIME_H
#define ANYLIBCXX_WINDOWS_TIME_H
#ifdef _USE_32BIT_TIME_T
#error AnyLibcxx requires 64-bit time_t
#endif
#ifdef _TM_DEFINED
#error Calendar time must be declared by AnyLibcxx
#endif
#define _TM_DEFINED
struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long long tm_gmtoff;
    const char* tm_zone;
};
#include_next <time.h>
#endif
