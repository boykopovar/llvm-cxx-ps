#ifndef ANYLIBCXX_ASSERT_H
#define ANYLIBCXX_ASSERT_H
#ifdef __cplusplus
extern "C" [[noreturn]] void AnyLibcxxAssertionFailed(const char* expression, const char* file, unsigned line, const char* function);
#else
_Noreturn void AnyLibcxxAssertionFailed(const char* expression, const char* file, unsigned line, const char* function);
#endif
#endif
#undef assert
#ifdef NDEBUG
#define assert(expression) ((void)0)
#else
#define assert(expression) ((expression) ? (void)0 : AnyLibcxxAssertionFailed(#expression, __FILE__, __LINE__, __func__))
#endif
