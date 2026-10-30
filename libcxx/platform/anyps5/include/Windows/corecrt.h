#ifndef ANYLIBCXX_WINDOWS_CORECRT_H
#define ANYLIBCXX_WINDOWS_CORECRT_H
#define _WINT_T
#define _WCTYPE_T_DEFINED
typedef unsigned int wint_t;
typedef unsigned long long wctype_t;
#include_next <corecrt.h>
#endif
