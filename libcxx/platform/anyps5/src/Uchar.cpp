#include <uchar.h>

extern "C" {
int __attribute__((sysv_abi)) ___mb_cur_max_nid_postfix();
int AnyLibcxxMbCurMax() { return ___mb_cur_max_nid_postfix(); }
size_t __attribute__((sysv_abi)) mbrtoc16_nid_postfix(char16_t* target, const char* source, size_t count, mbstate_t* state);
size_t mbrtoc16(char16_t* target, const char* source, size_t count, mbstate_t* state) { static mbstate_t internal{}; return mbrtoc16_nid_postfix(target, source, count, state ? state : &internal); }
size_t __attribute__((sysv_abi)) c16rtomb_nid_postfix(char* target, char16_t value, mbstate_t* state);
size_t c16rtomb(char* target, char16_t value, mbstate_t* state) { static mbstate_t internal{}; return c16rtomb_nid_postfix(target, value, state ? state : &internal); }
size_t __attribute__((sysv_abi)) mbrtoc32_nid_postfix(char32_t* target, const char* source, size_t count, mbstate_t* state);
size_t mbrtoc32(char32_t* target, const char* source, size_t count, mbstate_t* state) { static mbstate_t internal{}; return mbrtoc32_nid_postfix(target, source, count, state ? state : &internal); }
size_t __attribute__((sysv_abi)) c32rtomb_nid_postfix(char* target, char32_t value, mbstate_t* state);
size_t c32rtomb(char* target, char32_t value, mbstate_t* state) { return c32rtomb_nid_postfix(target, value, state); }
}
