#include "Runtime/Error.hpp"
#include "Runtime/Kernel.hpp"

#include <cerrno>
#include <cstddef>
#include <stdexcept>
#include <vector>

extern "C" int ANYLIBCXX_KERNEL_ABI strerror_r_nid_postfix(int error, char* buffer, std::size_t size);

namespace AnyLibcxx {

std::string ErrorMessage(int error) {
    struct ErrnoGuard {
        int Value = errno;
        ~ErrnoGuard() { errno = Value; }
    } guard;

    std::vector<char> buffer(128);
    for (;;) {
        const auto result = strerror_r_nid_postfix(error, buffer.data(), buffer.size());
        if (result == 0) return buffer.data();
        if (result == EINVAL) return "Unknown error " + std::to_string(error);
        if (result != ERANGE) throw std::runtime_error("strerror_r failed");
        if (buffer.size() > buffer.max_size() / 2) throw std::length_error("Error message exceeds string capacity");
        buffer.resize(buffer.size() * 2);
    }
}

}

