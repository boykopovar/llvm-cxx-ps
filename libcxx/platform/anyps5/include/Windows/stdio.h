#ifndef ANYLIBCXX_WINDOWS_STDIO_H
#define ANYLIBCXX_WINDOWS_STDIO_H
#include <stddef.h>
#include <stdarg.h>
#ifndef _FILE_DEFINED
#define _FILE_DEFINED
struct _iobuf;
typedef struct _iobuf FILE;
#endif
#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
typedef long long fpos_t;
#endif
#define EOF (-1)
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define BUFSIZ 8192
#define FILENAME_MAX 1024
#define FOPEN_MAX 20
#define L_tmpnam 1024
#define TMP_MAX 32767
#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2
#ifdef __cplusplus
extern "C" {
#endif
#undef stdin
#undef stdout
#undef stderr
FILE* __acrt_iob_func(unsigned);
#define stdin (__acrt_iob_func(0))
#define stdout (__acrt_iob_func(1))
#define stderr (__acrt_iob_func(2))
FILE* fopen(const char*, const char*);
FILE* freopen(const char*, const char*, FILE*);
FILE* tmpfile(void);
char* tmpnam(char*);
int remove(const char*);
int rename(const char*, const char*);
int fclose(FILE*);
int fflush(FILE*);
int fgetc(FILE*);
int getc(FILE*);
int getchar(void);
int fputc(int, FILE*);
int putc(int, FILE*);
int putchar(int);
int puts(const char*);
int fputs(const char*, FILE*);
char* fgets(char*, int, FILE*);
int ungetc(int, FILE*);
size_t fread(void*, size_t, size_t, FILE*);
size_t fwrite(const void*, size_t, size_t, FILE*);
int feof(FILE*);
int ferror(FILE*);
void clearerr(FILE*);
int fseek(FILE*, long, int);
long ftell(FILE*);
void rewind(FILE*);
int fgetpos(FILE*, fpos_t*);
int fsetpos(FILE*, const fpos_t*);
int setvbuf(FILE*, char*, int, size_t);
void setbuf(FILE*, char*);
void perror(const char*);
int printf(const char*, ...);
int fprintf(FILE*, const char*, ...);
int sprintf(char*, const char*, ...);
int snprintf(char*, size_t, const char*, ...);
int scanf(const char*, ...);
int fscanf(FILE*, const char*, ...);
int sscanf(const char*, const char*, ...);
int vprintf(const char*, va_list);
int vfprintf(FILE*, const char*, va_list);
int vsprintf(char*, const char*, va_list);
int vsnprintf(char*, size_t, const char*, va_list);
int vscanf(const char*, va_list);
int vfscanf(FILE*, const char*, va_list);
int vsscanf(const char*, const char*, va_list);
int fseeko(FILE*, long long, int);
long long ftello(FILE*);
FILE* fdopen(int, const char*);
int fileno(FILE*);
#ifdef __cplusplus
}
#endif
#endif
