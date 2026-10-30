#ifndef ANYLIBCXX_WINDOWS_STDLIB_H
#define ANYLIBCXX_WINDOWS_STDLIB_H
#include_next <stdlib.h>
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
