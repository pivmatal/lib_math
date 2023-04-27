#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (x >= LLONG_MAX || x <= LLONG_MIN || x != x) {
    res = x;
  } else if (s21_fabs(x) > 0. && x != res) {
    if (x > 0.) {
      res += 1;
    }
  }
  return res;
}
