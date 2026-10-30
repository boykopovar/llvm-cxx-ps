extern "C" {
long double tgammal_nid_postfix(long double value);
double lgamma_nid_postfix(double value);
double tgamma(double value) { return static_cast<double>(tgammal_nid_postfix(value)); }
float lgammaf(float value) { return static_cast<float>(lgamma_nid_postfix(value)); }
}
