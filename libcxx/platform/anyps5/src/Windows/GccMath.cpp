#include <stdexcept>

extern "C" {
double __attribute__((sysv_abi)) sin_nid_postfix(double value);
double __attribute__((sysv_abi)) cos_nid_postfix(double value);
float __attribute__((sysv_abi)) sinf_nid_postfix(float value);
float __attribute__((sysv_abi)) cosf_nid_postfix(float value);
long double __attribute__((sysv_abi)) AnyLibcxxGuest_sinl(long double value);
long double __attribute__((sysv_abi)) AnyLibcxxGuest_cosl(long double value);
void sincos(double value, double* sine, double* cosine) {
    if (sine == nullptr || cosine == nullptr) throw std::invalid_argument("Null sincos output");
    *sine = sin_nid_postfix(value);
    *cosine = cos_nid_postfix(value);
}
void sincosf(float value, float* sine, float* cosine) {
    if (sine == nullptr || cosine == nullptr) throw std::invalid_argument("Null sincosf output");
    *sine = sinf_nid_postfix(value);
    *cosine = cosf_nid_postfix(value);
}
void sincosl(long double value, long double* sine, long double* cosine) {
    if (sine == nullptr || cosine == nullptr) throw std::invalid_argument("Null sincosl output");
    *sine = AnyLibcxxGuest_sinl(value);
    *cosine = AnyLibcxxGuest_cosl(value);
}
}
