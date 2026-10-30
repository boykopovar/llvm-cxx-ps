#ifndef ANYLIBCXX_UCHAR_H
#define ANYLIBCXX_UCHAR_H
#include <stddef.h>
#include <wchar.h>
#ifndef __cplusplus
typedef unsigned short char16_t;
typedef unsigned int char32_t;
#endif
#ifdef _WIN32
#define ANYLIBCXX_UCHAR_NAME(name)
#else
#define ANYLIBCXX_UCHAR_NAME(name) __asm__("AnyLibcxx" #name)
#endif
#ifdef __cplusplus
extern "C" {
#endif
size_t mbrtoc16(char16_t* target, const char* source, size_t count, mbstate_t* state) ANYLIBCXX_UCHAR_NAME(mbrtoc16);
size_t c16rtomb(char* target, char16_t value, mbstate_t* state) ANYLIBCXX_UCHAR_NAME(c16rtomb);
size_t mbrtoc32(char32_t* target, const char* source, size_t count, mbstate_t* state) ANYLIBCXX_UCHAR_NAME(mbrtoc32);
size_t c32rtomb(char* target, char32_t value, mbstate_t* state) ANYLIBCXX_UCHAR_NAME(c32rtomb);
#ifdef __cplusplus
}
#endif
#undef ANYLIBCXX_UCHAR_NAME
#endif
