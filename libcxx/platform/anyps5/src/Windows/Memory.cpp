#include <stddef.h>

extern "C" {
void* __attribute__((sysv_abi)) memcpy_nid_postfix(void* target, const void* source, size_t size);
void* memcpy(void* target, const void* source, size_t size) { return memcpy_nid_postfix(target, source, size); }
void* __attribute__((sysv_abi)) memmove_nid_postfix(void* target, const void* source, size_t size);
void* memmove(void* target, const void* source, size_t size) { return memmove_nid_postfix(target, source, size); }
void* __attribute__((sysv_abi)) memset_nid_postfix(void* target, int value, size_t size);
void* memset(void* target, int value, size_t size) { return memset_nid_postfix(target, value, size); }
int __attribute__((sysv_abi)) memcmp_nid_postfix(const void* left, const void* right, size_t size);
int memcmp(const void* left, const void* right, size_t size) { return memcmp_nid_postfix(left, right, size); }
void* __attribute__((sysv_abi)) memchr_nid_postfix(const void* source, int value, size_t size);
void* memchr(const void* source, int value, size_t size) { return memchr_nid_postfix(source, value, size); }
size_t __attribute__((sysv_abi)) strlen_nid_postfix(const char* value);
size_t strlen(const char* value) { return strlen_nid_postfix(value); }
int __attribute__((sysv_abi)) strcmp_nid_postfix(const char* left, const char* right);
int strcmp(const char* left, const char* right) { return strcmp_nid_postfix(left, right); }
int __attribute__((sysv_abi)) wcscmp_nid_postfix(const wchar_t* left, const wchar_t* right);
int wcscmp(const wchar_t* left, const wchar_t* right) { return wcscmp_nid_postfix(left, right); }
size_t __attribute__((sysv_abi)) wcslen_nid_postfix(const wchar_t* value);
size_t wcslen(const wchar_t* value) { return wcslen_nid_postfix(value); }
}
