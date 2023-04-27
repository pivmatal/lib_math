#include "s21_math.h"

long double s21_pow(double x, double y) {
  if (!y) {
    return 1;
  }
  if (x == S21_INF_NEG && y == S21_INF_NEG) {
    return 0;
  }
  if (x == S21_INF_NEG && y == S21_INF_POS) {
    return S21_INF_POS;
  }
  if (x < 0 && y != (long long int)y) {
    return S21_NAN;
  }
  long double res = 0;
  int sign = 1;
  if (x < 0) {
    sign = -1;
  }
  res = s21_exp(y * s21_log(x * sign));
  if (s21_fmod(y, 2)) {
    res = res * sign;
  }
  return res;
}
