#ifndef ANYLIBCXX_RUNTIME_KERNEL_HPP
#define ANYLIBCXX_RUNTIME_KERNEL_HPP

#include <cstdint>

#define ANYLIBCXX_KERNEL_ABI __attribute__((sysv_abi))

namespace AnyLibcxx {

struct KernelTimespec {
    std::int64_t Seconds;
    std::int64_t Nanoseconds;
};

using KernelThreadEntry = void* (ANYLIBCXX_KERNEL_ABI*)(void*);
using KernelDestructor = void (ANYLIBCXX_KERNEL_ABI*)(void*);

int KernelError(int result) noexcept;
void RequireKernel(int result) noexcept;

}

extern "C" {

int ANYLIBCXX_KERNEL_ABI scePthreadMutexInit(void** mutex, void* const* attributes, const char* name);
int ANYLIBCXX_KERNEL_ABI scePthreadMutexDestroy(void** mutex);
int ANYLIBCXX_KERNEL_ABI scePthreadMutexLock(void** mutex);
int ANYLIBCXX_KERNEL_ABI scePthreadMutexTrylock(void** mutex);
int ANYLIBCXX_KERNEL_ABI scePthreadMutexUnlock(void** mutex);
int ANYLIBCXX_KERNEL_ABI scePthreadMutexattrInit(void** attributes);
int ANYLIBCXX_KERNEL_ABI scePthreadMutexattrDestroy(void** attributes);
int ANYLIBCXX_KERNEL_ABI scePthreadMutexattrSettype(void** attributes, int type);
int ANYLIBCXX_KERNEL_ABI scePthreadCondInit(void** condition, void* const* attributes, const char* name);
int ANYLIBCXX_KERNEL_ABI scePthreadCondDestroy(void** condition);
int ANYLIBCXX_KERNEL_ABI scePthreadCondSignal(void** condition);
int ANYLIBCXX_KERNEL_ABI scePthreadCondBroadcast(void** condition);
int ANYLIBCXX_KERNEL_ABI scePthreadCondWait(void** condition, void** mutex);
int ANYLIBCXX_KERNEL_ABI scePthreadCondTimedwait(void** condition, void** mutex, unsigned int microseconds);
int ANYLIBCXX_KERNEL_ABI scePthreadCreate(void** thread, void* const* attributes, AnyLibcxx::KernelThreadEntry entry, void* argument, const char* name);
int ANYLIBCXX_KERNEL_ABI scePthreadJoin(void* thread, void** result);
int ANYLIBCXX_KERNEL_ABI scePthreadDetach(void* thread);
void* ANYLIBCXX_KERNEL_ABI scePthreadSelf();
void ANYLIBCXX_KERNEL_ABI scePthreadYield();
int ANYLIBCXX_KERNEL_ABI scePthreadGetaffinity(void* thread, std::uint64_t* mask);
int ANYLIBCXX_KERNEL_ABI scePthreadKeyCreate(int* key, AnyLibcxx::KernelDestructor destructor);
int ANYLIBCXX_KERNEL_ABI scePthreadKeyDelete(int key);
void* ANYLIBCXX_KERNEL_ABI scePthreadGetspecific(int key);
int ANYLIBCXX_KERNEL_ABI scePthreadSetspecific(int key, void* value);
int ANYLIBCXX_KERNEL_ABI sceKernelClockGettime(int clock, AnyLibcxx::KernelTimespec* value);
int ANYLIBCXX_KERNEL_ABI sceKernelNanosleep(const AnyLibcxx::KernelTimespec* requested, AnyLibcxx::KernelTimespec* remaining);

}

#endif

