#include "s21_math.h"

long double s21_sin(double x) {
  long double sin = 0;
  if (s21_is_inf(x) || s21_is_nan(x)) {
    sin = S21_NAN;
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    while (x > S21_PI) {
      x -= 2 * S21_PI;
    }
    while (x < -S21_PI) {
      x += 2 * S21_PI;
    }
    sin = x;
    int i = 1;
    double temp = x;
    while (!(temp >= -0.0000001 && temp <= 0.0000001)) {
      temp = (-temp * x * x) / ((2 * i + 1) * (2 * i));
      sin += temp;
      i++;
    }
  }
  return sin;
}
