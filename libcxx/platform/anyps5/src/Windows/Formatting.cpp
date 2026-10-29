#include "Runtime/FormatArguments.hpp"
#include <cstdio>
#include <cwchar>

extern "C" {
int __attribute__((sysv_abi)) vfprintf_nid_postfix(FILE* stream, const char* format, AnyLibcxx::GuestArguments* arguments);
int vfprintf(FILE* stream, const char* format, va_list arguments) {
    AnyLibcxx::FormatArguments<char> converted(format, arguments, false);
    return vfprintf_nid_postfix(stream, converted.GetFormat(), converted.GetArguments());
}
int fprintf(FILE* stream, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vfprintf(stream, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vsnprintf_nid_postfix(char* output, size_t size, const char* format, AnyLibcxx::GuestArguments* arguments);
int vsnprintf(char* output, size_t size, const char* format, va_list arguments) {
    AnyLibcxx::FormatArguments<char> converted(format, arguments, false);
    return vsnprintf_nid_postfix(output, size, converted.GetFormat(), converted.GetArguments());
}
int snprintf(char* output, size_t size, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vsnprintf(output, size, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vsprintf_nid_postfix(char* output, const char* format, AnyLibcxx::GuestArguments* arguments);
int vsprintf(char* output, const char* format, va_list arguments) {
    AnyLibcxx::FormatArguments<char> converted(format, arguments, false);
    return vsprintf_nid_postfix(output, converted.GetFormat(), converted.GetArguments());
}
int sprintf(char* output, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vsprintf(output, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vsscanf_nid_postfix(const char* input, const char* format, AnyLibcxx::GuestArguments* arguments);
int vsscanf(const char* input, const char* format, va_list arguments) {
    AnyLibcxx::FormatArguments<char> converted(format, arguments, true);
    return vsscanf_nid_postfix(input, converted.GetFormat(), converted.GetArguments());
}
int sscanf(const char* input, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vsscanf(input, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vfscanf_nid_postfix(FILE* stream, const char* format, AnyLibcxx::GuestArguments* arguments);
int vfscanf(FILE* stream, const char* format, va_list arguments) {
    AnyLibcxx::FormatArguments<char> converted(format, arguments, true);
    return vfscanf_nid_postfix(stream, converted.GetFormat(), converted.GetArguments());
}
int fscanf(FILE* stream, const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vfscanf(stream, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vswprintf_nid_postfix(wchar_t* output, size_t size, const wchar_t* format, AnyLibcxx::GuestArguments* arguments);
int vswprintf(wchar_t* output, size_t size, const wchar_t* format, va_list arguments) {
    AnyLibcxx::FormatArguments<wchar_t> converted(format, arguments, false);
    return vswprintf_nid_postfix(output, size, converted.GetFormat(), converted.GetArguments());
}
int swprintf(wchar_t* output, size_t size, const wchar_t* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vswprintf(output, size, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vfwprintf_nid_postfix(FILE* stream, const wchar_t* format, AnyLibcxx::GuestArguments* arguments);
int vfwprintf(FILE* stream, const wchar_t* format, va_list arguments) {
    AnyLibcxx::FormatArguments<wchar_t> converted(format, arguments, false);
    return vfwprintf_nid_postfix(stream, converted.GetFormat(), converted.GetArguments());
}
int fwprintf(FILE* stream, const wchar_t* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vfwprintf(stream, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vswscanf_nid_postfix(const wchar_t* input, const wchar_t* format, AnyLibcxx::GuestArguments* arguments);
int vswscanf(const wchar_t* input, const wchar_t* format, va_list arguments) {
    AnyLibcxx::FormatArguments<wchar_t> converted(format, arguments, true);
    return vswscanf_nid_postfix(input, converted.GetFormat(), converted.GetArguments());
}
int swscanf(const wchar_t* input, const wchar_t* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vswscanf(input, format, arguments);
    va_end(arguments);
    return result;
}
int __attribute__((sysv_abi)) vfwscanf_nid_postfix(FILE* stream, const wchar_t* format, AnyLibcxx::GuestArguments* arguments);
int vfwscanf(FILE* stream, const wchar_t* format, va_list arguments) {
    AnyLibcxx::FormatArguments<wchar_t> converted(format, arguments, true);
    return vfwscanf_nid_postfix(stream, converted.GetFormat(), converted.GetArguments());
}
int fwscanf(FILE* stream, const wchar_t* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vfwscanf(stream, format, arguments);
    va_end(arguments);
    return result;
}
int vprintf(const char* format, va_list arguments) { return vfprintf(stdout, format, arguments); }
int vscanf(const char* format, va_list arguments) { return vfscanf(stdin, format, arguments); }
int printf(const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vprintf(format, arguments);
    va_end(arguments);
    return result;
}
int scanf(const char* format, ...) {
    va_list arguments;
    va_start(arguments, format);
    const auto result = vscanf(format, arguments);
    va_end(arguments);
    return result;
}
}
