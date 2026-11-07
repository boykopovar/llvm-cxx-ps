#ifndef ANYLIBCXX_WINDOWS_STDLIB_H
#define ANYLIBCXX_WINDOWS_STDLIB_H
#ifndef __CRT__NO_INLINE
#define __CRT__NO_INLINE 1
#define ANYLIBCXX_RESTORE_CRT_INLINE
#endif
#include_next <stdlib.h>
#ifdef ANYLIBCXX_RESTORE_CRT_INLINE
#undef __CRT__NO_INLINE
#undef ANYLIBCXX_RESTORE_CRT_INLINE
#endif
#include <AnyLibcxxMbCurMax.h>
#ifdef __cplusplus
extern "C" {
#endif
void* aligned_alloc(size_t, size_t);
int at_quick_exit(void (*callback)(void));
#ifdef __cplusplus
[[noreturn]] void quick_exit(int status);
#else
_Noreturn void quick_exit(int status);
#endif
#ifdef __cplusplus
}
#endif
#endif
