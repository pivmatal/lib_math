#include "s21_math.h"

long double s21_acos(double x) {
  long double result = 0;
  if (x > 0 && x <= 1) {
    result = s21_sqrt(1 - (x * x)) / x;
    result = s21_atan(result);
  } else if (x >= -1 && x < 0) {
    result = s21_sqrt(1 - (x * x)) / x;
    result = s21_atan(result) + S21_PI;
  }
  if (x == 0) {
    result = S21_PI / 2;
  }
  if (x > 1 || x < -1 || is_nan(x)) {
    result = S21_NAN;
  }
  return result;
}
