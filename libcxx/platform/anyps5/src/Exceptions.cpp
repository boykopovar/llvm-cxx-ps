#include "Exceptions.hpp"
#include <cxxabi.h>
#include <cstring>
#include <exception>
#include <limits>

using namespace __cxxabiv1;
#define HAVE_DEPENDENT_EH_ABI 1
#include "support/runtime/exception_pointer_cxxabi.ipp"

namespace std {

int uncaught_exceptions() noexcept {
    unsigned int count = 0;
    const auto* globals = reinterpret_cast<const unsigned char*>(__cxa_get_globals());
    if (globals == nullptr) std::terminate();
    std::memcpy(&count, globals + sizeof(void*), sizeof(count));
    if (count > static_cast<unsigned int>(std::numeric_limits<int>::max())) std::terminate();
    return static_cast<int>(count);
}

}

#ifdef _WIN32
#include <atomic>
#include <new>
namespace {
std::atomic<std::new_handler> newHandler{nullptr};
}
namespace std {
new_handler get_new_handler() noexcept { return newHandler.load(); }
new_handler set_new_handler(new_handler handler) noexcept { return newHandler.exchange(handler); }
}
#endif
