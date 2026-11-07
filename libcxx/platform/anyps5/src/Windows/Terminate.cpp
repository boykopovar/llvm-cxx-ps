#include <exception>

extern "C" {
std::terminate_handler __attribute__((sysv_abi)) _ZSt13set_terminatePFvvE_nid_postfix(std::terminate_handler handler);
std::terminate_handler __attribute__((sysv_abi)) _ZSt13get_terminatev_nid_postfix();
}

namespace std {

terminate_handler set_terminate(terminate_handler handler) noexcept { return _ZSt13set_terminatePFvvE_nid_postfix(handler); }
terminate_handler get_terminate() noexcept { return _ZSt13get_terminatev_nid_postfix(); }

}

