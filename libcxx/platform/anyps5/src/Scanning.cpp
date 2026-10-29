#include <cstdarg>
#include <cstdio>

extern "C" {
int AnyLibcxxVsscanf(const char* input, const char* format, va_list arguments) __asm__("vsscanf");
int AnyLibcxxVfscanf(std::FILE* stream, const char* format, va_list arguments) __asm__("vfscanf");
int AnyLibcxxVscanf(const char* format, va_list arguments) __asm__("vscanf");

int __isoc99_vsscanf(const char* input, const char* format, va_list arguments) { return AnyLibcxxVsscanf(input, format, arguments); }
int __isoc99_vfscanf(std::FILE* stream, const char* format, va_list arguments) { return AnyLibcxxVfscanf(stream, format, arguments); }
int __isoc99_vscanf(const char* format, va_list arguments) { return AnyLibcxxVscanf(format, arguments); }

int __isoc99_sscanf(const char* input, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = AnyLibcxxVsscanf(input, format, arguments);
    va_end(arguments);
    return result;
}

int __isoc99_fscanf(std::FILE* stream, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = AnyLibcxxVfscanf(stream, format, arguments);
    va_end(arguments);
    return result;
}

int __isoc99_scanf(const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = AnyLibcxxVscanf(format, arguments);
    va_end(arguments);
    return result;
}
}
