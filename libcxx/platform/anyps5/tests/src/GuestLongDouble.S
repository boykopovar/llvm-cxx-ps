.text
.macro ANYLIBCXX_TEST_LONG_DOUBLE name, count, integer
.globl \name
\name:
.if \count > 0
    fldt 8(%rsp)
    fldl AnyLibcxxTwo(%rip)
    fucomip %st(1), %st
    fstp %st(0)
    je 1f
    incl AnyLibcxxMathFailures(%rip)
1:
.endif
.if \count > 1
    fldt 24(%rsp)
    fldl AnyLibcxxThree(%rip)
    fucomip %st(1), %st
    fstp %st(0)
    je 2f
    incl AnyLibcxxMathFailures(%rip)
2:
.endif
.if \count > 2
    fldt 40(%rsp)
    fldl AnyLibcxxFour(%rip)
    fucomip %st(1), %st
    fstp %st(0)
    je 3f
    incl AnyLibcxxMathFailures(%rip)
3:
.endif
.if \integer >= 0
    cmp $\integer, %rdi
    je 4f
    incl AnyLibcxxMathFailures(%rip)
4:
.endif
    sub $8, %rsp
    call ClobberVolatileRegisters
    add $8, %rsp
    fldl AnyLibcxxSeven(%rip)
    ret
.endm

ANYLIBCXX_TEST_LONG_DOUBLE acosl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE asinl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE atanl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE acoshl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE asinhl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE atanhl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE cosl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE sinl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE tanl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE coshl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE sinhl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE tanhl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE expl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE exp2l_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE expm1l_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE logl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE log10l_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE log2l_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE log1pl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE logbl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE sqrtl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE cbrtl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE erfl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE erfcl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE ceill_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE floorl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE truncl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE roundl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE nearbyintl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE rintl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE fabsl_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE atan2l_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE powl_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE hypotl_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE fmodl_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE remainderl_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE copysignl_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE fdiml_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE fmaxl_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE fminl_nid_postfix, 2, -1
ANYLIBCXX_TEST_LONG_DOUBLE fmal_nid_postfix, 3, -1
ANYLIBCXX_TEST_LONG_DOUBLE ldexpl_nid_postfix, 1, 3
ANYLIBCXX_TEST_LONG_DOUBLE scalbnl_nid_postfix, 1, 3
ANYLIBCXX_TEST_LONG_DOUBLE frexpl_nid_postfix, 1, 0
ANYLIBCXX_TEST_LONG_DOUBLE modfl_nid_postfix, 1, 0
ANYLIBCXX_TEST_LONG_DOUBLE remquol_nid_postfix, 2, 0
ANYLIBCXX_TEST_LONG_DOUBLE nanl_nid_postfix, 0, 0
ANYLIBCXX_TEST_LONG_DOUBLE scalblnl_nid_postfix, 1, 3
ANYLIBCXX_TEST_LONG_DOUBLE lgammal_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE tgammal_nid_postfix, 1, -1
ANYLIBCXX_TEST_LONG_DOUBLE strtold_nid_postfix, 0, -1
ANYLIBCXX_TEST_LONG_DOUBLE wcstold_nid_postfix, 0, -1

.section .rdata,"dr"
AnyLibcxxTwo: .double 2.0
AnyLibcxxThree: .double 3.0
AnyLibcxxFour: .double 4.0
AnyLibcxxSeven: .double 7.0
