#include "s21_math.h"

long double s21_exp(double x) {
  long double exp = 0;
  long double res = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0, stop = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (stop == 0 && s21_fabs(res) > S21_EPS) {
    res = res * (x / i);
    i = i + 1;
    temp = temp + res;
    if (temp > MAX_LONG_DOUBLE) {
      temp = S21_INF;
      stop = 1;
    }
  }
  if (flag == 1) {
    if (temp > MAX_LONG_DOUBLE)
      temp = 0;
    else
      temp = 1. / temp;
  }
  if (temp > MAX_LONG_DOUBLE) {
    exp = S21_INF;
  } else {
    exp = temp;
  }
  return exp;
}
