#include "s21_math.h"

long double s21_cos(double x) {
  long double cos = 0;

  if (s21_is_nan(x) || s21_is_inf(x)) {
    cos = S21_NAN;
  } else {
    cos = s21_sin((S21_PI / 2.) - x);
  }
  return cos;
}
