.text
.globl __gxx_personality_seh0
__gxx_personality_seh0:
    jmp _ZSt9terminatev
.globl __gcc_personality_seh0
__gcc_personality_seh0:
    jmp _ZSt9terminatev
.section .sehgcc,"dr"
.balign 8
.globl AnyLibcxxSehPersonalities
AnyLibcxxSehPersonalities:
.quad __gxx_personality_seh0
.quad __gcc_personality_seh0
