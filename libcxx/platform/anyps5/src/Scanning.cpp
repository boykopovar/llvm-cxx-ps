#include <cstdarg>
#include <cstdio>
#include <cwchar>

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

int AnyLibcxxVswscanf(const wchar_t* input, const wchar_t* format, va_list arguments) __asm__("vswscanf");
int __isoc99_vswscanf(const wchar_t* input, const wchar_t* format, va_list arguments) { return AnyLibcxxVswscanf(input, format, arguments); }
int __isoc99_swscanf(const wchar_t* input, const wchar_t* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = AnyLibcxxVswscanf(input, format, arguments);
    va_end(arguments);
    return result;
}

int AnyLibcxxVfwscanf(std::FILE* stream, const wchar_t* format, va_list arguments) __asm__("vfwscanf");
int __isoc99_vfwscanf(std::FILE* stream, const wchar_t* format, va_list arguments) { return AnyLibcxxVfwscanf(stream, format, arguments); }
int __isoc99_fwscanf(std::FILE* stream, const wchar_t* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = AnyLibcxxVfwscanf(stream, format, arguments);
    va_end(arguments);
    return result;
}

int AnyLibcxxVwscanf(const wchar_t* format, va_list arguments) __asm__("vwscanf");
int __isoc99_vwscanf(const wchar_t* format, va_list arguments) { return AnyLibcxxVwscanf(format, arguments); }
int __isoc99_wscanf(const wchar_t* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = AnyLibcxxVwscanf(format, arguments);
    va_end(arguments);
    return result;
}
}
