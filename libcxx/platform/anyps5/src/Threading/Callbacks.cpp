#include "Threading/Callbacks.hpp"

namespace AnyLibcxx {

void* ANYLIBCXX_KERNEL_ABI ThreadEntry(void* argument) { return RunThread(argument); }
void ANYLIBCXX_KERNEL_ABI TlsDestructor(void* argument) { DestroyValue(argument); }

}

