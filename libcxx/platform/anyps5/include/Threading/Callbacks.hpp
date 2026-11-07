#ifndef ANYLIBCXX_THREADING_CALLBACKS_HPP
#define ANYLIBCXX_THREADING_CALLBACKS_HPP

#include "Runtime/Kernel.hpp"

namespace AnyLibcxx {

void* RunThread(void* argument) noexcept;
void DestroyValue(void* argument) noexcept;
void* ANYLIBCXX_KERNEL_ABI ThreadEntry(void* argument);
void ANYLIBCXX_KERNEL_ABI TlsDestructor(void* argument);

}

#endif

