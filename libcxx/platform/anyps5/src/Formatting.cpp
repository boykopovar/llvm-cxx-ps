#include <__format/parser_std_format_spec.h>
#include <string>

_LIBCPP_BEGIN_NAMESPACE_STD

namespace __format_spec {

[[noreturn]] void __throw_invalid_option_format_error(const char* id, const char* option) {
    string message("The format specifier for ");
    message.append(id);
    message.append(" does not allow the ");
    message.append(option);
    message.append(" option");
    std::__throw_format_error(message.c_str());
}

[[noreturn]] void __throw_invalid_type_format_error(const char* id) {
    string message("The type option contains an invalid value for ");
    message.append(id);
    message.append(" formatting argument");
    std::__throw_format_error(message.c_str());
}

}

_LIBCPP_END_NAMESPACE_STD

