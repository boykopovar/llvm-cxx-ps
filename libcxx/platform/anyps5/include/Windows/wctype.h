#ifndef ANYLIBCXX_WINDOWS_WCTYPE_H
#define ANYLIBCXX_WINDOWS_WCTYPE_H
#include <wchar.h>
typedef unsigned long long wctrans_t;
#ifdef __cplusplus
extern "C" {
#endif
int iswalnum(wint_t value);
int iswalpha(wint_t value);
int iswblank(wint_t value);
int iswcntrl(wint_t value);
int iswdigit(wint_t value);
int iswgraph(wint_t value);
int iswlower(wint_t value);
int iswprint(wint_t value);
int iswpunct(wint_t value);
int iswspace(wint_t value);
int iswupper(wint_t value);
int iswxdigit(wint_t value);
int iswctype(wint_t value, wctype_t descriptor);
wctype_t wctype(const char* property);
wctrans_t wctrans(const char* property);
wint_t towlower(wint_t value);
wint_t towupper(wint_t value);
wint_t towctrans(wint_t value, wctrans_t descriptor);
#ifdef __cplusplus
}
#endif
#endif
