#include <stddef.h>
#include <stdexcept>
#include <climits>
#include <cerrno>
#include <stdio.h>
#include <wchar.h>
#undef getwc
#undef putwc

extern "C" {
FILE* __attribute__((sysv_abi)) fopen_nid_postfix(const char* path, const char* mode);
FILE* fopen(const char* path, const char* mode) { return fopen_nid_postfix(path, mode); }
FILE* __attribute__((sysv_abi)) freopen_nid_postfix(const char* path, const char* mode, FILE* stream);
FILE* freopen(const char* path, const char* mode, FILE* stream) { return freopen_nid_postfix(path, mode, stream); }
int __attribute__((sysv_abi)) fclose_nid_postfix(FILE* stream);
int fclose(FILE* stream) { return fclose_nid_postfix(stream); }
int __attribute__((sysv_abi)) fflush_nid_postfix(FILE* stream);
int fflush(FILE* stream) { return fflush_nid_postfix(stream); }
size_t __attribute__((sysv_abi)) fread_nid_postfix(void* data, size_t size, size_t count, FILE* stream);
size_t fread(void* data, size_t size, size_t count, FILE* stream) { return fread_nid_postfix(data, size, count, stream); }
size_t __attribute__((sysv_abi)) fwrite_nid_postfix(const void* data, size_t size, size_t count, FILE* stream);
size_t fwrite(const void* data, size_t size, size_t count, FILE* stream) { return fwrite_nid_postfix(data, size, count, stream); }
int __attribute__((sysv_abi)) getc_nid_postfix(FILE* stream);
int getc(FILE* stream) { return getc_nid_postfix(stream); }
int __attribute__((sysv_abi)) fgetc_nid_postfix(FILE* stream);
int fgetc(FILE* stream) { return fgetc_nid_postfix(stream); }
int __attribute__((sysv_abi)) fputc_nid_postfix(int value, FILE* stream);
int fputc(int value, FILE* stream) { return fputc_nid_postfix(value, stream); }
int __attribute__((sysv_abi)) fputs_nid_postfix(const char* value, FILE* stream);
int fputs(const char* value, FILE* stream) { return fputs_nid_postfix(value, stream); }
int __attribute__((sysv_abi)) ungetc_nid_postfix(int value, FILE* stream);
int ungetc(int value, FILE* stream) { return ungetc_nid_postfix(value, stream); }
int __attribute__((sysv_abi)) fgetwc_nid_postfix(FILE* stream);
wint_t fgetwc(FILE* stream) { return fgetwc_nid_postfix(stream); }
int __attribute__((sysv_abi)) fputwc_nid_postfix(wchar_t value, FILE* stream);
wint_t fputwc(wchar_t value, FILE* stream) { return fputwc_nid_postfix(value, stream); }
int __attribute__((sysv_abi)) ungetwc_nid_postfix(unsigned int value, FILE* stream);
wint_t ungetwc(wint_t value, FILE* stream) { return ungetwc_nid_postfix(value == WEOF ? -1 : value, stream); }
void __attribute__((sysv_abi)) setbuf_nid_postfix(FILE* stream, char* buffer);
void setbuf(FILE* stream, char* buffer) { return setbuf_nid_postfix(stream, buffer); }
int __attribute__((sysv_abi)) setvbuf_nid_postfix(FILE* stream, char* buffer, int mode, size_t size);
int setvbuf(FILE* stream, char* buffer, int mode, size_t size) { return setvbuf_nid_postfix(stream, buffer, mode, size); }
int __attribute__((sysv_abi)) remove_nid_postfix(const char* path);
int remove(const char* path) { return remove_nid_postfix(path); }
int __attribute__((sysv_abi)) rename_nid_postfix(const char* oldPath, const char* newPath);
int rename(const char* oldPath, const char* newPath) { return rename_nid_postfix(oldPath, newPath); }
int __attribute__((sysv_abi)) feof_nid_postfix(FILE* stream);
int feof(FILE* stream) { return feof_nid_postfix(stream); }
int __attribute__((sysv_abi)) ferror_nid_postfix(FILE* stream);
int ferror(FILE* stream) { return ferror_nid_postfix(stream); }
void __attribute__((sysv_abi)) clearerr_nid_postfix(FILE* stream);
void clearerr(FILE* stream) { return clearerr_nid_postfix(stream); }

__declspec(dllimport) extern FILE* __stdinp_nid_postfix;
__declspec(dllimport) extern FILE* __stdoutp_nid_postfix;
__declspec(dllimport) extern FILE* __stderrp_nid_postfix;
FILE* __acrt_iob_func(unsigned index) {
    if (index == 0) return __stdinp_nid_postfix;
    if (index == 1) return __stdoutp_nid_postfix;
    if (index == 2) return __stderrp_nid_postfix;
    throw std::invalid_argument("Invalid standard stream");
}
int __attribute__((sysv_abi)) fseeko_nid_postfix(FILE* stream, long long offset, int origin);
long long __attribute__((sysv_abi)) ftello_nid_postfix(FILE* stream);
int fseeko(FILE* stream, long long offset, int origin) { return fseeko_nid_postfix(stream, offset, origin); }
long long ftello(FILE* stream) { return ftello_nid_postfix(stream); }
int fseek(FILE* stream, long offset, int origin) { return fseeko_nid_postfix(stream, offset, origin); }
long ftell(FILE* stream) {
    const auto result = ftello_nid_postfix(stream);
    if (result > LONG_MAX) { errno = ERANGE; return -1; }
    return static_cast<long>(result);
}
int __attribute__((sysv_abi)) fileno_nid_postfix(FILE* stream);
int fileno(FILE* stream) { return fileno_nid_postfix(stream); }
int __attribute__((sysv_abi)) fgetpos_nid_postfix(FILE* stream, long long* position);
int fgetpos(FILE* stream, fpos_t* position) { return fgetpos_nid_postfix(stream, position); }
int __attribute__((sysv_abi)) fsetpos_nid_postfix(FILE* stream, const long long* position);
int fsetpos(FILE* stream, const fpos_t* position) { return fsetpos_nid_postfix(stream, position); }
void __attribute__((sysv_abi)) rewind_nid_postfix(FILE* stream);
void rewind(FILE* stream) { rewind_nid_postfix(stream); }
char* __attribute__((sysv_abi)) fgets_nid_postfix(char* target, int capacity, FILE* stream);
char* fgets(char* target, int capacity, FILE* stream) { return fgets_nid_postfix(target, capacity, stream); }
wchar_t* __attribute__((sysv_abi)) fgetws_nid_postfix(wchar_t* target, int capacity, FILE* stream);
wchar_t* fgetws(wchar_t* target, int capacity, FILE* stream) { return fgetws_nid_postfix(target, capacity, stream); }
int __attribute__((sysv_abi)) fputws_nid_postfix(const wchar_t* value, FILE* stream);
int fputws(const wchar_t* value, FILE* stream) { return fputws_nid_postfix(value, stream); }
int __attribute__((sysv_abi)) puts_nid_postfix(const char* value);
int puts(const char* value) { return puts_nid_postfix(value); }
void __attribute__((sysv_abi)) perror_nid_postfix(const char* prefix);
void perror(const char* prefix) { perror_nid_postfix(prefix); }
int getchar() { return fgetc(stdin); }
int putchar(int value) { return fputc(value, stdout); }
int putc(int value, FILE* stream) { return fputc(value, stream); }
wint_t getwc(FILE* stream) { return fgetwc(stream); }
wint_t putwc(wchar_t value, FILE* stream) { return fputwc(value, stream); }
}
