#define __CRT__NO_INLINE 1
#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>
#include <inttypes.h>

extern "C" {
int __attribute__((sysv_abi)) rand_nid_postfix();
int rand() { return rand_nid_postfix(); }
void __attribute__((sysv_abi)) srand_nid_postfix(unsigned int seed);
void srand(unsigned int seed) { srand_nid_postfix(seed); }
char* __attribute__((sysv_abi)) getenv_nid_postfix(const char* name);
char* getenv(const char* name) { return getenv_nid_postfix(name); }
int atoi(const char* value) { return static_cast<int>(strtol(value, nullptr, 10)); }
long atol(const char* value) { return strtol(value, nullptr, 10); }
long long atoll(const char* value) { return strtoll(value, nullptr, 10); }
double atof(const char* value) { return strtod(value, nullptr); }
int abs(int value) { return value < 0 ? -value : value; }
long labs(long value) { return value < 0 ? -value : value; }
long long llabs(long long value) { return value < 0 ? -value : value; }
intmax_t imaxabs(intmax_t value) { return value < 0 ? -value : value; }
div_t div(int numerator, int denominator) { return {numerator / denominator, numerator % denominator}; }
ldiv_t ldiv(long numerator, long denominator) { return {numerator / denominator, numerator % denominator}; }
lldiv_t lldiv(long long numerator, long long denominator) { return {numerator / denominator, numerator % denominator}; }
imaxdiv_t imaxdiv(intmax_t numerator, intmax_t denominator) { return {numerator / denominator, numerator % denominator}; }
intmax_t strtoimax(const char* value, char** end, int base) { return strtoll(value, end, base); }
uintmax_t strtoumax(const char* value, char** end, int base) { return strtoull(value, end, base); }
intmax_t wcstoimax(const wchar_t* value, wchar_t** end, int base) { return wcstoll(value, end, base); }
uintmax_t wcstoumax(const wchar_t* value, wchar_t** end, int base) { return wcstoull(value, end, base); }
}
