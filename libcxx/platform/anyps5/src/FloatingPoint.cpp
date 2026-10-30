#include <fenv.h>
#include <stdexcept>

static_assert(sizeof(fenv_t) == 32);

extern "C" {
const fenv_t AnyLibcxxDefaultEnvironment{0xffff037fu, 0xffff0000u, 0xffffffffu, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xff, 0xff}, 0x1f80u};
int __attribute__((sysv_abi)) feclearexcept_nid_postfix(int exceptions);
int feclearexcept(int exceptions) { return feclearexcept_nid_postfix(exceptions); }
int __attribute__((sysv_abi)) fegetexceptflag_nid_postfix(fexcept_t* flags, int exceptions);
int fegetexceptflag(fexcept_t* flags, int exceptions) { return fegetexceptflag_nid_postfix(flags, exceptions); }
int __attribute__((sysv_abi)) feraiseexcept_nid_postfix(int exceptions);
int feraiseexcept(int exceptions) { return feraiseexcept_nid_postfix(exceptions); }
int __attribute__((sysv_abi)) fesetexceptflag_nid_postfix(const fexcept_t* flags, int exceptions);
int fesetexceptflag(const fexcept_t* flags, int exceptions) { return fesetexceptflag_nid_postfix(flags, exceptions); }
int __attribute__((sysv_abi)) fetestexcept_nid_postfix(int exceptions);
int fetestexcept(int exceptions) { return fetestexcept_nid_postfix(exceptions); }
int __attribute__((sysv_abi)) fegetround_nid_postfix();
int fegetround() { return fegetround_nid_postfix(); }
int __attribute__((sysv_abi)) fesetround_nid_postfix(int rounding);
int fesetround(int rounding) { return fesetround_nid_postfix(rounding); }
int __attribute__((sysv_abi)) fegetenv_nid_postfix(fenv_t* environment);
int fegetenv(fenv_t* environment) { return fegetenv_nid_postfix(environment); }
int __attribute__((sysv_abi)) feupdateenv_nid_postfix(const fenv_t* environment);
int feupdateenv(const fenv_t* environment) { return feupdateenv_nid_postfix(environment); }
int __attribute__((sysv_abi)) feholdexcept_nid_postfix(fenv_t* environment);
int feholdexcept(fenv_t* environment) { return feholdexcept_nid_postfix(environment); }
int AnyLibcxxSetEnvironment(const fenv_t* environment);
int fesetenv(const fenv_t* environment) {
    if (!environment) throw std::invalid_argument("Null floating point environment");
    return AnyLibcxxSetEnvironment(environment);
}
}
