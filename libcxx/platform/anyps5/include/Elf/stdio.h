#ifndef ANYLIBCXX_ELF_STDIO_H
#define ANYLIBCXX_ELF_STDIO_H
#include <features.h>
#ifdef __USE_EXTERN_INLINES
#define ANYLIBCXX_RESTORE_STDIO_INLINES
#undef __USE_EXTERN_INLINES
#endif
#include_next <stdio.h>
#ifdef ANYLIBCXX_RESTORE_STDIO_INLINES
#define __USE_EXTERN_INLINES 1
#undef ANYLIBCXX_RESTORE_STDIO_INLINES
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern FILE* __stdinp_nid_postfix;
extern FILE* __stdoutp_nid_postfix;
extern FILE* __stderrp_nid_postfix;
#ifdef __cplusplus
}
#endif
#undef stdin
#undef stdout
#undef stderr
#define stdin __stdinp_nid_postfix
#define stdout __stdoutp_nid_postfix
#define stderr __stderrp_nid_postfix
#endif
