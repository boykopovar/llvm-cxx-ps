.text
.globl AnyLibcxxSetEnvironment
AnyLibcxxSetEnvironment:
#ifdef _WIN32
    fldenv (%rcx)
    ldmxcsr 28(%rcx)
#else
    fldenv (%rdi)
    ldmxcsr 28(%rdi)
#endif
    xor %eax, %eax
    ret

#ifndef _WIN32
.section .note.GNU-stack,"",@progbits
#endif
