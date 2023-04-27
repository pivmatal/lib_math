#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  if (x > -1 && x < 1) {
    result = x / s21_sqrt(1 - (x * x));
    result = s21_atan(result);
  } else if (x == 1 || x == -1) {
    result = x * S21_PI / 2;
  }
  if (x > 1 || x < -1 || is_nan(x)) {
    result = S21_NAN;
  }
  return result;
}
