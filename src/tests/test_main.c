#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_math.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))
#define TEST_EPS 1e-6l

START_TEST(test_zero1) { ck_assert_int_eq(abs(0), s21_abs(0)); }
END_TEST

START_TEST(test_neg1) { ck_assert_int_eq(abs(-1234), s21_abs(-1234)); }
END_TEST

START_TEST(test_pos1) { ck_assert_int_eq(abs(1234), s21_abs(1234)); }
END_TEST

Suite *suite_s21_abs(void) {
    Suite *s = suite_create("s21_abs");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero1);
    tcase_add_test(tc, test_neg1);
    tcase_add_test(tc, test_pos1);

    suite_add_tcase(s, tc);
    return s;
}



START_TEST(s21_acos_test1) {
  ck_assert_double_eq_tol(s21_acos(0), acos(0), 0.000001);
}
END_TEST

START_TEST(s21_acos_test2) {
  ck_assert_double_eq_tol(s21_acos(-0.369), acos(-0.369), 0.000001);
}
END_TEST

START_TEST(s21_acos_test3) {
  ck_assert_double_eq_tol(s21_acos(-1), acos(-1), 0.000001);
}
END_TEST

START_TEST(s21_acos_test4) {
  ck_assert_double_nan(s21_acos(INFINITY));
  ck_assert_double_nan(acos(INFINITY));
}
END_TEST

START_TEST(s21_acos_test5) {
  ck_assert_double_nan(s21_acos(NAN));
  ck_assert_double_nan(acos(NAN));
}
END_TEST

START_TEST(s21_acos_test6) {
  ck_assert_double_nan(s21_acos(-INFINITY));
  ck_assert_double_nan(acos(-INFINITY));
}
END_TEST

START_TEST(s21_acos_test7) {
  ck_assert_double_nan(s21_acos(16));
  ck_assert_double_nan(acos(16));
}
END_TEST

START_TEST(s21_acos_test8) {
  ck_assert_double_nan(s21_acos(-16));
  ck_assert_double_nan(acos(-16));
}
END_TEST

START_TEST(s21_acos_test9) {
  ck_assert_double_eq_tol(s21_acos(1), acos(1), 0.000001);
}
END_TEST

Suite *suite_s21_acos(void) {
    Suite *s = suite_create("s21_acos");
    TCase *tc = tcase_create("core");

  tcase_add_test(tc, s21_acos_test1);
  tcase_add_test(tc, s21_acos_test2);
  tcase_add_test(tc, s21_acos_test3);
  tcase_add_test(tc, s21_acos_test4);
  tcase_add_test(tc, s21_acos_test5);
  tcase_add_test(tc, s21_acos_test6);
  tcase_add_test(tc, s21_acos_test7);
  tcase_add_test(tc, s21_acos_test8);
  tcase_add_test(tc, s21_acos_test9);

    suite_add_tcase(s, tc);
    return s;
}


START_TEST(s21_asin_test1) {
  ck_assert_double_eq_tol(s21_asin(0.156), asin(0.156), 0.000001);
}
END_TEST

START_TEST(s21_asin_test2) {
  ck_assert_double_eq_tol(s21_asin(1), asin(1), 0.000001);
}
END_TEST

START_TEST(s21_asin_test3) {
  ck_assert_double_eq_tol(s21_asin(-1), asin(-1), 0.000001);
}
END_TEST

START_TEST(s21_asin_test4) {
  ck_assert_double_nan(s21_asin(INFINITY));
  ck_assert_double_nan(asin(INFINITY));
}
END_TEST

START_TEST(s21_asin_test5) {
  ck_assert_double_nan(s21_asin(NAN));
  ck_assert_double_nan(asin(NAN));
}
END_TEST

START_TEST(s21_asin_test6) {
  ck_assert_double_nan(s21_asin(-INFINITY));
  ck_assert_double_nan(asin(-INFINITY));
}
END_TEST

START_TEST(s21_asin_test7) {
  ck_assert_double_nan(s21_asin(16));
  ck_assert_double_nan(asin(16));
}
END_TEST

START_TEST(s21_asin_test8) {
  ck_assert_double_nan(s21_asin(-16));
  ck_assert_double_nan(asin(-16));
}
END_TEST

START_TEST(s21_asin_test9) {
  ck_assert_double_eq_tol(s21_asin(0), asin(0), 0.000001);
}
END_TEST

Suite *suite_s21_asin(void) {
    Suite *s = suite_create("s21_asin");
    TCase *tc = tcase_create("core");

  tcase_add_test(tc, s21_asin_test1);
  tcase_add_test(tc, s21_asin_test2);
  tcase_add_test(tc, s21_asin_test3);
  tcase_add_test(tc, s21_asin_test4);
  tcase_add_test(tc, s21_asin_test5);
  tcase_add_test(tc, s21_asin_test6);
  tcase_add_test(tc, s21_asin_test7);
  tcase_add_test(tc, s21_asin_test8);
  tcase_add_test(tc, s21_asin_test9);
    suite_add_tcase(s, tc);
    return s;
}

START_TEST(s21_atan_test1) {
  long double arr[] = {14.96, -25.1235, 0.23464, 0, 1, -1};
  for (int i = 0; i < 6; i++)
    ck_assert_double_eq_tol(s21_atan(arr[i]), atan(arr[i]), 0.000001);
}
END_TEST

START_TEST(s21_atan_test2) {
  ck_assert_double_eq(s21_atan(INFINITY), atan(INFINITY));
}
END_TEST

START_TEST(s21_atan_test3) {
  ck_assert_double_nan(s21_atan(NAN));
  ck_assert_double_nan(atan(NAN));
}
END_TEST

START_TEST(s21_atan_test4) {
  ck_assert_double_eq(s21_atan(-INFINITY), atan(-INFINITY));
}
END_TEST

Suite *suite_s21_atan(void) {
    Suite *s = suite_create("s21_atan");
    TCase *tc = tcase_create("core");

  tcase_add_test(tc, s21_atan_test1);
  tcase_add_test(tc, s21_atan_test2);
  tcase_add_test(tc, s21_atan_test3);
  tcase_add_test(tc, s21_atan_test4);

    suite_add_tcase(s, tc);
    return s;
}

START_TEST(test_zero) { ck_assert_ldouble_eq(ceil(0), s21_ceil(0)); }
END_TEST

START_TEST(test_neg) { ck_assert_ldouble_eq(ceil(-1234), s21_ceil(-1234)); }
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(ceil(1234), s21_ceil(1234)); }
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq(ceil(1), s21_ceil(1)); }
END_TEST

START_TEST(test_normal) { ck_assert_ldouble_eq(ceil(1.7), s21_ceil(1.7)); }
END_TEST

START_TEST(test_normal_negative) {
    ck_assert_int_eq(ceil(-1.7), s21_ceil(-1.7));
}
END_TEST

START_TEST(test_normal_negative_1) {
    ck_assert_int_eq(floor(-0.7), s21_floor(-0.7));
}
END_TEST

START_TEST(test_normal_above_1) {
    ck_assert_ldouble_eq(ceil(14.7), s21_ceil(14.7));
}
END_TEST
START_TEST(test_lesser_than_1) {
    ck_assert_ldouble_eq(ceil(0.7), s21_ceil(0.7));
}
END_TEST
START_TEST(test_positive_inf) {
    ck_assert_ldouble_eq(ceil(S21_INF), s21_ceil(S21_INF));
}
END_TEST
START_TEST(test_negative_inf) {
    ck_assert_ldouble_eq(ceil(-S21_INF), s21_ceil(-S21_INF));
}
END_TEST

START_TEST(test_nan) { ck_assert_ldouble_nan(s21_ceil(S21_NAN)); }
END_TEST

START_TEST(test_tolerance_pos) {
    double a = 0.1;
    int i = _i;
    ck_assert_ldouble_eq_tol(ceil(a * i), s21_ceil(a * i), TEST_EPS);
}
END_TEST

START_TEST(test_tolerance_neg) {
    double a = 0.1;
    int i = _i;
    ck_assert_ldouble_eq_tol(ceil(-a * i), s21_ceil(-a * i), TEST_EPS);
}
END_TEST

Suite *suite_s21_ceil(void) {
    Suite *s = suite_create("s21_ceil");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_pos);
    tcase_add_test(tc, test_pos_1);
    tcase_add_test(tc, test_normal);
    tcase_add_test(tc, test_normal_negative);
    tcase_add_test(tc, test_normal_negative_1);
    tcase_add_test(tc, test_normal_above_1);
    tcase_add_test(tc, test_negative_inf);
    tcase_add_test(tc, test_lesser_than_1);
    tcase_add_test(tc, test_positive_inf);
    tcase_add_test(tc, test_nan);
    tcase_add_loop_test(tc, test_tolerance_pos, 0, 520);
    tcase_add_loop_test(tc, test_tolerance_neg, 0, 520);
    suite_add_tcase(s, tc);
    return s;
}


START_TEST(test_cos_positive) {
    double x = 0.4;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_negative) {
    double x = -0.4;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_zero) {
    double x = 0;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_one) {
    double x = 1;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_one_negative) {
    double x = -1;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_huge_positive) {
    double x = 598987986;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_huge_negative) {
    double x = -5938409234;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_big_mantissa) {
    double x = 0.123456789012345678901234567890;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST
START_TEST(test_cos_two_pi) {
    double x = S21_PI;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_eps_positive) {
    double x = 1 + TEST_EPS;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_eps_negative) {
    double x = -1 - TEST_EPS;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_inf) { ck_assert_ldouble_nan(s21_cos(INFINITY)); }
END_TEST

START_TEST(test_cos_nan) { ck_assert_ldouble_nan(s21_cos(NAN)); }
END_TEST

START_TEST(test_cos_minus_inf) { ck_assert_ldouble_nan(s21_cos(-INFINITY)); }
END_TEST


START_TEST(test_cos_fractional_pi_values) {
    int i = _i;
    if (i != 0) {
        ck_assert_ldouble_eq_tol(cos(S21_PI / i), s21_cos(S21_PI / i), TEST_EPS);
    } else {
        ck_assert_ldouble_nan(s21_cos(S21_PI / i));
    }
} END_TEST

START_TEST(test_cos_whole_pi_values) {
    int i = _i;
    ck_assert_ldouble_eq_tol(cos(S21_PI * i), s21_cos(S21_PI * i), TEST_EPS);
} END_TEST


Suite *suite_s21_cos(void) {
    Suite *s = suite_create("s21_cos");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_cos_positive);
    tcase_add_test(tc, test_cos_negative);
    tcase_add_test(tc, test_cos_zero);
    tcase_add_test(tc, test_cos_one);
    tcase_add_test(tc, test_cos_negative);
    tcase_add_test(tc, test_cos_one_negative);
    tcase_add_test(tc, test_cos_huge_positive);
    tcase_add_test(tc, test_cos_huge_negative);
    tcase_add_test(tc, test_cos_big_mantissa);
    tcase_add_test(tc, test_cos_eps_positive);
    tcase_add_test(tc, test_cos_eps_negative);
    tcase_add_test(tc, test_cos_inf);
    tcase_add_test(tc, test_cos_nan);
    tcase_add_test(tc, test_cos_minus_inf);
    tcase_add_test(tc, test_cos_two_pi);
    tcase_add_loop_test(tc, test_cos_fractional_pi_values, -10, 10);
    tcase_add_loop_test(tc, test_cos_whole_pi_values, -10, 10);
    suite_add_tcase(s, tc);
    return s;
}



START_TEST(s21_exp_test1) {
  ck_assert_double_eq(s21_exp(25048.369), exp(25048.369));
}
END_TEST

START_TEST(s21_exp_test2) {
  ck_assert_double_eq_tol(s21_exp(-14.96), exp(-14.96), 0.000001);
}
END_TEST

START_TEST(s21_exp_test3) {
  ck_assert_double_eq(s21_exp(INFINITY), exp(INFINITY));
}
END_TEST

START_TEST(s21_exp_test4) {
  ck_assert_double_nan(s21_exp(NAN));
  ck_assert_double_nan(exp(NAN));
}
END_TEST

START_TEST(s21_exp_test5) {
  ck_assert_double_eq(s21_exp(-INFINITY), exp(-INFINITY));
}
END_TEST

START_TEST(s21_exp_test6) {
  ck_assert_double_eq_tol(s21_exp(0), exp(0), 0.000001);
}
END_TEST

START_TEST(s21_exp_test7) {
  ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001);
}
END_TEST

START_TEST(s21_exp_test8) {
  ck_assert_double_eq_tol(s21_exp(-1), exp(-1), 0.000001);
}
END_TEST

Suite *suite_s21_exp(void) {
    Suite *s = suite_create("s21_exp");
    TCase *tc = tcase_create("core");

  tcase_add_test(tc, s21_exp_test1);
  tcase_add_test(tc, s21_exp_test2);
  tcase_add_test(tc, s21_exp_test3);
  tcase_add_test(tc, s21_exp_test4);
  tcase_add_test(tc, s21_exp_test5);
  tcase_add_test(tc, s21_exp_test6);
  tcase_add_test(tc, s21_exp_test7);
  tcase_add_test(tc, s21_exp_test8);

    suite_add_tcase(s, tc);
    return s;
}


START_TEST(test_zero2) {
    ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
} END_TEST

START_TEST(test_neg2) {
    ck_assert_int_eq(fabs(-3425743948574326.345345), s21_fabs(-3425743948574326.345345));
} END_TEST

START_TEST(test_pos2) {
    ck_assert_int_eq(fabs(3425743948574326.345345), s21_fabs(3425743948574326.345345));
} END_TEST


Suite *suite_s21_fabs(void) {
    Suite *s = suite_create("s21_fabs");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero2);
    tcase_add_test(tc, test_neg2);
    tcase_add_test(tc, test_pos2);

    suite_add_tcase(s, tc);
    return s;
}


START_TEST(test_zero3) { ck_assert_ldouble_eq(floor(0), s21_floor(0)); }
END_TEST

START_TEST(test_neg3) { ck_assert_ldouble_eq(floor(-1234), s21_floor(-1234)); }
END_TEST

START_TEST(test_pos3) { ck_assert_ldouble_eq(floor(1234), s21_floor(1234)); }
END_TEST

START_TEST(test_pos_13) { ck_assert_ldouble_eq(ceil(1), s21_ceil(1)); }
END_TEST

START_TEST(test_normal3) { ck_assert_ldouble_eq(floor(1.7), s21_floor(1.7)); }
END_TEST

START_TEST(test_normal_negative3) {
    ck_assert_int_eq(floor(-1.7), s21_floor(-1.7));
}
END_TEST

START_TEST(test_normal_negative_13) {
    ck_assert_int_eq(floor(-0.7), s21_floor(-0.7));
}
END_TEST

START_TEST(test_normal_above_13) {
    ck_assert_ldouble_eq(floor(14.7), s21_floor(14.7));
}
END_TEST
START_TEST(test_lesser_than_13) {
    ck_assert_ldouble_eq(floor(0.7), s21_floor(0.7));
}
END_TEST
START_TEST(test_positive_inf3) {
    ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
}
END_TEST
START_TEST(test_negative_inf3) {
    ck_assert_ldouble_eq(floor(-S21_INF), s21_floor(-S21_INF));
}
END_TEST

START_TEST(test_nan3) { ck_assert_ldouble_nan(s21_floor(S21_NAN)); }
END_TEST

START_TEST(test_high_accuracy3) {
    ck_assert_ldouble_eq(floor(0.123456907912345),
                         s21_floor(0.123456907912345));
}
END_TEST

START_TEST(test_tolerance_pos3) {
    double a = 0.1;
    int i = _i;
    ck_assert_ldouble_eq_tol(ceil(a * i), s21_ceil(a * i), TEST_EPS);
}
END_TEST

START_TEST(test_tolerance_neg3) {
    double a = 0.1;
    int i = _i;
    ck_assert_ldouble_eq_tol(ceil(-a * i), s21_ceil(-a * i), TEST_EPS);
}
END_TEST

Suite *suite_s21_floor(void) {
    Suite *s = suite_create("s21_floor");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero3);
    tcase_add_test(tc, test_neg3);
    tcase_add_test(tc, test_pos3);
    tcase_add_test(tc, test_pos_13);
    tcase_add_test(tc, test_normal3);
    tcase_add_test(tc, test_normal_negative3);
    tcase_add_test(tc, test_normal_negative_13);
    tcase_add_test(tc, test_normal_above_13);
    tcase_add_test(tc, test_negative_inf3);
    tcase_add_test(tc, test_lesser_than_13);
    tcase_add_test(tc, test_positive_inf3);
    tcase_add_test(tc, test_nan3);
    tcase_add_test(tc, test_tolerance_pos3);
    tcase_add_test(tc, test_tolerance_neg3);
    tcase_add_test(tc, test_high_accuracy3);
    suite_add_tcase(s, tc);
    return s;
}


START_TEST(test_pos4) {
    double x = 534536.34523;
    double y = 2345.34535;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_neg4) {
    double x = -5345346.34523;
    double y = 2345.34535;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_neg24) {
    double x = 5345346.34523;
    double y = -2345.34535;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_neg_two4) {
    double x = -10.1;
    double y = -3.;
    ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}

START_TEST(test_nul4) {
    double x = 5345346.34523;
    double y = 0;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_nul24) {
    double x = 0;
    double y = 4353.64564;
    ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_nul34) {
    double x = 0;
    double y = -S21_NAN;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_nan4) {
    double x = S21_NAN;
    double y = 245.34535;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_nan24) {
    double x = 245.34535;
    double y = S21_NAN;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_inf4) {
    double x = S21_INF;
    double y = 4323.432543;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_inf24) {
    double x = 436645.34523;
    double y = S21_INF;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_inf34) {
    double x = 436645.34523;
    double y = -S21_INF;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_inf44) {
    double x = -S21_INF;
    double y = 0;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_inf54) {
    double x = 0;
    double y = S21_INF;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

Suite *suite_s21_fmod(void) {
    Suite *s = suite_create("s21_fmod");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_pos4);
    tcase_add_test(tc, test_neg4);
    tcase_add_test(tc, test_neg24);
    tcase_add_test(tc, test_neg_two4);
    tcase_add_test(tc, test_nul4);
    tcase_add_test(tc, test_nul24);
    tcase_add_test(tc, test_nul34);
    tcase_add_test(tc, test_nan4);
    tcase_add_test(tc, test_nan24);
    tcase_add_test(tc, test_inf4);
    tcase_add_test(tc, test_inf24);
    tcase_add_test(tc, test_inf34);
    tcase_add_test(tc, test_inf44);
    tcase_add_test(tc, test_inf54);
    suite_add_tcase(s, tc);
    return s;
}


START_TEST(s21_log_test1) {
  ck_assert_double_eq_tol(s21_log(26941.289), log(26941.289), 0.000001);
}
END_TEST

START_TEST(s21_log_test2) {
  ck_assert_double_nan(s21_log(-12.36));
  ck_assert_double_nan(log(-12.36));
}
END_TEST

START_TEST(s21_log_test3) {
  ck_assert_double_eq(s21_log(INFINITY), log(INFINITY));
}
END_TEST

START_TEST(s21_log_test4) {
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(log(NAN));
}
END_TEST

START_TEST(s21_log_test5) {
  ck_assert_double_nan(s21_log(-INFINITY));
  ck_assert_double_nan(log(-INFINITY));
}
END_TEST

START_TEST(s21_log_test6) { ck_assert_double_eq(s21_log(0), log(0)); }
END_TEST

START_TEST(s21_log_test7) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST

Suite *suite_s21_log(void) {
    Suite *s = suite_create("s21_log");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, s21_log_test1);
    tcase_add_test(tc, s21_log_test2);
    tcase_add_test(tc, s21_log_test3);
    tcase_add_test(tc, s21_log_test4);
    tcase_add_test(tc, s21_log_test5);
    tcase_add_test(tc, s21_log_test6);
    tcase_add_test(tc, s21_log_test7);

    suite_add_tcase(s, tc);
    return s;
}


START_TEST(s21_pow_test1) {
  ck_assert_double_eq_tol(s21_pow(20, 0.4), pow(20, 0.4), 0.000001);
}
END_TEST

START_TEST(s21_pow_test2) {
  ck_assert_double_nan(s21_pow(-20, 0.4));
  ck_assert_double_nan(pow(-20, 0.4));
}
END_TEST

START_TEST(s21_pow_test3) {
  ck_assert_double_eq(s21_pow(INFINITY, INFINITY), pow(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test4) {
  ck_assert_double_eq(s21_pow(-INFINITY, -INFINITY), pow(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test5) {
  ck_assert_double_nan(s21_pow(NAN, NAN));
  ck_assert_double_nan(pow(NAN, NAN));
}
END_TEST

START_TEST(s21_pow_test6) {
  ck_assert_double_nan(s21_pow(INFINITY, NAN));
  ck_assert_double_nan(pow(INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test7) {
  ck_assert_double_nan(s21_pow(NAN, INFINITY));
  ck_assert_double_nan(pow(NAN, INFINITY));
}
END_TEST

START_TEST(s21_pow_test8) {
  ck_assert_double_nan(s21_pow(-INFINITY, NAN));
  ck_assert_double_nan(pow(-INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_test9) {
  ck_assert_double_nan(s21_pow(NAN, -INFINITY));
  ck_assert_double_nan(pow(NAN, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test10) {
  ck_assert_double_eq(s21_pow(-INFINITY, INFINITY), pow(-INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_test11) {
  ck_assert_double_eq(s21_pow(INFINITY, -INFINITY), pow(INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test12) {
  ck_assert_double_eq_tol(s21_pow(12.69, 0), pow(12.69, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test13) {
  ck_assert_double_eq_tol(s21_pow(-20.63, 3), pow(-20.63, 3), 0.000001);
}
END_TEST

START_TEST(s21_pow_test14) {
  ck_assert_double_eq_tol(s21_pow(-20.63, 6), pow(-20.63, 6), 0.000001);
}
END_TEST

START_TEST(s21_pow_test15) {
  ck_assert_double_eq_tol(s21_pow(-INFINITY, 0), pow(-INFINITY, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test16) {
  ck_assert_double_eq_tol(s21_pow(INFINITY, 0), pow(INFINITY, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test17) {
  ck_assert_double_eq_tol(s21_pow(NAN, 0), pow(NAN, 0), 0.000001);
}
END_TEST

START_TEST(s21_pow_test18) {
  ck_assert_double_eq(s21_pow(0, -INFINITY), pow(0, -INFINITY));
}
END_TEST

START_TEST(s21_pow_test19) {
  ck_assert_double_eq_tol(s21_pow(0, INFINITY), pow(0, INFINITY), 0.000001);
}
END_TEST

START_TEST(s21_pow_test20) {
  ck_assert_double_nan(s21_pow(0, NAN));
  ck_assert_double_nan(pow(0, NAN));
}
END_TEST

START_TEST(s21_pow_test21) { ck_assert_double_eq(s21_pow(0, 0), pow(0, 0)); }
END_TEST

START_TEST(s21_pow_test22) {
  ck_assert_double_eq(s21_pow(16894.2629, 1545), pow(16894.2629, 1545));
}
END_TEST

START_TEST(s21_pow_test23) {
  ck_assert_double_eq(s21_pow(16894.2629, -1545), pow(16894.2629, -1545));
}
END_TEST

START_TEST(s21_pow_test24) {
  ck_assert_double_eq(s21_pow(-16894.2629, 1545), pow(-16894.2629, 1545));
}
END_TEST

START_TEST(s21_pow_test25) {
  ck_assert_double_eq(s21_pow(-16894.2629, -1545), pow(-16894.2629, -1545));
}
END_TEST

Suite *suite_s21_pow(void) {
    Suite *s = suite_create("s21_pow");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, s21_pow_test1);
    tcase_add_test(tc, s21_pow_test2);
    tcase_add_test(tc, s21_pow_test3);
    tcase_add_test(tc, s21_pow_test4);
    tcase_add_test(tc, s21_pow_test5);
    tcase_add_test(tc, s21_pow_test6);
    tcase_add_test(tc, s21_pow_test7);
    tcase_add_test(tc, s21_pow_test8);
    tcase_add_test(tc, s21_pow_test9);
    tcase_add_test(tc, s21_pow_test10);
    tcase_add_test(tc, s21_pow_test11);
    tcase_add_test(tc, s21_pow_test12);
    tcase_add_test(tc, s21_pow_test13);
    tcase_add_test(tc, s21_pow_test14);
    tcase_add_test(tc, s21_pow_test15);
    tcase_add_test(tc, s21_pow_test16);
    tcase_add_test(tc, s21_pow_test17);
    tcase_add_test(tc, s21_pow_test18);
    tcase_add_test(tc, s21_pow_test19);
    tcase_add_test(tc, s21_pow_test20);
    tcase_add_test(tc, s21_pow_test21);
    tcase_add_test(tc, s21_pow_test22);
    tcase_add_test(tc, s21_pow_test23);
    tcase_add_test(tc, s21_pow_test24);
    tcase_add_test(tc, s21_pow_test25);

    suite_add_tcase(s, tc);
    return s;
}


START_TEST(test_sin_small_positive) {
    double x = 2.523;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_small_negative) {
    double x = -2.523;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_huge_positive) {
    double x = 923456789;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_huge_negative) {
    double x = -923456789;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_zero) {
    double x = 0;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_nan) {
    double x = NAN;
    ck_assert_ldouble_nan(s21_sin(x));
} END_TEST

START_TEST(test_sin_inf) {
    double x = INFINITY;
    ck_assert_ldouble_nan(s21_sin(x));
} END_TEST

START_TEST(test_sin_fractional_pi_values) {
    int i = _i;
    if (i != 0) {
        ck_assert_ldouble_eq_tol(sin(S21_PI / i), s21_sin(S21_PI / i), TEST_EPS);
    } else {
        ck_assert_ldouble_nan(s21_sin(S21_PI / i));
    }
} END_TEST

START_TEST(test_sin_whole_pi_values) {
    int i = _i;
    ck_assert_ldouble_eq_tol(sin(S21_PI * i), s21_sin(S21_PI * i), TEST_EPS);
} END_TEST

START_TEST(test_sin_big_mantissa) {
    double x = 0.12345678901234567890;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

Suite *suite_s21_sin(void) {
    Suite *s = suite_create("s21_sin");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_sin_small_positive);
    tcase_add_test(tc, test_sin_small_negative);
    tcase_add_test(tc, test_sin_huge_positive);
    tcase_add_test(tc, test_sin_huge_negative);
    tcase_add_test(tc, test_sin_zero);
    tcase_add_test(tc, test_sin_nan);
    tcase_add_test(tc, test_sin_inf);
    tcase_add_loop_test(tc, test_sin_fractional_pi_values, -10, 10);
    tcase_add_loop_test(tc, test_sin_whole_pi_values, -10, 10);
    tcase_add_test(tc, test_sin_big_mantissa);

    suite_add_tcase(s, tc);
    return s;
}


START_TEST(s21_sqrt_test1) {
  ck_assert_double_nan(s21_sqrt(-0.01));
  ck_assert_double_nan(sqrt(-0.01));
}
END_TEST

START_TEST(s21_sqrt_test2) {
  ck_assert_double_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test3) {
  ck_assert_double_nan(s21_sqrt(NAN));
  ck_assert_double_nan(sqrt(NAN));
}
END_TEST

START_TEST(s21_sqrt_test4) {
  ck_assert_double_nan(s21_sqrt(-INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(s21_sqrt_test5) {
  ck_assert_double_nan(s21_sqrt(-231.41));
  ck_assert_double_nan(sqrt(-231.41));
}
END_TEST

START_TEST(s21_sqrt_test6) {
  long double arr[] = {5898.467, 8427.928,  5698.0035, 1289.244, 7025.7,
                       12.1357,  4745.5,    2930.637,  8187.391, 1015.89,
                       3155.844, 3954.143,  2862.1,    2782.954, 5097.545,
                       2630.4,   1075.747,  1889.786,  1782,     0.0001,
                       21345678, 7432,      0.3245,    12345,    13456,
                       0.03213,  324.42342, 0,         50,       0.24};
  for (int i = 0; i < 30; i++) {
    ck_assert_double_eq_tol(s21_sqrt(arr[i]), sqrt(arr[i]), 0.000001);
  }
}

Suite *suite_s21_sqrt(void) {
    Suite *s = suite_create("s21_sqrt");
    TCase *tc = tcase_create("core");

  tcase_add_test(tc, s21_sqrt_test1);
  tcase_add_test(tc, s21_sqrt_test2);
  tcase_add_test(tc, s21_sqrt_test3);
  tcase_add_test(tc, s21_sqrt_test4);
  tcase_add_test(tc, s21_sqrt_test5);
  tcase_add_test(tc, s21_sqrt_test6);

    suite_add_tcase(s, tc);
    return s;
}


START_TEST(test_tan_positive) {
    double x = 0.4;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_negative) {
    double x = -0.4;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_zero) {
    double x = 0;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_one) {
    double x = 1;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_one_negative) {
    double x = -1;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_huge_positive) {
    double x = 400000.23;
    /* 598987986; */
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_huge_negative) {
    double x = -400000.23;
    /* 5938409234; */
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_big_mantissa) {
    double x = 0.123456789012345678901234567890;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST
START_TEST(test_tan_two_pi) {
    double x = S21_PI;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_eps_positive) {
    double x = 1 + TEST_EPS;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_eps_negative) {
    double x = -1 - TEST_EPS;
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), TEST_EPS);
}
END_TEST

START_TEST(test_tan_inf) { ck_assert_ldouble_nan(s21_tan(INFINITY)); }
END_TEST

START_TEST(test_tan_nan) { ck_assert_ldouble_nan(s21_tan(NAN)); }
END_TEST

START_TEST(test_tan_minus_inf) { ck_assert_ldouble_nan(s21_tan(-INFINITY)); }
END_TEST
START_TEST(test_tan_fractional_pi_values) {
    int i = _i;
    if (i != 2 && i != -2) {
        if (i != 0) {
            ck_assert_ldouble_eq_tol(tan(S21_PI / i), s21_tan(S21_PI / i), TEST_EPS);
        } else {
            ck_assert_ldouble_nan(s21_tan(S21_PI / i));
        }
    }
}
END_TEST
START_TEST(test_tan_whole_pi_values) {
    int i = _i;
    ck_assert_ldouble_eq_tol(tan(S21_PI * i), s21_tan(S21_PI * i), TEST_EPS);
}
END_TEST

Suite *suite_s21_tan(void) {
    Suite *s = suite_create("s21_tan");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_tan_positive);
    tcase_add_test(tc, test_tan_negative);
    tcase_add_test(tc, test_tan_zero);
    tcase_add_test(tc, test_tan_one);
    tcase_add_test(tc, test_tan_negative);
    tcase_add_test(tc, test_tan_one_negative);
    tcase_add_test(tc, test_tan_huge_positive);
    tcase_add_test(tc, test_tan_huge_negative);
    tcase_add_test(tc, test_tan_big_mantissa);
    tcase_add_test(tc, test_tan_eps_positive);
    tcase_add_test(tc, test_tan_eps_negative);
    tcase_add_test(tc, test_tan_inf);
    tcase_add_test(tc, test_tan_nan);
    tcase_add_test(tc, test_tan_minus_inf);
    tcase_add_test(tc, test_tan_two_pi);
    tcase_add_loop_test(tc, test_tan_fractional_pi_values, -10, 10);
    tcase_add_loop_test(tc, test_tan_whole_pi_values, -10, 10);
    suite_add_tcase(s, tc);
    return s;
}

int main(void) {
    Suite *test_suites[] = {suite_s21_pow(),
                            suite_s21_exp(),                            
                            suite_s21_log(),
                            suite_s21_sqrt(),
                            suite_s21_acos(),
                            suite_s21_atan(),
                            suite_s21_asin(),
                            suite_s21_abs(),
                            suite_s21_fabs(),
                            suite_s21_cos(),
                            suite_s21_tan(),   
                            suite_s21_sin(),                                                     
                            suite_s21_ceil(), 
                            suite_s21_floor(),
                            suite_s21_fmod()};

    SRunner *sr = srunner_create(test_suites[0]);
    srunner_set_fork_status(sr, CK_NOFORK);
    int nf;

    for (size_t i = 1; i < ARRAY_SIZE(test_suites); i++)
        srunner_add_suite(sr, test_suites[i]);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
