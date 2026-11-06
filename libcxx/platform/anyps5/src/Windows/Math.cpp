#include <limits.h>

extern "C" {
int __attribute__((sysv_abi)) feraiseexcept_nid_postfix(int exceptions);
double __attribute__((sysv_abi)) acos_nid_postfix(double value);
double acos(double value) { return acos_nid_postfix(value); }
double __attribute__((sysv_abi)) asin_nid_postfix(double value);
double asin(double value) { return asin_nid_postfix(value); }
double __attribute__((sysv_abi)) atan_nid_postfix(double value);
double atan(double value) { return atan_nid_postfix(value); }
double __attribute__((sysv_abi)) acosh_nid_postfix(double value);
double acosh(double value) { return acosh_nid_postfix(value); }
double __attribute__((sysv_abi)) asinh_nid_postfix(double value);
double asinh(double value) { return asinh_nid_postfix(value); }
double __attribute__((sysv_abi)) atanh_nid_postfix(double value);
double atanh(double value) { return atanh_nid_postfix(value); }
double __attribute__((sysv_abi)) cos_nid_postfix(double value);
double cos(double value) { return cos_nid_postfix(value); }
double __attribute__((sysv_abi)) sin_nid_postfix(double value);
double sin(double value) { return sin_nid_postfix(value); }
double __attribute__((sysv_abi)) tan_nid_postfix(double value);
double tan(double value) { return tan_nid_postfix(value); }
double __attribute__((sysv_abi)) cosh_nid_postfix(double value);
double cosh(double value) { return cosh_nid_postfix(value); }
double __attribute__((sysv_abi)) sinh_nid_postfix(double value);
double sinh(double value) { return sinh_nid_postfix(value); }
double __attribute__((sysv_abi)) tanh_nid_postfix(double value);
double tanh(double value) { return tanh_nid_postfix(value); }
double __attribute__((sysv_abi)) exp_nid_postfix(double value);
double exp(double value) { return exp_nid_postfix(value); }
double __attribute__((sysv_abi)) exp2_nid_postfix(double value);
double exp2(double value) { return exp2_nid_postfix(value); }
double __attribute__((sysv_abi)) expm1_nid_postfix(double value);
double expm1(double value) { return expm1_nid_postfix(value); }
double __attribute__((sysv_abi)) log_nid_postfix(double value);
double log(double value) { return log_nid_postfix(value); }
double __attribute__((sysv_abi)) log10_nid_postfix(double value);
double log10(double value) { return log10_nid_postfix(value); }
double __attribute__((sysv_abi)) log2_nid_postfix(double value);
double log2(double value) { return log2_nid_postfix(value); }
double __attribute__((sysv_abi)) log1p_nid_postfix(double value);
double log1p(double value) { return log1p_nid_postfix(value); }
double __attribute__((sysv_abi)) logb_nid_postfix(double value);
double logb(double value) { return logb_nid_postfix(value); }
double __attribute__((sysv_abi)) sqrt_nid_postfix(double value);
double sqrt(double value) { return sqrt_nid_postfix(value); }
double __attribute__((sysv_abi)) cbrt_nid_postfix(double value);
double cbrt(double value) { return cbrt_nid_postfix(value); }
double __attribute__((sysv_abi)) erf_nid_postfix(double value);
double erf(double value) { return erf_nid_postfix(value); }
double __attribute__((sysv_abi)) erfc_nid_postfix(double value);
double erfc(double value) { return erfc_nid_postfix(value); }
double __attribute__((sysv_abi)) ceil_nid_postfix(double value);
double ceil(double value) { return ceil_nid_postfix(value); }
double __attribute__((sysv_abi)) floor_nid_postfix(double value);
double floor(double value) { return floor_nid_postfix(value); }
double __attribute__((sysv_abi)) trunc_nid_postfix(double value);
double trunc(double value) { return trunc_nid_postfix(value); }
double __attribute__((sysv_abi)) round_nid_postfix(double value);
double round(double value) { return round_nid_postfix(value); }
double __attribute__((sysv_abi)) nearbyint_nid_postfix(double value);
double nearbyint(double value) { return nearbyint_nid_postfix(value); }
double __attribute__((sysv_abi)) rint_nid_postfix(double value);
double rint(double value) { return rint_nid_postfix(value); }
double __attribute__((sysv_abi)) fabs_nid_postfix(double value);
double fabs(double value) { return fabs_nid_postfix(value); }
double __attribute__((sysv_abi)) atan2_nid_postfix(double left, double right);
double atan2(double left, double right) { return atan2_nid_postfix(left, right); }
double __attribute__((sysv_abi)) pow_nid_postfix(double left, double right);
double pow(double left, double right) { return pow_nid_postfix(left, right); }
double __attribute__((sysv_abi)) hypot_nid_postfix(double left, double right);
double hypot(double left, double right) { return hypot_nid_postfix(left, right); }
double __attribute__((sysv_abi)) fmod_nid_postfix(double left, double right);
double fmod(double left, double right) { return fmod_nid_postfix(left, right); }
double __attribute__((sysv_abi)) remainder_nid_postfix(double left, double right);
double remainder(double left, double right) { return remainder_nid_postfix(left, right); }
double __attribute__((sysv_abi)) copysign_nid_postfix(double left, double right);
double copysign(double left, double right) { return copysign_nid_postfix(left, right); }
double __attribute__((sysv_abi)) fdim_nid_postfix(double left, double right);
double fdim(double left, double right) { return fdim_nid_postfix(left, right); }
double __attribute__((sysv_abi)) fmax_nid_postfix(double left, double right);
double fmax(double left, double right) { return fmax_nid_postfix(left, right); }
double __attribute__((sysv_abi)) fmin_nid_postfix(double left, double right);
double fmin(double left, double right) { return fmin_nid_postfix(left, right); }
double __attribute__((sysv_abi)) fma_nid_postfix(double left, double right, double addend);
double fma(double left, double right, double addend) { return fma_nid_postfix(left, right, addend); }
double __attribute__((sysv_abi)) ldexp_nid_postfix(double value, int exponent);
double ldexp(double value, int exponent) { return ldexp_nid_postfix(value, exponent); }
double __attribute__((sysv_abi)) scalbn_nid_postfix(double value, int exponent);
double scalbn(double value, int exponent) { return scalbn_nid_postfix(value, exponent); }
double __attribute__((sysv_abi)) frexp_nid_postfix(double value, int* exponent);
double frexp(double value, int* exponent) { return frexp_nid_postfix(value, exponent); }
double __attribute__((sysv_abi)) modf_nid_postfix(double value, double* integral);
double modf(double value, double* integral) { return modf_nid_postfix(value, integral); }
double __attribute__((sysv_abi)) remquo_nid_postfix(double left, double right, int* quotient);
double remquo(double left, double right, int* quotient) { return remquo_nid_postfix(left, right, quotient); }
double __attribute__((sysv_abi)) nan_nid_postfix(const char* payload);
double nan(const char* payload) { return nan_nid_postfix(payload); }
int __attribute__((sysv_abi)) ilogb_nid_postfix(double value);
int ilogb(double value) { return ilogb_nid_postfix(value); }
long long __attribute__((sysv_abi)) llround_nid_postfix(double value);
long long llround(double value) { return llround_nid_postfix(value); }
long long __attribute__((sysv_abi)) llrint_nid_postfix(double value);
long long llrint(double value) { return llrint_nid_postfix(value); }
long long __attribute__((sysv_abi)) lround_nid_postfix(double value);
long lround(double value) { const auto result = lround_nid_postfix(value); if (result < LONG_MIN || result > LONG_MAX) { feraiseexcept_nid_postfix(1); return LONG_MIN; } return static_cast<long>(result); }
long long __attribute__((sysv_abi)) lrint_nid_postfix(double value);
long lrint(double value) { const auto result = lrint_nid_postfix(value); if (result < LONG_MIN || result > LONG_MAX) { feraiseexcept_nid_postfix(1); return LONG_MIN; } return static_cast<long>(result); }
double __attribute__((sysv_abi)) scalbln_nid_postfix(double value, long long exponent);
double scalbln(double value, long exponent) { return scalbln_nid_postfix(value, exponent); }
float __attribute__((sysv_abi)) acosf_nid_postfix(float value);
float acosf(float value) { return acosf_nid_postfix(value); }
float __attribute__((sysv_abi)) asinf_nid_postfix(float value);
float asinf(float value) { return asinf_nid_postfix(value); }
float __attribute__((sysv_abi)) atanf_nid_postfix(float value);
float atanf(float value) { return atanf_nid_postfix(value); }
float __attribute__((sysv_abi)) acoshf_nid_postfix(float value);
float acoshf(float value) { return acoshf_nid_postfix(value); }
float __attribute__((sysv_abi)) asinhf_nid_postfix(float value);
float asinhf(float value) { return asinhf_nid_postfix(value); }
float __attribute__((sysv_abi)) atanhf_nid_postfix(float value);
float atanhf(float value) { return atanhf_nid_postfix(value); }
float __attribute__((sysv_abi)) cosf_nid_postfix(float value);
float cosf(float value) { return cosf_nid_postfix(value); }
float __attribute__((sysv_abi)) sinf_nid_postfix(float value);
float sinf(float value) { return sinf_nid_postfix(value); }
float __attribute__((sysv_abi)) tanf_nid_postfix(float value);
float tanf(float value) { return tanf_nid_postfix(value); }
float __attribute__((sysv_abi)) coshf_nid_postfix(float value);
float coshf(float value) { return coshf_nid_postfix(value); }
float __attribute__((sysv_abi)) sinhf_nid_postfix(float value);
float sinhf(float value) { return sinhf_nid_postfix(value); }
float __attribute__((sysv_abi)) tanhf_nid_postfix(float value);
float tanhf(float value) { return tanhf_nid_postfix(value); }
float __attribute__((sysv_abi)) expf_nid_postfix(float value);
float expf(float value) { return expf_nid_postfix(value); }
float __attribute__((sysv_abi)) exp2f_nid_postfix(float value);
float exp2f(float value) { return exp2f_nid_postfix(value); }
float __attribute__((sysv_abi)) expm1f_nid_postfix(float value);
float expm1f(float value) { return expm1f_nid_postfix(value); }
float __attribute__((sysv_abi)) logf_nid_postfix(float value);
float logf(float value) { return logf_nid_postfix(value); }
float __attribute__((sysv_abi)) log10f_nid_postfix(float value);
float log10f(float value) { return log10f_nid_postfix(value); }
float __attribute__((sysv_abi)) log2f_nid_postfix(float value);
float log2f(float value) { return log2f_nid_postfix(value); }
float __attribute__((sysv_abi)) log1pf_nid_postfix(float value);
float log1pf(float value) { return log1pf_nid_postfix(value); }
float __attribute__((sysv_abi)) logbf_nid_postfix(float value);
float logbf(float value) { return logbf_nid_postfix(value); }
float __attribute__((sysv_abi)) sqrtf_nid_postfix(float value);
float sqrtf(float value) { return sqrtf_nid_postfix(value); }
float __attribute__((sysv_abi)) cbrtf_nid_postfix(float value);
float cbrtf(float value) { return cbrtf_nid_postfix(value); }
float __attribute__((sysv_abi)) erff_nid_postfix(float value);
float erff(float value) { return erff_nid_postfix(value); }
float __attribute__((sysv_abi)) erfcf_nid_postfix(float value);
float erfcf(float value) { return erfcf_nid_postfix(value); }
float __attribute__((sysv_abi)) ceilf_nid_postfix(float value);
float ceilf(float value) { return ceilf_nid_postfix(value); }
float __attribute__((sysv_abi)) floorf_nid_postfix(float value);
float floorf(float value) { return floorf_nid_postfix(value); }
float __attribute__((sysv_abi)) truncf_nid_postfix(float value);
float truncf(float value) { return truncf_nid_postfix(value); }
float __attribute__((sysv_abi)) roundf_nid_postfix(float value);
float roundf(float value) { return roundf_nid_postfix(value); }
float __attribute__((sysv_abi)) nearbyintf_nid_postfix(float value);
float nearbyintf(float value) { return nearbyintf_nid_postfix(value); }
float __attribute__((sysv_abi)) rintf_nid_postfix(float value);
float rintf(float value) { return rintf_nid_postfix(value); }
float __attribute__((sysv_abi)) fabsf_nid_postfix(float value);
float fabsf(float value) { return fabsf_nid_postfix(value); }
float __attribute__((sysv_abi)) atan2f_nid_postfix(float left, float right);
float atan2f(float left, float right) { return atan2f_nid_postfix(left, right); }
float __attribute__((sysv_abi)) powf_nid_postfix(float left, float right);
float powf(float left, float right) { return powf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) hypotf_nid_postfix(float left, float right);
float hypotf(float left, float right) { return hypotf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) fmodf_nid_postfix(float left, float right);
float fmodf(float left, float right) { return fmodf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) remainderf_nid_postfix(float left, float right);
float remainderf(float left, float right) { return remainderf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) copysignf_nid_postfix(float left, float right);
float copysignf(float left, float right) { return copysignf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) fdimf_nid_postfix(float left, float right);
float fdimf(float left, float right) { return fdimf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) fmaxf_nid_postfix(float left, float right);
float fmaxf(float left, float right) { return fmaxf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) fminf_nid_postfix(float left, float right);
float fminf(float left, float right) { return fminf_nid_postfix(left, right); }
float __attribute__((sysv_abi)) fmaf_nid_postfix(float left, float right, float addend);
float fmaf(float left, float right, float addend) { return fmaf_nid_postfix(left, right, addend); }
float __attribute__((sysv_abi)) ldexpf_nid_postfix(float value, int exponent);
float ldexpf(float value, int exponent) { return ldexpf_nid_postfix(value, exponent); }
float __attribute__((sysv_abi)) scalbnf_nid_postfix(float value, int exponent);
float scalbnf(float value, int exponent) { return scalbnf_nid_postfix(value, exponent); }
float __attribute__((sysv_abi)) frexpf_nid_postfix(float value, int* exponent);
float frexpf(float value, int* exponent) { return frexpf_nid_postfix(value, exponent); }
float __attribute__((sysv_abi)) modff_nid_postfix(float value, float* integral);
float modff(float value, float* integral) { return modff_nid_postfix(value, integral); }
float __attribute__((sysv_abi)) remquof_nid_postfix(float left, float right, int* quotient);
float remquof(float left, float right, int* quotient) { return remquof_nid_postfix(left, right, quotient); }
float __attribute__((sysv_abi)) nanf_nid_postfix(const char* payload);
float nanf(const char* payload) { return nanf_nid_postfix(payload); }
int __attribute__((sysv_abi)) ilogbf_nid_postfix(float value);
int ilogbf(float value) { return ilogbf_nid_postfix(value); }
long long __attribute__((sysv_abi)) llroundf_nid_postfix(float value);
long long llroundf(float value) { return llroundf_nid_postfix(value); }
long long __attribute__((sysv_abi)) llrintf_nid_postfix(float value);
long long llrintf(float value) { return llrintf_nid_postfix(value); }
long long __attribute__((sysv_abi)) lroundf_nid_postfix(float value);
long lroundf(float value) { const auto result = lroundf_nid_postfix(value); if (result < LONG_MIN || result > LONG_MAX) { feraiseexcept_nid_postfix(1); return LONG_MIN; } return static_cast<long>(result); }
long long __attribute__((sysv_abi)) lrintf_nid_postfix(float value);
long lrintf(float value) { const auto result = lrintf_nid_postfix(value); if (result < LONG_MIN || result > LONG_MAX) { feraiseexcept_nid_postfix(1); return LONG_MIN; } return static_cast<long>(result); }
float __attribute__((sysv_abi)) scalblnf_nid_postfix(float value, long long exponent);
float scalblnf(float value, long exponent) { return scalblnf_nid_postfix(value, exponent); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_acosl(long double value);
long double acosl(long double value) { return AnyLibcxxGuest_acosl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_asinl(long double value);
long double asinl(long double value) { return AnyLibcxxGuest_asinl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_atanl(long double value);
long double atanl(long double value) { return AnyLibcxxGuest_atanl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_acoshl(long double value);
long double acoshl(long double value) { return AnyLibcxxGuest_acoshl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_asinhl(long double value);
long double asinhl(long double value) { return AnyLibcxxGuest_asinhl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_atanhl(long double value);
long double atanhl(long double value) { return AnyLibcxxGuest_atanhl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_cosl(long double value);
long double cosl(long double value) { return AnyLibcxxGuest_cosl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_sinl(long double value);
long double sinl(long double value) { return AnyLibcxxGuest_sinl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_tanl(long double value);
long double tanl(long double value) { return AnyLibcxxGuest_tanl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_coshl(long double value);
long double coshl(long double value) { return AnyLibcxxGuest_coshl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_sinhl(long double value);
long double sinhl(long double value) { return AnyLibcxxGuest_sinhl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_tanhl(long double value);
long double tanhl(long double value) { return AnyLibcxxGuest_tanhl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_expl(long double value);
long double expl(long double value) { return AnyLibcxxGuest_expl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_exp2l(long double value);
long double exp2l(long double value) { return AnyLibcxxGuest_exp2l(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_expm1l(long double value);
long double expm1l(long double value) { return AnyLibcxxGuest_expm1l(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_logl(long double value);
long double logl(long double value) { return AnyLibcxxGuest_logl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_log10l(long double value);
long double log10l(long double value) { return AnyLibcxxGuest_log10l(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_log2l(long double value);
long double log2l(long double value) { return AnyLibcxxGuest_log2l(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_log1pl(long double value);
long double log1pl(long double value) { return AnyLibcxxGuest_log1pl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_logbl(long double value);
long double logbl(long double value) { return AnyLibcxxGuest_logbl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_sqrtl(long double value);
long double sqrtl(long double value) { return AnyLibcxxGuest_sqrtl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_cbrtl(long double value);
long double cbrtl(long double value) { return AnyLibcxxGuest_cbrtl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_erfl(long double value);
long double erfl(long double value) { return AnyLibcxxGuest_erfl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_erfcl(long double value);
long double erfcl(long double value) { return AnyLibcxxGuest_erfcl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_ceill(long double value);
long double ceill(long double value) { return AnyLibcxxGuest_ceill(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_floorl(long double value);
long double floorl(long double value) { return AnyLibcxxGuest_floorl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_truncl(long double value);
long double truncl(long double value) { return AnyLibcxxGuest_truncl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_roundl(long double value);
long double roundl(long double value) { return AnyLibcxxGuest_roundl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_nearbyintl(long double value);
long double nearbyintl(long double value) { return AnyLibcxxGuest_nearbyintl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_rintl(long double value);
long double rintl(long double value) { return AnyLibcxxGuest_rintl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_fabsl(long double value);
long double fabsl(long double value) { return AnyLibcxxGuest_fabsl(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_atan2l(long double left, long double right);
long double atan2l(long double left, long double right) { return AnyLibcxxGuest_atan2l(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_powl(long double left, long double right);
long double powl(long double left, long double right) { return AnyLibcxxGuest_powl(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_hypotl(long double left, long double right);
long double hypotl(long double left, long double right) { return AnyLibcxxGuest_hypotl(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_fmodl(long double left, long double right);
long double fmodl(long double left, long double right) { return AnyLibcxxGuest_fmodl(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_remainderl(long double left, long double right);
long double remainderl(long double left, long double right) { return AnyLibcxxGuest_remainderl(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_copysignl(long double left, long double right);
long double copysignl(long double left, long double right) { return AnyLibcxxGuest_copysignl(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_fdiml(long double left, long double right);
long double fdiml(long double left, long double right) { return AnyLibcxxGuest_fdiml(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_fmaxl(long double left, long double right);
long double fmaxl(long double left, long double right) { return AnyLibcxxGuest_fmaxl(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_fminl(long double left, long double right);
long double fminl(long double left, long double right) { return AnyLibcxxGuest_fminl(left, right); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_fmal(long double left, long double right, long double addend);
long double fmal(long double left, long double right, long double addend) { return AnyLibcxxGuest_fmal(left, right, addend); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_ldexpl(long double value, int exponent);
long double ldexpl(long double value, int exponent) { return AnyLibcxxGuest_ldexpl(value, exponent); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_scalbnl(long double value, int exponent);
long double scalbnl(long double value, int exponent) { return AnyLibcxxGuest_scalbnl(value, exponent); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_frexpl(long double value, int* exponent);
long double frexpl(long double value, int* exponent) { return AnyLibcxxGuest_frexpl(value, exponent); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_modfl(long double value, long double* integral);
long double modfl(long double value, long double* integral) { return AnyLibcxxGuest_modfl(value, integral); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_remquol(long double left, long double right, int* quotient);
long double remquol(long double left, long double right, int* quotient) { return AnyLibcxxGuest_remquol(left, right, quotient); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_nanl(const char* payload);
long double nanl(const char* payload) { return AnyLibcxxGuest_nanl(payload); }
int __attribute__((sysv_abi)) ilogbl_nid_postfix(long double value);
int ilogbl(long double value) { return ilogbl_nid_postfix(value); }
long long __attribute__((sysv_abi)) llroundl_nid_postfix(long double value);
long long llroundl(long double value) { return llroundl_nid_postfix(value); }
long long __attribute__((sysv_abi)) llrintl_nid_postfix(long double value);
long long llrintl(long double value) { return llrintl_nid_postfix(value); }
long long __attribute__((sysv_abi)) lroundl_nid_postfix(long double value);
long lroundl(long double value) { const auto result = lroundl_nid_postfix(value); if (result < LONG_MIN || result > LONG_MAX) { feraiseexcept_nid_postfix(1); return LONG_MIN; } return static_cast<long>(result); }
long long __attribute__((sysv_abi)) lrintl_nid_postfix(long double value);
long lrintl(long double value) { const auto result = lrintl_nid_postfix(value); if (result < LONG_MIN || result > LONG_MAX) { feraiseexcept_nid_postfix(1); return LONG_MIN; } return static_cast<long>(result); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_scalblnl(long double value, long long exponent);
long double scalblnl(long double value, long exponent) { return AnyLibcxxGuest_scalblnl(value, exponent); }
double __attribute__((sysv_abi)) lgamma_nid_postfix(double value);
double lgamma(double value) { return lgamma_nid_postfix(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_lgammal(long double value);
long double lgammal(long double value) { return AnyLibcxxGuest_lgammal(value); }
float __attribute__((sysv_abi)) tgammaf_nid_postfix(float value);
float tgammaf(float value) { return tgammaf_nid_postfix(value); }
long double __attribute__((sysv_abi)) AnyLibcxxGuest_tgammal(long double value);
long double tgammal(long double value) { return AnyLibcxxGuest_tgammal(value); }
double __attribute__((sysv_abi)) nextafter_nid_postfix(double value, double direction);
double nextafter(double value, double direction) { return nextafter_nid_postfix(value, direction); }
float __attribute__((sysv_abi)) nextafterf_nid_postfix(float value, float direction);
float nextafterf(float value, float direction) { return nextafterf_nid_postfix(value, direction); }
double tgamma(double value) { return static_cast<double>(AnyLibcxxGuest_tgammal(value)); }
float lgammaf(float value) { return static_cast<float>(lgamma_nid_postfix(value)); }
}
