#include "s21_math.h"

long double s21_floor(double x) {
  long double res = (long long int)x;
  if (x >= LLONG_MAX || x <= LLONG_MIN || x != x) {
    res = x;
  } else if (s21_fabs(x - res) > 0. && s21_fabs(x) > 0.) {
    if (x < 0.) {
      res -= 1;
    }
  }

  return res;
}
