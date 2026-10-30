extern "C" {
int __attribute__((sysv_abi)) feraiseexcept_nid_postfix(int) { return 0; }
void __attribute__((sysv_abi)) ClobberVolatileRegisters();
}
extern "C" { unsigned AnyLibcxxMathFailures = 0; }
extern "C" {
double acos(double value);
double __attribute__((sysv_abi)) acos_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double asin(double value);
double __attribute__((sysv_abi)) asin_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double atan(double value);
double __attribute__((sysv_abi)) atan_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double acosh(double value);
double __attribute__((sysv_abi)) acosh_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double asinh(double value);
double __attribute__((sysv_abi)) asinh_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double atanh(double value);
double __attribute__((sysv_abi)) atanh_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double cos(double value);
double __attribute__((sysv_abi)) cos_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double sin(double value);
double __attribute__((sysv_abi)) sin_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double tan(double value);
double __attribute__((sysv_abi)) tan_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double cosh(double value);
double __attribute__((sysv_abi)) cosh_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double sinh(double value);
double __attribute__((sysv_abi)) sinh_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double tanh(double value);
double __attribute__((sysv_abi)) tanh_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double exp(double value);
double __attribute__((sysv_abi)) exp_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double exp2(double value);
double __attribute__((sysv_abi)) exp2_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double expm1(double value);
double __attribute__((sysv_abi)) expm1_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double log(double value);
double __attribute__((sysv_abi)) log_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double log10(double value);
double __attribute__((sysv_abi)) log10_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double log2(double value);
double __attribute__((sysv_abi)) log2_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double log1p(double value);
double __attribute__((sysv_abi)) log1p_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double logb(double value);
double __attribute__((sysv_abi)) logb_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double sqrt(double value);
double __attribute__((sysv_abi)) sqrt_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double cbrt(double value);
double __attribute__((sysv_abi)) cbrt_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double erf(double value);
double __attribute__((sysv_abi)) erf_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double erfc(double value);
double __attribute__((sysv_abi)) erfc_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double ceil(double value);
double __attribute__((sysv_abi)) ceil_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double floor(double value);
double __attribute__((sysv_abi)) floor_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double trunc(double value);
double __attribute__((sysv_abi)) trunc_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double round(double value);
double __attribute__((sysv_abi)) round_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double nearbyint(double value);
double __attribute__((sysv_abi)) nearbyint_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double rint(double value);
double __attribute__((sysv_abi)) rint_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double fabs(double value);
double __attribute__((sysv_abi)) fabs_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double atan2(double left, double right);
double __attribute__((sysv_abi)) atan2_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double pow(double left, double right);
double __attribute__((sysv_abi)) pow_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double hypot(double left, double right);
double __attribute__((sysv_abi)) hypot_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double fmod(double left, double right);
double __attribute__((sysv_abi)) fmod_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double remainder(double left, double right);
double __attribute__((sysv_abi)) remainder_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double copysign(double left, double right);
double __attribute__((sysv_abi)) copysign_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double fdim(double left, double right);
double __attribute__((sysv_abi)) fdim_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double fmax(double left, double right);
double __attribute__((sysv_abi)) fmax_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double fmin(double left, double right);
double __attribute__((sysv_abi)) fmin_nid_postfix(double left, double right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double fma(double left, double right, double addend);
double __attribute__((sysv_abi)) fma_nid_postfix(double left, double right, double addend) { if (left != 2 || right != 3 || addend != 4) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double ldexp(double value, int exponent);
double __attribute__((sysv_abi)) ldexp_nid_postfix(double value, int exponent) { if (value != 2 || exponent != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double scalbn(double value, int exponent);
double __attribute__((sysv_abi)) scalbn_nid_postfix(double value, int exponent) { if (value != 2 || exponent != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double frexp(double value, int* exponent);
double __attribute__((sysv_abi)) frexp_nid_postfix(double value, int* exponent) { if (value != 2 || exponent != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double modf(double value, double* integral);
double __attribute__((sysv_abi)) modf_nid_postfix(double value, double* integral) { if (value != 2 || integral != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double remquo(double left, double right, int* quotient);
double __attribute__((sysv_abi)) remquo_nid_postfix(double left, double right, int* quotient) { if (left != 2 || right != 3 || quotient != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
double nan(const char* payload);
double __attribute__((sysv_abi)) nan_nid_postfix(const char* payload) { if (payload != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
int ilogb(double value);
int __attribute__((sysv_abi)) ilogb_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<int>(7); }
long long llround(double value);
long long __attribute__((sysv_abi)) llround_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long long llrint(double value);
long long __attribute__((sysv_abi)) llrint_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long lround(double value);
long long __attribute__((sysv_abi)) lround_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long lrint(double value);
long long __attribute__((sysv_abi)) lrint_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
double scalbln(double value, long exponent);
double __attribute__((sysv_abi)) scalbln_nid_postfix(double value, long long exponent) { if (value != 2 || exponent != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
float acosf(float value);
float __attribute__((sysv_abi)) acosf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float asinf(float value);
float __attribute__((sysv_abi)) asinf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float atanf(float value);
float __attribute__((sysv_abi)) atanf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float acoshf(float value);
float __attribute__((sysv_abi)) acoshf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float asinhf(float value);
float __attribute__((sysv_abi)) asinhf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float atanhf(float value);
float __attribute__((sysv_abi)) atanhf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float cosf(float value);
float __attribute__((sysv_abi)) cosf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float sinf(float value);
float __attribute__((sysv_abi)) sinf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float tanf(float value);
float __attribute__((sysv_abi)) tanf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float coshf(float value);
float __attribute__((sysv_abi)) coshf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float sinhf(float value);
float __attribute__((sysv_abi)) sinhf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float tanhf(float value);
float __attribute__((sysv_abi)) tanhf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float expf(float value);
float __attribute__((sysv_abi)) expf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float exp2f(float value);
float __attribute__((sysv_abi)) exp2f_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float expm1f(float value);
float __attribute__((sysv_abi)) expm1f_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float logf(float value);
float __attribute__((sysv_abi)) logf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float log10f(float value);
float __attribute__((sysv_abi)) log10f_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float log2f(float value);
float __attribute__((sysv_abi)) log2f_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float log1pf(float value);
float __attribute__((sysv_abi)) log1pf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float logbf(float value);
float __attribute__((sysv_abi)) logbf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float sqrtf(float value);
float __attribute__((sysv_abi)) sqrtf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float cbrtf(float value);
float __attribute__((sysv_abi)) cbrtf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float erff(float value);
float __attribute__((sysv_abi)) erff_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float erfcf(float value);
float __attribute__((sysv_abi)) erfcf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float ceilf(float value);
float __attribute__((sysv_abi)) ceilf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float floorf(float value);
float __attribute__((sysv_abi)) floorf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float truncf(float value);
float __attribute__((sysv_abi)) truncf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float roundf(float value);
float __attribute__((sysv_abi)) roundf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float nearbyintf(float value);
float __attribute__((sysv_abi)) nearbyintf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float rintf(float value);
float __attribute__((sysv_abi)) rintf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float fabsf(float value);
float __attribute__((sysv_abi)) fabsf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float atan2f(float left, float right);
float __attribute__((sysv_abi)) atan2f_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float powf(float left, float right);
float __attribute__((sysv_abi)) powf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float hypotf(float left, float right);
float __attribute__((sysv_abi)) hypotf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float fmodf(float left, float right);
float __attribute__((sysv_abi)) fmodf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float remainderf(float left, float right);
float __attribute__((sysv_abi)) remainderf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float copysignf(float left, float right);
float __attribute__((sysv_abi)) copysignf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float fdimf(float left, float right);
float __attribute__((sysv_abi)) fdimf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float fmaxf(float left, float right);
float __attribute__((sysv_abi)) fmaxf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float fminf(float left, float right);
float __attribute__((sysv_abi)) fminf_nid_postfix(float left, float right) { if (left != 2 || right != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float fmaf(float left, float right, float addend);
float __attribute__((sysv_abi)) fmaf_nid_postfix(float left, float right, float addend) { if (left != 2 || right != 3 || addend != 4) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float ldexpf(float value, int exponent);
float __attribute__((sysv_abi)) ldexpf_nid_postfix(float value, int exponent) { if (value != 2 || exponent != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float scalbnf(float value, int exponent);
float __attribute__((sysv_abi)) scalbnf_nid_postfix(float value, int exponent) { if (value != 2 || exponent != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float frexpf(float value, int* exponent);
float __attribute__((sysv_abi)) frexpf_nid_postfix(float value, int* exponent) { if (value != 2 || exponent != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float modff(float value, float* integral);
float __attribute__((sysv_abi)) modff_nid_postfix(float value, float* integral) { if (value != 2 || integral != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float remquof(float left, float right, int* quotient);
float __attribute__((sysv_abi)) remquof_nid_postfix(float left, float right, int* quotient) { if (left != 2 || right != 3 || quotient != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
float nanf(const char* payload);
float __attribute__((sysv_abi)) nanf_nid_postfix(const char* payload) { if (payload != nullptr) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
int ilogbf(float value);
int __attribute__((sysv_abi)) ilogbf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<int>(7); }
long long llroundf(float value);
long long __attribute__((sysv_abi)) llroundf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long long llrintf(float value);
long long __attribute__((sysv_abi)) llrintf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long lroundf(float value);
long long __attribute__((sysv_abi)) lroundf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long lrintf(float value);
long long __attribute__((sysv_abi)) lrintf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
float scalblnf(float value, long exponent);
float __attribute__((sysv_abi)) scalblnf_nid_postfix(float value, long long exponent) { if (value != 2 || exponent != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
long double acosl(long double value);
long double asinl(long double value);
long double atanl(long double value);
long double acoshl(long double value);
long double asinhl(long double value);
long double atanhl(long double value);
long double cosl(long double value);
long double sinl(long double value);
long double tanl(long double value);
long double coshl(long double value);
long double sinhl(long double value);
long double tanhl(long double value);
long double expl(long double value);
long double exp2l(long double value);
long double expm1l(long double value);
long double logl(long double value);
long double log10l(long double value);
long double log2l(long double value);
long double log1pl(long double value);
long double logbl(long double value);
long double sqrtl(long double value);
long double cbrtl(long double value);
long double erfl(long double value);
long double erfcl(long double value);
long double ceill(long double value);
long double floorl(long double value);
long double truncl(long double value);
long double roundl(long double value);
long double nearbyintl(long double value);
long double rintl(long double value);
long double fabsl(long double value);
long double atan2l(long double left, long double right);
long double powl(long double left, long double right);
long double hypotl(long double left, long double right);
long double fmodl(long double left, long double right);
long double remainderl(long double left, long double right);
long double copysignl(long double left, long double right);
long double fdiml(long double left, long double right);
long double fmaxl(long double left, long double right);
long double fminl(long double left, long double right);
long double fmal(long double left, long double right, long double addend);
long double ldexpl(long double value, int exponent);
long double scalbnl(long double value, int exponent);
long double frexpl(long double value, int* exponent);
long double modfl(long double value, long double* integral);
long double remquol(long double left, long double right, int* quotient);
long double nanl(const char* payload);
int ilogbl(long double value);
int __attribute__((sysv_abi)) ilogbl_nid_postfix(long double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<int>(7); }
long long llroundl(long double value);
long long __attribute__((sysv_abi)) llroundl_nid_postfix(long double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long long llrintl(long double value);
long long __attribute__((sysv_abi)) llrintl_nid_postfix(long double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long lroundl(long double value);
long long __attribute__((sysv_abi)) lroundl_nid_postfix(long double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long lrintl(long double value);
long long __attribute__((sysv_abi)) lrintl_nid_postfix(long double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<long long>(7); }
long double scalblnl(long double value, long exponent);
double lgamma(double value);
double __attribute__((sysv_abi)) lgamma_nid_postfix(double value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
long double lgammal(long double value);
float tgammaf(float value);
float __attribute__((sysv_abi)) tgammaf_nid_postfix(float value) { if (value != 2) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
long double tgammal(long double value);
double nextafter(double value, double direction);
double __attribute__((sysv_abi)) nextafter_nid_postfix(double value, double direction) { if (value != 2 || direction != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<double>(7); }
float nextafterf(float value, float direction);
float __attribute__((sysv_abi)) nextafterf_nid_postfix(float value, float direction) { if (value != 2 || direction != 3) ++AnyLibcxxMathFailures; ClobberVolatileRegisters(); return static_cast<float>(7); }
}
int main() {
    if (acos(2) != 7) ++AnyLibcxxMathFailures;
    if (asin(2) != 7) ++AnyLibcxxMathFailures;
    if (atan(2) != 7) ++AnyLibcxxMathFailures;
    if (acosh(2) != 7) ++AnyLibcxxMathFailures;
    if (asinh(2) != 7) ++AnyLibcxxMathFailures;
    if (atanh(2) != 7) ++AnyLibcxxMathFailures;
    if (cos(2) != 7) ++AnyLibcxxMathFailures;
    if (sin(2) != 7) ++AnyLibcxxMathFailures;
    if (tan(2) != 7) ++AnyLibcxxMathFailures;
    if (cosh(2) != 7) ++AnyLibcxxMathFailures;
    if (sinh(2) != 7) ++AnyLibcxxMathFailures;
    if (tanh(2) != 7) ++AnyLibcxxMathFailures;
    if (exp(2) != 7) ++AnyLibcxxMathFailures;
    if (exp2(2) != 7) ++AnyLibcxxMathFailures;
    if (expm1(2) != 7) ++AnyLibcxxMathFailures;
    if (log(2) != 7) ++AnyLibcxxMathFailures;
    if (log10(2) != 7) ++AnyLibcxxMathFailures;
    if (log2(2) != 7) ++AnyLibcxxMathFailures;
    if (log1p(2) != 7) ++AnyLibcxxMathFailures;
    if (logb(2) != 7) ++AnyLibcxxMathFailures;
    if (sqrt(2) != 7) ++AnyLibcxxMathFailures;
    if (cbrt(2) != 7) ++AnyLibcxxMathFailures;
    if (erf(2) != 7) ++AnyLibcxxMathFailures;
    if (erfc(2) != 7) ++AnyLibcxxMathFailures;
    if (ceil(2) != 7) ++AnyLibcxxMathFailures;
    if (floor(2) != 7) ++AnyLibcxxMathFailures;
    if (trunc(2) != 7) ++AnyLibcxxMathFailures;
    if (round(2) != 7) ++AnyLibcxxMathFailures;
    if (nearbyint(2) != 7) ++AnyLibcxxMathFailures;
    if (rint(2) != 7) ++AnyLibcxxMathFailures;
    if (fabs(2) != 7) ++AnyLibcxxMathFailures;
    if (atan2(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (pow(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (hypot(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmod(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (remainder(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (copysign(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fdim(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmax(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmin(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fma(2, 3, 4) != 7) ++AnyLibcxxMathFailures;
    if (ldexp(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (scalbn(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (frexp(2, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (modf(2, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (remquo(2, 3, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (nan(nullptr) != 7) ++AnyLibcxxMathFailures;
    if (ilogb(2) != 7) ++AnyLibcxxMathFailures;
    if (llround(2) != 7) ++AnyLibcxxMathFailures;
    if (llrint(2) != 7) ++AnyLibcxxMathFailures;
    if (lround(2) != 7) ++AnyLibcxxMathFailures;
    if (lrint(2) != 7) ++AnyLibcxxMathFailures;
    if (scalbln(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (acosf(2) != 7) ++AnyLibcxxMathFailures;
    if (asinf(2) != 7) ++AnyLibcxxMathFailures;
    if (atanf(2) != 7) ++AnyLibcxxMathFailures;
    if (acoshf(2) != 7) ++AnyLibcxxMathFailures;
    if (asinhf(2) != 7) ++AnyLibcxxMathFailures;
    if (atanhf(2) != 7) ++AnyLibcxxMathFailures;
    if (cosf(2) != 7) ++AnyLibcxxMathFailures;
    if (sinf(2) != 7) ++AnyLibcxxMathFailures;
    if (tanf(2) != 7) ++AnyLibcxxMathFailures;
    if (coshf(2) != 7) ++AnyLibcxxMathFailures;
    if (sinhf(2) != 7) ++AnyLibcxxMathFailures;
    if (tanhf(2) != 7) ++AnyLibcxxMathFailures;
    if (expf(2) != 7) ++AnyLibcxxMathFailures;
    if (exp2f(2) != 7) ++AnyLibcxxMathFailures;
    if (expm1f(2) != 7) ++AnyLibcxxMathFailures;
    if (logf(2) != 7) ++AnyLibcxxMathFailures;
    if (log10f(2) != 7) ++AnyLibcxxMathFailures;
    if (log2f(2) != 7) ++AnyLibcxxMathFailures;
    if (log1pf(2) != 7) ++AnyLibcxxMathFailures;
    if (logbf(2) != 7) ++AnyLibcxxMathFailures;
    if (sqrtf(2) != 7) ++AnyLibcxxMathFailures;
    if (cbrtf(2) != 7) ++AnyLibcxxMathFailures;
    if (erff(2) != 7) ++AnyLibcxxMathFailures;
    if (erfcf(2) != 7) ++AnyLibcxxMathFailures;
    if (ceilf(2) != 7) ++AnyLibcxxMathFailures;
    if (floorf(2) != 7) ++AnyLibcxxMathFailures;
    if (truncf(2) != 7) ++AnyLibcxxMathFailures;
    if (roundf(2) != 7) ++AnyLibcxxMathFailures;
    if (nearbyintf(2) != 7) ++AnyLibcxxMathFailures;
    if (rintf(2) != 7) ++AnyLibcxxMathFailures;
    if (fabsf(2) != 7) ++AnyLibcxxMathFailures;
    if (atan2f(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (powf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (hypotf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmodf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (remainderf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (copysignf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fdimf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmaxf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fminf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmaf(2, 3, 4) != 7) ++AnyLibcxxMathFailures;
    if (ldexpf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (scalbnf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (frexpf(2, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (modff(2, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (remquof(2, 3, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (nanf(nullptr) != 7) ++AnyLibcxxMathFailures;
    if (ilogbf(2) != 7) ++AnyLibcxxMathFailures;
    if (llroundf(2) != 7) ++AnyLibcxxMathFailures;
    if (llrintf(2) != 7) ++AnyLibcxxMathFailures;
    if (lroundf(2) != 7) ++AnyLibcxxMathFailures;
    if (lrintf(2) != 7) ++AnyLibcxxMathFailures;
    if (scalblnf(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (acosl(2) != 7) ++AnyLibcxxMathFailures;
    if (asinl(2) != 7) ++AnyLibcxxMathFailures;
    if (atanl(2) != 7) ++AnyLibcxxMathFailures;
    if (acoshl(2) != 7) ++AnyLibcxxMathFailures;
    if (asinhl(2) != 7) ++AnyLibcxxMathFailures;
    if (atanhl(2) != 7) ++AnyLibcxxMathFailures;
    if (cosl(2) != 7) ++AnyLibcxxMathFailures;
    if (sinl(2) != 7) ++AnyLibcxxMathFailures;
    if (tanl(2) != 7) ++AnyLibcxxMathFailures;
    if (coshl(2) != 7) ++AnyLibcxxMathFailures;
    if (sinhl(2) != 7) ++AnyLibcxxMathFailures;
    if (tanhl(2) != 7) ++AnyLibcxxMathFailures;
    if (expl(2) != 7) ++AnyLibcxxMathFailures;
    if (exp2l(2) != 7) ++AnyLibcxxMathFailures;
    if (expm1l(2) != 7) ++AnyLibcxxMathFailures;
    if (logl(2) != 7) ++AnyLibcxxMathFailures;
    if (log10l(2) != 7) ++AnyLibcxxMathFailures;
    if (log2l(2) != 7) ++AnyLibcxxMathFailures;
    if (log1pl(2) != 7) ++AnyLibcxxMathFailures;
    if (logbl(2) != 7) ++AnyLibcxxMathFailures;
    if (sqrtl(2) != 7) ++AnyLibcxxMathFailures;
    if (cbrtl(2) != 7) ++AnyLibcxxMathFailures;
    if (erfl(2) != 7) ++AnyLibcxxMathFailures;
    if (erfcl(2) != 7) ++AnyLibcxxMathFailures;
    if (ceill(2) != 7) ++AnyLibcxxMathFailures;
    if (floorl(2) != 7) ++AnyLibcxxMathFailures;
    if (truncl(2) != 7) ++AnyLibcxxMathFailures;
    if (roundl(2) != 7) ++AnyLibcxxMathFailures;
    if (nearbyintl(2) != 7) ++AnyLibcxxMathFailures;
    if (rintl(2) != 7) ++AnyLibcxxMathFailures;
    if (fabsl(2) != 7) ++AnyLibcxxMathFailures;
    if (atan2l(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (powl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (hypotl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmodl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (remainderl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (copysignl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fdiml(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmaxl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fminl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (fmal(2, 3, 4) != 7) ++AnyLibcxxMathFailures;
    if (ldexpl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (scalbnl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (frexpl(2, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (modfl(2, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (remquol(2, 3, nullptr) != 7) ++AnyLibcxxMathFailures;
    if (nanl(nullptr) != 7) ++AnyLibcxxMathFailures;
    if (ilogbl(2) != 7) ++AnyLibcxxMathFailures;
    if (llroundl(2) != 7) ++AnyLibcxxMathFailures;
    if (llrintl(2) != 7) ++AnyLibcxxMathFailures;
    if (lroundl(2) != 7) ++AnyLibcxxMathFailures;
    if (lrintl(2) != 7) ++AnyLibcxxMathFailures;
    if (scalblnl(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (lgamma(2) != 7) ++AnyLibcxxMathFailures;
    if (lgammal(2) != 7) ++AnyLibcxxMathFailures;
    if (tgammaf(2) != 7) ++AnyLibcxxMathFailures;
    if (tgammal(2) != 7) ++AnyLibcxxMathFailures;
    if (nextafter(2, 3) != 7) ++AnyLibcxxMathFailures;
    if (nextafterf(2, 3) != 7) ++AnyLibcxxMathFailures;
    return AnyLibcxxMathFailures ? 1 : 0;
}
