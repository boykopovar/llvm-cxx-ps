#ifndef ANYLIBCXX_ELF_SETJMP_H
#define ANYLIBCXX_ELF_SETJMP_H
typedef struct AnyLibcxxJumpBuffer { unsigned long long Registers[12]; } jmp_buf[1];
#ifdef __cplusplus
extern "C" {
#endif
int setjmp(jmp_buf environment) __attribute__((returns_twice));
#ifdef __cplusplus
[[noreturn]] void longjmp(jmp_buf environment, int value);
}
#else
_Noreturn void longjmp(jmp_buf environment, int value);
#endif
#endif
