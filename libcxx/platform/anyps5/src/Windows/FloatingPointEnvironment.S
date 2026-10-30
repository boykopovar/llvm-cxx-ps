.text
.globl AnyLibcxxSetEnvironment
AnyLibcxxSetEnvironment:
    fldenv (%rcx)
    ldmxcsr 28(%rcx)
    xor %eax, %eax
    ret
