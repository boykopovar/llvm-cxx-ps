#include <setjmp.h>

namespace {
void jump(jmp_buf environment, int value) { longjmp(environment, value); }
bool check(int requested) {
    jmp_buf environment;
    volatile int entered = 0;
    volatile int preserved = 123;
    const int value = setjmp(environment);
    if (value == 0) {
        entered = 1;
        jump(environment, requested);
    }
    return entered == 1 && preserved == 123 && value == (requested == 0 ? 1 : requested);
}
}

int main() { return check(0) && check(1) && check(42) && check(-7) ? 0 : 1; }
