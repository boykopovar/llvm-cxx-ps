#ifndef ANYLIBCXX_WINDOWS_STDLIB_H
#define ANYLIBCXX_WINDOWS_STDLIB_H
#include_next <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
void* aligned_alloc(size_t, size_t);
#ifdef __cplusplus
}
#endif
#endif
