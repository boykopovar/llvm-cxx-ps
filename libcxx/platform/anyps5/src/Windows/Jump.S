.text
.globl setjmp
setjmp:
    mov %rbx, 0(%rcx)
    mov %rbp, 8(%rcx)
    mov %rsi, 16(%rcx)
    mov %rdi, 24(%rcx)
    lea 8(%rsp), %rax
    mov %rax, 32(%rcx)
    mov %r12, 40(%rcx)
    mov %r13, 48(%rcx)
    mov %r14, 56(%rcx)
    mov %r15, 64(%rcx)
    mov (%rsp), %rax
    mov %rax, 72(%rcx)
    stmxcsr 80(%rcx)
    fnstcw 84(%rcx)
    movdqu %xmm6, 96(%rcx)
    movdqu %xmm7, 112(%rcx)
    movdqu %xmm8, 128(%rcx)
    movdqu %xmm9, 144(%rcx)
    movdqu %xmm10, 160(%rcx)
    movdqu %xmm11, 176(%rcx)
    movdqu %xmm12, 192(%rcx)
    movdqu %xmm13, 208(%rcx)
    movdqu %xmm14, 224(%rcx)
    movdqu %xmm15, 240(%rcx)
    xor %eax, %eax
    ret

.globl longjmp
longjmp:
    mov %edx, %eax
    test %eax, %eax
    jne 1f
    inc %eax
1:
    mov 0(%rcx), %rbx
    mov 8(%rcx), %rbp
    mov 16(%rcx), %rsi
    mov 24(%rcx), %rdi
    mov 32(%rcx), %rsp
    mov 40(%rcx), %r12
    mov 48(%rcx), %r13
    mov 56(%rcx), %r14
    mov 64(%rcx), %r15
    ldmxcsr 80(%rcx)
    fldcw 84(%rcx)
    movdqu 96(%rcx), %xmm6
    movdqu 112(%rcx), %xmm7
    movdqu 128(%rcx), %xmm8
    movdqu 144(%rcx), %xmm9
    movdqu 160(%rcx), %xmm10
    movdqu 176(%rcx), %xmm11
    movdqu 192(%rcx), %xmm12
    movdqu 208(%rcx), %xmm13
    movdqu 224(%rcx), %xmm14
    movdqu 240(%rcx), %xmm15
    jmp *72(%rcx)
