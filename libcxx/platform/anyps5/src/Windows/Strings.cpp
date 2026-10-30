#include <stddef.h>

extern "C" {
char* __attribute__((sysv_abi)) strcpy_nid_postfix(char* target, const char* source);
char* strcpy(char* target, const char* source) { return strcpy_nid_postfix(target, source); }
char* __attribute__((sysv_abi)) strcat_nid_postfix(char* target, const char* source);
char* strcat(char* target, const char* source) { return strcat_nid_postfix(target, source); }
char* __attribute__((sysv_abi)) strncpy_nid_postfix(char* target, const char* source, size_t count);
char* strncpy(char* target, const char* source, size_t count) { return strncpy_nid_postfix(target, source, count); }
char* __attribute__((sysv_abi)) strncat_nid_postfix(char* target, const char* source, size_t count);
char* strncat(char* target, const char* source, size_t count) { return strncat_nid_postfix(target, source, count); }
int __attribute__((sysv_abi)) strncmp_nid_postfix(const char* left, const char* right, size_t count);
int strncmp(const char* left, const char* right, size_t count) { return strncmp_nid_postfix(left, right, count); }
int __attribute__((sysv_abi)) strcoll_nid_postfix(const char* left, const char* right);
int strcoll(const char* left, const char* right) { return strcoll_nid_postfix(left, right); }
char* __attribute__((sysv_abi)) strchr_nid_postfix(const char* value, int character);
char* strchr(const char* value, int character) { return strchr_nid_postfix(value, character); }
char* __attribute__((sysv_abi)) strrchr_nid_postfix(const char* value, int character);
char* strrchr(const char* value, int character) { return strrchr_nid_postfix(value, character); }
char* __attribute__((sysv_abi)) strstr_nid_postfix(const char* value, const char* characters);
char* strstr(const char* value, const char* characters) { return strstr_nid_postfix(value, characters); }
char* __attribute__((sysv_abi)) strpbrk_nid_postfix(const char* value, const char* characters);
char* strpbrk(const char* value, const char* characters) { return strpbrk_nid_postfix(value, characters); }
size_t __attribute__((sysv_abi)) strspn_nid_postfix(const char* value, const char* characters);
size_t strspn(const char* value, const char* characters) { return strspn_nid_postfix(value, characters); }
size_t __attribute__((sysv_abi)) strcspn_nid_postfix(const char* value, const char* characters);
size_t strcspn(const char* value, const char* characters) { return strcspn_nid_postfix(value, characters); }
size_t __attribute__((sysv_abi)) strxfrm_nid_postfix(char* target, const char* source, size_t count);
size_t strxfrm(char* target, const char* source, size_t count) { return strxfrm_nid_postfix(target, source, count); }
wchar_t* __attribute__((sysv_abi)) wcscpy_nid_postfix(wchar_t* target, const wchar_t* source);
wchar_t* wcscpy(wchar_t* target, const wchar_t* source) { return wcscpy_nid_postfix(target, source); }
wchar_t* __attribute__((sysv_abi)) wcscat_nid_postfix(wchar_t* target, const wchar_t* source);
wchar_t* wcscat(wchar_t* target, const wchar_t* source) { return wcscat_nid_postfix(target, source); }
wchar_t* __attribute__((sysv_abi)) wcsncpy_nid_postfix(wchar_t* target, const wchar_t* source, size_t count);
wchar_t* wcsncpy(wchar_t* target, const wchar_t* source, size_t count) { return wcsncpy_nid_postfix(target, source, count); }
wchar_t* __attribute__((sysv_abi)) wcsncat_nid_postfix(wchar_t* target, const wchar_t* source, size_t count);
wchar_t* wcsncat(wchar_t* target, const wchar_t* source, size_t count) { return wcsncat_nid_postfix(target, source, count); }
int __attribute__((sysv_abi)) wcsncmp_nid_postfix(const wchar_t* left, const wchar_t* right, size_t count);
int wcsncmp(const wchar_t* left, const wchar_t* right, size_t count) { return wcsncmp_nid_postfix(left, right, count); }
int __attribute__((sysv_abi)) wcscoll_nid_postfix(const wchar_t* left, const wchar_t* right);
int wcscoll(const wchar_t* left, const wchar_t* right) { return wcscoll_nid_postfix(left, right); }
wchar_t* __attribute__((sysv_abi)) wcschr_nid_postfix(const wchar_t* value, wchar_t character);
wchar_t* wcschr(const wchar_t* value, wchar_t character) { return wcschr_nid_postfix(value, character); }
wchar_t* __attribute__((sysv_abi)) wcsrchr_nid_postfix(const wchar_t* value, wchar_t character);
wchar_t* wcsrchr(const wchar_t* value, wchar_t character) { return wcsrchr_nid_postfix(value, character); }
wchar_t* __attribute__((sysv_abi)) wcsstr_nid_postfix(const wchar_t* value, const wchar_t* characters);
wchar_t* wcsstr(const wchar_t* value, const wchar_t* characters) { return wcsstr_nid_postfix(value, characters); }
wchar_t* __attribute__((sysv_abi)) wcspbrk_nid_postfix(const wchar_t* value, const wchar_t* characters);
wchar_t* wcspbrk(const wchar_t* value, const wchar_t* characters) { return wcspbrk_nid_postfix(value, characters); }
size_t __attribute__((sysv_abi)) wcsspn_nid_postfix(const wchar_t* value, const wchar_t* characters);
size_t wcsspn(const wchar_t* value, const wchar_t* characters) { return wcsspn_nid_postfix(value, characters); }
size_t __attribute__((sysv_abi)) wcscspn_nid_postfix(const wchar_t* value, const wchar_t* characters);
size_t wcscspn(const wchar_t* value, const wchar_t* characters) { return wcscspn_nid_postfix(value, characters); }
size_t __attribute__((sysv_abi)) wcsxfrm_nid_postfix(wchar_t* target, const wchar_t* source, size_t count);
size_t wcsxfrm(wchar_t* target, const wchar_t* source, size_t count) { return wcsxfrm_nid_postfix(target, source, count); }
char* __attribute__((sysv_abi)) strtok_nid_postfix(char* value, const char* delimiters);
char* strtok(char* value, const char* delimiters) { return strtok_nid_postfix(value, delimiters); }
wchar_t* __attribute__((sysv_abi)) wcstok_nid_postfix(wchar_t* value, const wchar_t* delimiters, wchar_t** state);
wchar_t* wcstok(wchar_t* value, const wchar_t* delimiters, wchar_t** state) { return wcstok_nid_postfix(value, delimiters, state); }
wchar_t* __attribute__((sysv_abi)) wmemcpy_nid_postfix(wchar_t* target, const wchar_t* source, size_t count);
wchar_t* wmemcpy(wchar_t* target, const wchar_t* source, size_t count) { return wmemcpy_nid_postfix(target, source, count); }
wchar_t* __attribute__((sysv_abi)) wmemmove_nid_postfix(wchar_t* target, const wchar_t* source, size_t count);
wchar_t* wmemmove(wchar_t* target, const wchar_t* source, size_t count) { return wmemmove_nid_postfix(target, source, count); }
wchar_t* __attribute__((sysv_abi)) wmemchr_nid_postfix(const wchar_t* value, wchar_t character, size_t count);
wchar_t* wmemchr(const wchar_t* value, wchar_t character, size_t count) { return wmemchr_nid_postfix(value, character, count); }
int __attribute__((sysv_abi)) wmemcmp_nid_postfix(const wchar_t* left, const wchar_t* right, size_t count);
int wmemcmp(const wchar_t* left, const wchar_t* right, size_t count) { return wmemcmp_nid_postfix(left, right, count); }
wchar_t* __attribute__((sysv_abi)) wmemset_nid_postfix(wchar_t* target, wchar_t value, size_t count);
wchar_t* wmemset(wchar_t* target, wchar_t value, size_t count) { return wmemset_nid_postfix(target, value, count); }
}
