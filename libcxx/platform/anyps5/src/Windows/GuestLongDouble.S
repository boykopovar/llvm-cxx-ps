.text
.macro ANYLIBCXX_LONG_DOUBLE name, target, size, registers
.globl \name
\name:
.cfi_startproc
    push %rbx
.cfi_def_cfa_offset 16
.cfi_offset %rbx, -16
    mov %rdi, %rbx
.if \size
    sub $\size, %rsp
.cfi_def_cfa_offset 16 + \size
.set offset, 0
.rept \size / 8
    mov (\size + 16 + offset)(%rsp), %rax
    mov %rax, offset(%rsp)
.set offset, offset + 8
.endr
.endif
.if \registers > 0
    mov %rsi, %rdi
.endif
.if \registers > 1
    mov %rdx, %rsi
.endif
    call \target
    fstpt (%rbx)
    mov %rbx, %rax
.if \size
    add $\size, %rsp
.cfi_def_cfa_offset 16
.endif
    pop %rbx
.cfi_def_cfa_offset 8
.cfi_restore %rbx
    ret
.cfi_endproc
.endm

ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_acosl, acosl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_asinl, asinl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_atanl, atanl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_acoshl, acoshl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_asinhl, asinhl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_atanhl, atanhl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_cosl, cosl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_sinl, sinl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_tanl, tanl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_coshl, coshl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_sinhl, sinhl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_tanhl, tanhl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_expl, expl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_exp2l, exp2l_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_expm1l, expm1l_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_logl, logl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_log10l, log10l_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_log2l, log2l_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_log1pl, log1pl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_logbl, logbl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_sqrtl, sqrtl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_cbrtl, cbrtl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_erfl, erfl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_erfcl, erfcl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_ceill, ceill_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_floorl, floorl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_truncl, truncl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_roundl, roundl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_nearbyintl, nearbyintl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_rintl, rintl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_fabsl, fabsl_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_atan2l, atan2l_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_powl, powl_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_hypotl, hypotl_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_fmodl, fmodl_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_remainderl, remainderl_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_copysignl, copysignl_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_fdiml, fdiml_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_fmaxl, fmaxl_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_fminl, fminl_nid_postfix, 32, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_fmal, fmal_nid_postfix, 48, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_ldexpl, ldexpl_nid_postfix, 16, 1
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_scalbnl, scalbnl_nid_postfix, 16, 1
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_frexpl, frexpl_nid_postfix, 16, 1
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_modfl, modfl_nid_postfix, 16, 1
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_remquol, remquol_nid_postfix, 32, 1
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_nanl, nanl_nid_postfix, 0, 1
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_scalblnl, scalblnl_nid_postfix, 16, 1
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_lgammal, lgammal_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_tgammal, tgammal_nid_postfix, 16, 0
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_strtold, strtold_nid_postfix, 0, 2
ANYLIBCXX_LONG_DOUBLE AnyLibcxxGuest_wcstold, wcstold_nid_postfix, 0, 2
