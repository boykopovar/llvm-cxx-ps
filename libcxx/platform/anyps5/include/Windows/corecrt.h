#ifndef ANYLIBCXX_WINDOWS_CORECRT_H
#define ANYLIBCXX_WINDOWS_CORECRT_H
#define _WINT_T
#define _WCTYPE_T_DEFINED
typedef unsigned int wint_t;
typedef unsigned long long wctype_t;
#define mbstate_t AnyLibcxxHostMbState
#include_next <corecrt.h>
#undef mbstate_t
#define _INC_CORECRT_WSTRING
#define _INC_CORECRT_WTIME
#include <AnyLibcxxMbState.h>
typedef AnyLibcxxMbState mbstate_t;
#endif
