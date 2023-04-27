#ifndef S21_MATH_H
#define S21_MATH_H
#include <float.h>
#include <limits.h>

#define S21_E 2.718281828459045
#define S21_PI 3.141592653589793

#define S21_INF __builtin_inf()
#define S21_NAN __builtin_nan("")
#define S21_DBL_MAX DBL_MAX
#define is_inf __builtin_isinf
#define is_nan __builtin_isnan
#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define s21_is_nan(x) __builtin_isnan(x)
#define s21_is_inf(x) __builtin_isinf(x)

#define S21_EPS 1e-17
#define MAX_LONG_DOUBLE 1.79769313486231571e+308

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
