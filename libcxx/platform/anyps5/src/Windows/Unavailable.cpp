#include <cstdio>
#include <cwchar>
#include <csignal>
#include <stdexcept>

extern "C" {
FILE* tmpfile() { throw std::runtime_error("tmpfile is not provided by guest libc"); }
char* tmpnam(char*) { throw std::runtime_error("tmpnam is not provided by guest libc"); }
int fwide(FILE*, int) { throw std::runtime_error("fwide is not provided by guest libc"); }
int system(const char*) { throw std::runtime_error("system requires libkernel"); }
int raise(int) { throw std::runtime_error("raise requires libkernel"); }
void (*signal(int, void (*)(int)))(int) { throw std::runtime_error("signal requires libkernel"); }
}
