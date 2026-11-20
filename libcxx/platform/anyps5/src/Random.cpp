#include "Runtime/Kernel.hpp"
#include <random>
#include <stdexcept>

extern "C" unsigned int ANYLIBCXX_KERNEL_ABI _ZSt14_Random_devicev_nid_postfix();

_LIBCPP_BEGIN_NAMESPACE_STD

random_device::random_device(const string& token) {
    if (token != "/dev/urandom") throw invalid_argument("Unsupported random device token");
}

random_device::~random_device() = default;

random_device::result_type random_device::operator()() {
    static_assert(sizeof(result_type) == 4);
    return _ZSt14_Random_devicev_nid_postfix();
}

double random_device::entropy() const noexcept {
    return 0;
}

_LIBCPP_END_NAMESPACE_STD
