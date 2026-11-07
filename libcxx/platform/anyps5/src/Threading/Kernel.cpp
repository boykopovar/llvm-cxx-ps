#include "Runtime/Kernel.hpp"

#include <cerrno>
#include <exception>

namespace AnyLibcxx {

int KernelError(int result) noexcept {
    if (result == 0) return 0;
    const auto value = static_cast<std::uint32_t>(result);
    if ((value & 0xffff0000u) != 0x80020000u) return result;

    return static_cast<int>(value & 0xffffu);
}

void RequireKernel(int result) noexcept {
    if (result != 0) std::terminate();
}

}

