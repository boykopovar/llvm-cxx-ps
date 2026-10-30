extern "C" {
[[noreturn]] void __attribute__((sysv_abi)) exit_nid_postfix(int status);
[[noreturn]] void __attribute__((sysv_abi)) quick_exit_nid_postfix(int status);
[[noreturn]] void __attribute__((sysv_abi)) _Exit_nid_postfix(int status);
[[noreturn]] void exit(int status) { exit_nid_postfix(status); }
[[noreturn]] void quick_exit(int status) { quick_exit_nid_postfix(status); }
[[noreturn]] void _Exit(int status) { _Exit_nid_postfix(status); }
[[noreturn]] void _exit(int status) { _Exit_nid_postfix(status); }
}
