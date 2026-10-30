#include <cstdio>
#include <cstdlib>

extern "C" [[noreturn]] void AnyLibcxxAssertionFailed(const char* expression, const char* file, unsigned line, const char* function) {
    std::fprintf(stderr, "%s:%u: %s: assertion failed: %s\n", file, line, function, expression);
    std::abort();
}
