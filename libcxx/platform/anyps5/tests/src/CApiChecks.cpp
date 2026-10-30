extern "C" __uint128_t __udivti3(__uint128_t, __uint128_t);
extern "C" __uint128_t __umodti3(__uint128_t, __uint128_t);
#include <algorithm>
#include <array>
#include <cerrno>
#include <csetjmp>
#include <cmath>
#include <complex>
#include <random>
#include <valarray>
#include <cfenv>
#include <clocale>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <limits>
#include <stdexcept>
#include <source_location>
#include <string>

namespace {
void require(bool value, std::source_location location = std::source_location::current()) { if (!value) throw std::runtime_error("C API check failed at line " + std::to_string(location.line())); }
int compare(const void* a, const void* b) {
    const auto left = *static_cast<const int*>(a);
    const auto right = *static_cast<const int*>(b);
    return (left > right) - (left < right);
}
template<typename TValue>
void math() {
    volatile TValue input = static_cast<TValue>(0.5);
    const auto x = input;
    require(std::abs(std::sin(x) * std::sin(x) + std::cos(x) * std::cos(x) - 1) < static_cast<TValue>(0.00001));
    require(std::abs(std::sqrt(x) * std::sqrt(x) - x) < static_cast<TValue>(0.00001));
    require(std::abs(std::log(std::exp(x)) - x) < static_cast<TValue>(0.00001));
    require(std::abs(std::pow(x, TValue{2}) - x * x) < static_cast<TValue>(0.00001));
    require(std::abs(std::atan(std::tan(x)) - x) < static_cast<TValue>(0.00001));
    require(std::abs(std::asinh(std::sinh(x)) - x) < static_cast<TValue>(0.00001));
    require(std::abs(std::erf(x) + std::erfc(x) - 1) < static_cast<TValue>(0.00001));
    require(std::hypot(TValue{3}, TValue{4}) == TValue{5});
    require(std::fma(TValue{2}, TValue{3}, TValue{4}) == TValue{10});
    int exponent = 0;
    require(std::frexp(TValue{8}, &exponent) == x && exponent == 4);
    TValue integral;
    require(std::modf(TValue{2} + x, &integral) == x && integral == TValue{2});
    require(std::lround(x) == 1 && std::llround(-x) == -1);
    require(std::nextafter(TValue{1}, TValue{2}) > TValue{1});
    require(std::nextafter(TValue{1}, TValue{0}) < TValue{1});
    require(std::nextafter(TValue{0}, TValue{1}) == std::numeric_limits<TValue>::denorm_min());
    require(std::isnan(std::nan("")));
}
}

void RunCApiChecks() {
    const __uint128_t numerator = (static_cast<__uint128_t>(1) << 100) + 23;
    require(__udivti3(numerator, 16) == (static_cast<__uint128_t>(1) << 96) + 1);
    require(__umodti3(numerator, 16) == 7);
    require(std::strtold("1.25", nullptr) == 1.25L);
    require(std::wcstold(L"1.25", nullptr) == 1.25L);
    std::jmp_buf environment;
    volatile int entered = 0;
    const int jumpResult = setjmp(environment);
    if (jumpResult == 0) {
        entered = 1;
        std::longjmp(environment, 42);
    }
    require(entered == 1 && jumpResult == 42);
    static_assert(sizeof(std::mbstate_t) == 16);
    require(std::setlocale(LC_ALL, "C") != nullptr);
    require(MB_CUR_MAX >= 1);
    errno = 0;
    char* end = nullptr;
    require(std::strtol("999999999999999999999999", &end, 10) == std::numeric_limits<long>::max() && errno == ERANGE && *end == 0);
    char formatted[96];
    require(std::snprintf(formatted, sizeof(formatted), "%ld %.2Lf %zu", -123L, 1.25L, std::size_t{42}) > 0);
    require(std::strcmp(formatted, "-123 1.25 42") == 0);
    long parsedLong;
    long double parsedReal;
    std::size_t parsedSize;
    require(std::sscanf(formatted, "%ld %Lf %zu", &parsedLong, &parsedReal, &parsedSize) == 3);
    require(parsedLong == -123 && parsedReal == 1.25L && parsedSize == 42);
#ifdef _WIN32
    bool rejected = false;
    try { std::fwide(nullptr, 0); } catch (const std::runtime_error&) { rejected = true; }
    require(rejected);
#endif
    math<float>();
    math<double>();
    math<long double>();
    require(std::nextafter(std::numeric_limits<long double>::infinity(), 0.0L) == std::numeric_limits<long double>::max());
    require(std::isinf(std::nextafter(std::numeric_limits<long double>::max(), std::numeric_limits<long double>::infinity())));
    require(std::nextafter(std::numeric_limits<long double>::min(), 0.0L) < std::numeric_limits<long double>::min());
    require(std::signbit(std::nextafter(0.0L, -0.0L)));
    require(std::nexttoward(1.0, 1.0L + std::numeric_limits<long double>::epsilon()) == std::nextafter(1.0, 2.0));
    const auto rotation = std::exp(std::complex<float>{0.0f, 1.5707963267948966f});
    require(std::abs(rotation.real()) < 0.00001f && std::abs(rotation.imag() - 1.0f) < 0.00001f);
    const std::valarray<float> roots = std::sqrt(std::valarray<float>{0.0f, 1.0f, 4.0f});
    require(roots[0] == 0.0f && roots[1] == 1.0f && roots[2] == 2.0f);
    std::mt19937 generator(123);
    std::normal_distribution<float> normal;
    std::gamma_distribution<double> gamma(3.0);
    std::uniform_real_distribution<long double> uniform(0.0L, 1.0L);
    for (int i = 0; i < 32; ++i) {
        require(std::isfinite(normal(generator)));
        const auto gammaValue = gamma(generator);
        require(std::isfinite(gammaValue) && gammaValue >= 0);
        const auto uniformValue = uniform(generator);
        require(uniformValue >= 0 && uniformValue < 1);
    }
    std::array<int, 7> values{7, 2, 5, 1, 6, 3, 4};
    std::qsort(values.data(), values.size(), sizeof(int), compare);
    require(std::is_sorted(values.begin(), values.end()));
    const int key = 4;
    require(std::bsearch(&key, values.data(), values.size(), sizeof(int), compare) == values.data() + 3);
    char text[32];
    std::strcpy(text, "abc");
    std::strcat(text, "def");
    require(std::strncmp(text, "abcdef", 6) == 0 && std::strstr(text, "cd") == text + 2);
    wchar_t wide[32];
    std::wcscpy(wide, L"Abc");
    std::wcscat(wide, L"def");
    require(std::wcsncmp(wide, L"Abcdef", 6) == 0);
    require(std::iswalpha(L'A') && std::towlower(L'A') == L'a');
    require(std::iswctype(L'9', std::wctype("digit")) != 0);
    struct StateGuard { unsigned long long Before = 0x123456789abcdef0ull; std::mbstate_t State{}; unsigned long long After = 0xfedcba9876543210ull; } state;
    require(std::mbrtowc(wide, "A", 1, &state.State) == 1 && wide[0] == L'A');
    require(std::mbsinit(&state.State) && state.Before == 0x123456789abcdef0ull && state.After == 0xfedcba9876543210ull);
    require(std::wcrtomb(text, L'A', &state.State) == 1 && text[0] == 'A');
    char32_t codepoint;
    require(std::mbrtoc32(&codepoint, "Z", 1, &state.State) == 1 && codepoint == U'Z');
    require(std::c32rtomb(text, U'Z', &state.State) == 1 && text[0] == 'Z');
    require(state.Before == 0x123456789abcdef0ull && state.After == 0xfedcba9876543210ull);
    require(std::mbrtoc16(nullptr, "", 1, nullptr) == 0);
    require(std::mbrtoc32(nullptr, "", 1, nullptr) == 0);
    require(std::c16rtomb(text, u'A', nullptr) == 1 && text[0] == 'A');
    state.State = {};
    errno = 0;
    require(std::mbrtoc32(&codepoint, "\x80", 1, &state.State) == static_cast<std::size_t>(-1));
    require(errno == EILSEQ);
    const auto* locale = std::localeconv();
    require(locale && locale->decimal_point && std::strcmp(locale->decimal_point, ".") == 0);
    std::fenv_t saved;
    require(std::fegetenv(&saved) == 0);
    for (const auto mode : {FE_TONEAREST, FE_DOWNWARD, FE_UPWARD, FE_TOWARDZERO}) {
        require(std::fesetround(mode) == 0 && std::fegetround() == mode);
    }
    require(std::feclearexcept(FE_ALL_EXCEPT) == 0);
    require(std::feraiseexcept(FE_INVALID) == 0 && (std::fetestexcept(FE_INVALID) & FE_INVALID) != 0);
    std::fexcept_t flags;
    require(std::fegetexceptflag(&flags, FE_ALL_EXCEPT) == 0);
    require(std::feclearexcept(FE_ALL_EXCEPT) == 0 && std::fesetexceptflag(&flags, FE_ALL_EXCEPT) == 0);
    require((std::fetestexcept(FE_INVALID) & FE_INVALID) != 0);
    require(std::fesetenv(&saved) == 0);
    static_assert(sizeof(std::tm) == 56 && sizeof(std::time_t) == 8);
    std::time_t epoch = 0;
    const auto* utc = std::gmtime(&epoch);
    require(utc && utc->tm_year == 70 && utc->tm_mon == 0 && utc->tm_mday == 1);
    require(std::difftime(25, 7) == 18);
    require(std::time(nullptr) > 0);
    auto* file = std::fopen("anylibcxx-abi-check.tmp", "w+b");
    require(file != nullptr);
    require(std::fputs("abc\n", file) >= 0);
    std::fpos_t position;
    require(std::fgetpos(file, &position) == 0);
    std::rewind(file);
    require(std::fgets(text, sizeof(text), file) == text && std::strcmp(text, "abc\n") == 0);
    require(std::fsetpos(file, &position) == 0);
    require(std::fclose(file) == 0 && std::remove("anylibcxx-abi-check.tmp") == 0);
}
