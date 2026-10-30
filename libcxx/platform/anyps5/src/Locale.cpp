#include <locale.h>
#include <stdexcept>

namespace {
struct GuestLocaleConventions {
    char* Monetary[7];
    char Characters[14];
    char Padding[2];
    char* DecimalPoint;
    char* Grouping;
    char* ThousandsSeparator;
    char* Extra[6];
};
static_assert(sizeof(GuestLocaleConventions) == 144);
lconv convertedLocale;
}

extern "C" {
GuestLocaleConventions* __attribute__((sysv_abi)) localeconv_nid_postfix();
lconv* localeconv() {
    const auto* value = localeconv_nid_postfix();
    if (!value) throw std::runtime_error("Missing locale conventions");
    convertedLocale.decimal_point = value->DecimalPoint;
    convertedLocale.grouping = value->Grouping;
    convertedLocale.thousands_sep = value->ThousandsSeparator;
    convertedLocale.int_curr_symbol = value->Monetary[0];
    convertedLocale.currency_symbol = value->Monetary[1];
    convertedLocale.mon_decimal_point = value->Monetary[2];
    convertedLocale.mon_thousands_sep = value->Monetary[3];
    convertedLocale.mon_grouping = value->Monetary[4];
    convertedLocale.positive_sign = value->Monetary[5];
    convertedLocale.negative_sign = value->Monetary[6];
    convertedLocale.int_frac_digits = value->Characters[0];
    convertedLocale.frac_digits = value->Characters[1];
    convertedLocale.p_cs_precedes = value->Characters[2];
    convertedLocale.p_sep_by_space = value->Characters[3];
    convertedLocale.n_cs_precedes = value->Characters[4];
    convertedLocale.n_sep_by_space = value->Characters[5];
    convertedLocale.p_sign_posn = value->Characters[6];
    convertedLocale.n_sign_posn = value->Characters[7];
    convertedLocale.int_p_cs_precedes = value->Characters[8];
    convertedLocale.int_p_sep_by_space = value->Characters[9];
    convertedLocale.int_n_cs_precedes = value->Characters[10];
    convertedLocale.int_n_sep_by_space = value->Characters[11];
    convertedLocale.int_p_sign_posn = value->Characters[12];
    convertedLocale.int_n_sign_posn = value->Characters[13];
    return &convertedLocale;
}
}
