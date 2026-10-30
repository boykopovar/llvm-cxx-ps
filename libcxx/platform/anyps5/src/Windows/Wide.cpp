#include <wchar.h>
#include <wctype.h>
#include <uchar.h>
#include <stdexcept>
#include <limits>

extern "C" {
int __attribute__((sysv_abi)) iswalnum_nid_postfix(unsigned int value);
int iswalnum(wint_t value) { return iswalnum_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswalpha_nid_postfix(unsigned int value);
int iswalpha(wint_t value) { return iswalpha_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswblank_nid_postfix(unsigned int value);
int iswblank(wint_t value) { return iswblank_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswcntrl_nid_postfix(unsigned int value);
int iswcntrl(wint_t value) { return iswcntrl_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswdigit_nid_postfix(unsigned int value);
int iswdigit(wint_t value) { return iswdigit_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswgraph_nid_postfix(unsigned int value);
int iswgraph(wint_t value) { return iswgraph_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswlower_nid_postfix(unsigned int value);
int iswlower(wint_t value) { return iswlower_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswprint_nid_postfix(unsigned int value);
int iswprint(wint_t value) { return iswprint_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswpunct_nid_postfix(unsigned int value);
int iswpunct(wint_t value) { return iswpunct_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswspace_nid_postfix(unsigned int value);
int iswspace(wint_t value) { return iswspace_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswupper_nid_postfix(unsigned int value);
int iswupper(wint_t value) { return iswupper_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswxdigit_nid_postfix(unsigned int value);
int iswxdigit(wint_t value) { return iswxdigit_nid_postfix(value == WEOF ? 0xffffffffu : value); }
unsigned int __attribute__((sysv_abi)) towlower_nid_postfix(unsigned int value);
wint_t towlower(wint_t value) { return towlower_nid_postfix(value == WEOF ? 0xffffffffu : value); }
unsigned int __attribute__((sysv_abi)) towupper_nid_postfix(unsigned int value);
wint_t towupper(wint_t value) { return towupper_nid_postfix(value == WEOF ? 0xffffffffu : value); }
unsigned int __attribute__((sysv_abi)) btowc_nid_postfix(int value);
wint_t btowc(int value) { return btowc_nid_postfix(value); }
int __attribute__((sysv_abi)) wctob_nid_postfix(unsigned int value);
int wctob(wint_t value) { return wctob_nid_postfix(value == WEOF ? 0xffffffffu : value); }
int __attribute__((sysv_abi)) iswctype_nid_postfix(unsigned int value, unsigned long long descriptor);
int iswctype(wint_t value, wctype_t descriptor) { return iswctype_nid_postfix(value == WEOF ? 0xffffffffu : value, descriptor); }
unsigned int __attribute__((sysv_abi)) towctrans_nid_postfix(unsigned int value, unsigned long long descriptor);
wint_t towctrans(wint_t value, wctrans_t descriptor) { return towctrans_nid_postfix(value == WEOF ? 0xffffffffu : value, descriptor); }
unsigned long long __attribute__((sysv_abi)) wctype_nid_postfix(const char* property);
wctype_t wctype(const char* property) { const auto value = wctype_nid_postfix(property); if (value > std::numeric_limits<wctype_t>::max()) throw std::range_error("Wide character descriptor overflow"); return static_cast<wctype_t>(value); }
unsigned long long __attribute__((sysv_abi)) wctrans_nid_postfix(const char* property);
wctrans_t wctrans(const char* property) { const auto value = wctrans_nid_postfix(property); if (value > std::numeric_limits<wctrans_t>::max()) throw std::range_error("Wide character descriptor overflow"); return static_cast<wctrans_t>(value); }
int __attribute__((sysv_abi)) mbsinit_nid_postfix(const mbstate_t* state);
int mbsinit(const mbstate_t* state) { return mbsinit_nid_postfix(state); }
size_t __attribute__((sysv_abi)) mbrlen_nid_postfix(const char* source, size_t count, mbstate_t* state);
size_t mbrlen(const char* source, size_t count, mbstate_t* state) { return mbrlen_nid_postfix(source, count, state); }
size_t __attribute__((sysv_abi)) mbrtowc_nid_postfix(wchar_t* target, const char* source, size_t count, mbstate_t* state);
size_t mbrtowc(wchar_t* target, const char* source, size_t count, mbstate_t* state) { return mbrtowc_nid_postfix(target, source, count, state); }
size_t __attribute__((sysv_abi)) wcrtomb_nid_postfix(char* target, wchar_t value, mbstate_t* state);
size_t wcrtomb(char* target, wchar_t value, mbstate_t* state) { return wcrtomb_nid_postfix(target, value, state); }
size_t __attribute__((sysv_abi)) mbsrtowcs_nid_postfix(wchar_t* target, const char** source, size_t count, mbstate_t* state);
size_t mbsrtowcs(wchar_t* target, const char** source, size_t count, mbstate_t* state) { return mbsrtowcs_nid_postfix(target, source, count, state); }
size_t __attribute__((sysv_abi)) wcsrtombs_nid_postfix(char* target, const wchar_t** source, size_t count, mbstate_t* state);
size_t wcsrtombs(char* target, const wchar_t** source, size_t count, mbstate_t* state) { return wcsrtombs_nid_postfix(target, source, count, state); }
size_t __attribute__((sysv_abi)) mbrtoc16_nid_postfix(char16_t* target, const char* source, size_t count, mbstate_t* state);
size_t mbrtoc16(char16_t* target, const char* source, size_t count, mbstate_t* state) { return mbrtoc16_nid_postfix(target, source, count, state); }
size_t __attribute__((sysv_abi)) c16rtomb_nid_postfix(char* target, char16_t value, mbstate_t* state);
size_t c16rtomb(char* target, char16_t value, mbstate_t* state) { return c16rtomb_nid_postfix(target, value, state); }
size_t __attribute__((sysv_abi)) mbrtoc32_nid_postfix(char32_t* target, const char* source, size_t count, mbstate_t* state);
size_t mbrtoc32(char32_t* target, const char* source, size_t count, mbstate_t* state) { return mbrtoc32_nid_postfix(target, source, count, state); }
size_t __attribute__((sysv_abi)) c32rtomb_nid_postfix(char* target, char32_t value, mbstate_t* state);
size_t c32rtomb(char* target, char32_t value, mbstate_t* state) { return c32rtomb_nid_postfix(target, value, state); }
int __attribute__((sysv_abi)) mbtowc_nid_postfix(wchar_t* target, const char* source, size_t count);
int mbtowc(wchar_t* target, const char* source, size_t count) { return mbtowc_nid_postfix(target, source, count); }
int __attribute__((sysv_abi)) mblen_nid_postfix(const char* source, size_t count);
int mblen(const char* source, size_t count) { return mblen_nid_postfix(source, count); }
int __attribute__((sysv_abi)) wctomb_nid_postfix(char* target, wchar_t value);
int wctomb(char* target, wchar_t value) { return wctomb_nid_postfix(target, value); }
size_t __attribute__((sysv_abi)) mbstowcs_nid_postfix(wchar_t* target, const char* source, size_t count);
size_t mbstowcs(wchar_t* target, const char* source, size_t count) { return mbstowcs_nid_postfix(target, source, count); }
size_t __attribute__((sysv_abi)) wcstombs_nid_postfix(char* target, const wchar_t* source, size_t count);
size_t wcstombs(char* target, const wchar_t* source, size_t count) { return wcstombs_nid_postfix(target, source, count); }
wint_t getwchar() { return fgetwc(stdin); }
wint_t putwchar(wchar_t value) { return fputwc(value, stdout); }
}

static_assert(sizeof(mbstate_t) == 16);
