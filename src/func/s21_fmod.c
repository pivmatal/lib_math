#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (is_nan(x) || is_nan(y) || is_inf(x) || y == 0) {
    res = S21_NAN;
  } else if (is_inf(y)) {
    res = x;
  } else if (x == 0.0 && y != 0) {
    res = 0.0;
  } else {
    if ((x < 0 || y < 0) && (x * y) < 0) {
      res = -s21_abs(x / y);
    } else {
      res = s21_abs(x / y);
    }
    res = x - res * y;
  }
  return res;
}
