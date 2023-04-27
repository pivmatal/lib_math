#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  int zn = 1;

  if (x == 1 || x == -1) {
    result = x * S21_PI / 4;
  } else if (is_nan(x)) {
    result = S21_NAN;
  } else if (is_inf(x) || x == S21_DBL_MAX) {
    if (x < 0) {
      zn = -1;
    }
    result = zn * S21_PI / 2;
  }

  if (s21_fabs(x) < 1) {
    for (int i = 0; i < 7000; i++) {
      result += s21_pow(-1, i) * s21_pow(x, (1 + (2 * i))) / (1 + (2 * i));
    }
  } else if (s21_fabs(x) > 1 && !is_inf(x) && x != S21_DBL_MAX) {
    for (int i = 0; i < 7000; i++) {
      result += s21_pow(-1, i) * (s21_pow(x, (-1 - (2 * i))) / (1 + (2 * i)));
    }
    result = S21_PI * s21_sqrt(x * x) / (2 * x) - result;
  }

  return result;
}
