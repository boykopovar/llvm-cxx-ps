#ifndef ANYLIBCXX_WINDOWS_FENV_H
#define ANYLIBCXX_WINDOWS_FENV_H
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
#ifdef __cplusplus
extern "C" {
#endif
extern const fenv_t AnyLibcxxDefaultEnvironment;
#define FE_DFL_ENV (&AnyLibcxxDefaultEnvironment)
int feclearexcept(int exceptions);
int fegetexceptflag(fexcept_t* flags, int exceptions);
int feraiseexcept(int exceptions);
int fesetexceptflag(const fexcept_t* flags, int exceptions);
int fetestexcept(int exceptions);
int fegetround(void);
int fesetround(int rounding);
int fegetenv(fenv_t* environment);
int fesetenv(const fenv_t* environment);
int feupdateenv(const fenv_t* environment);
int feholdexcept(fenv_t* environment);
#ifdef __cplusplus
}
#endif
#endif
