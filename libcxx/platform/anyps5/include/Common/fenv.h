#ifndef ANYLIBCXX_FENV_H
#define ANYLIBCXX_FENV_H
#define FE_INVALID 1
#define FE_DIVBYZERO 4
#define FE_OVERFLOW 8
#define FE_UNDERFLOW 16
#define FE_INEXACT 32
#define FE_ALL_EXCEPT 61
#define FE_TONEAREST 0
#define FE_DOWNWARD 1024
#define FE_UPWARD 2048
#define FE_TOWARDZERO 3072
typedef unsigned short fexcept_t;
typedef struct {
    unsigned int Control;
    unsigned int Status;
    unsigned int Tag;
    unsigned char Other[16];
    unsigned int Mxcsr;
} fenv_t;
#ifdef _WIN32
#define ANYLIBCXX_FENV_NAME(name)
#else
#define ANYLIBCXX_FENV_NAME(name) __asm__("AnyLibcxx" #name)
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern const fenv_t AnyLibcxxDefaultEnvironment;
#define FE_DFL_ENV (&AnyLibcxxDefaultEnvironment)
int feclearexcept(int exceptions) ANYLIBCXX_FENV_NAME(feclearexcept);
int fegetexceptflag(fexcept_t* flags, int exceptions) ANYLIBCXX_FENV_NAME(fegetexceptflag);
int feraiseexcept(int exceptions) ANYLIBCXX_FENV_NAME(feraiseexcept);
int fesetexceptflag(const fexcept_t* flags, int exceptions) ANYLIBCXX_FENV_NAME(fesetexceptflag);
int fetestexcept(int exceptions) ANYLIBCXX_FENV_NAME(fetestexcept);
int fegetround(void) ANYLIBCXX_FENV_NAME(fegetround);
int fesetround(int rounding) ANYLIBCXX_FENV_NAME(fesetround);
int fegetenv(fenv_t* environment) ANYLIBCXX_FENV_NAME(fegetenv);
int fesetenv(const fenv_t* environment) ANYLIBCXX_FENV_NAME(fesetenv);
int feupdateenv(const fenv_t* environment) ANYLIBCXX_FENV_NAME(feupdateenv);
int feholdexcept(fenv_t* environment) ANYLIBCXX_FENV_NAME(feholdexcept);
#ifdef __cplusplus
}
#endif
#undef ANYLIBCXX_FENV_NAME
#endif
