#include "s21_math.h"

long double s21_log(double x) {
  int count = 0;
  long double res = 0;
  if (x == S21_INF_POS) {
    res = x;
  } else if (x == 0) {
    res = S21_INF_NEG;
  } else if (x < 0) {
    res = S21_NAN;
  } else {
    while (x >= S21_E) {
      x /= S21_E;
      count++;
    }
    long double stap = 0;
    for (int i = 0; i < 1000; i++) {
      stap = res;
      res = stap + 2 * ((x - s21_exp(stap)) / (x + s21_exp(stap)));
    }
  }
  return (res + count);
}
