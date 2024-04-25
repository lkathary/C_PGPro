#include <check.h>
#include <math.h>

#include "quadratic_equation.h"

START_TEST(test_1) {
  EquationResult result = solve_equation(0.0, 0.0, 0.0);
  ck_assert_int_eq(result.num_roots, -1);  // Infinite roots
}
END_TEST

START_TEST(test_2) {
  EquationResult result = solve_equation(0.0, 0.0, 2.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_3) {
  EquationResult result = solve_equation(0.0, 0.0, -3.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_4) {
  EquationResult result = solve_equation(0.0, 2.0, 0.0);
  ck_assert_int_eq(result.num_roots, 1);
  ck_assert_double_eq_tol(result.root1, 0.0, EPSILON);
  ck_assert_double_eq_tol(result.root2, 0.0, EPSILON);
}
END_TEST

START_TEST(test_5) {
  EquationResult result = solve_equation(0.0, 2.0, 5.0);
  ck_assert_int_eq(result.num_roots, 1);
  ck_assert_double_eq_tol(result.root1, -2.5, EPSILON);
  ck_assert_double_eq_tol(result.root2, -2.5, EPSILON);
}
END_TEST

START_TEST(test_6) {
  EquationResult result = solve_equation(2.0, 0.0, 0.0);
  ck_assert_int_eq(result.num_roots, 1);
  ck_assert_double_eq_tol(result.root1, 0.0, EPSILON);
  ck_assert_double_eq_tol(result.root2, 0.0, EPSILON);
}
END_TEST

START_TEST(test_7) {
  EquationResult result = solve_equation(2.0, 0.0, -8.0);
  ck_assert_int_eq(result.num_roots, 2);
  ck_assert_double_eq_tol(result.root1, 2.0, EPSILON);
  ck_assert_double_eq_tol(result.root2, -2.0, EPSILON);
}
END_TEST

START_TEST(test_8) {
  EquationResult result = solve_equation(2.0, 0.0, 8.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_9) {
  EquationResult result = solve_equation(2.0, 4.0, 0.0);
  ck_assert_int_eq(result.num_roots, 2);
  ck_assert_double_eq_tol(result.root1, 0.0, EPSILON);
  ck_assert_double_eq_tol(result.root2, -2.0, EPSILON);
}
END_TEST

START_TEST(test_10) {
  EquationResult result = solve_equation(2.0, -4.0, 0.0);
  ck_assert_int_eq(result.num_roots, 2);
  ck_assert_double_eq_tol(result.root1, 2.0, EPSILON);
  ck_assert_double_eq_tol(result.root2, 0.0, EPSILON);
}
END_TEST

START_TEST(test_11) {
  EquationResult result = solve_equation(1.0, -3.0, 2.0);
  ck_assert_int_eq(result.num_roots, 2);
  ck_assert_double_eq_tol(result.root1, 2.0, EPSILON);
  ck_assert_double_eq_tol(result.root2, 1.0, EPSILON);
}
END_TEST

START_TEST(test_12) {
  EquationResult result = solve_equation(1.0, -4.0, 4.0);
  ck_assert_int_eq(result.num_roots, 1);
  ck_assert_double_eq_tol(result.root1, 2.0, EPSILON);
  ck_assert_double_eq_tol(result.root2, 2.0, EPSILON);
}
END_TEST

START_TEST(test_13) {
  EquationResult result = solve_equation(-2.0, 4.0, -5.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_14) {
  EquationResult result = solve_equation(NAN, -3.0, 2.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_15) {
  EquationResult result = solve_equation(1.0, NAN, 2.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_16) {
  EquationResult result = solve_equation(1.0, -3.0, NAN);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_17) {
  EquationResult result = solve_equation(INFINITY, -3.0, 2.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_18) {
  EquationResult result = solve_equation(1.0, INFINITY, 2.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_19) {
  EquationResult result = solve_equation(1.0, -3.0, INFINITY);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_20) {
  EquationResult result = solve_equation(-INFINITY, -3.0, 2.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_21) {
  EquationResult result = solve_equation(1.0, -INFINITY, 2.0);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_22) {
  EquationResult result = solve_equation(1.0, -3.0, -INFINITY);
  ck_assert_int_eq(result.num_roots, 0);
}
END_TEST

START_TEST(test_23) {
  EquationResult result = solve_equation(1e-12, -2e-6, 1);
  ck_assert_int_eq(result.num_roots, 1);
  ck_assert_double_eq_tol(result.root1, 1e6, EPSILON);
  ck_assert_double_eq_tol(result.root2, 1e6, EPSILON);
}
END_TEST

int main() {
  Suite *suite = suite_create("quadratic_equation");
  SRunner *sr = srunner_create(suite);

  TCase *tc = tcase_create("equation_tests");
  tcase_add_test(tc, test_1);
  tcase_add_test(tc, test_2);
  tcase_add_test(tc, test_3);
  tcase_add_test(tc, test_4);
  tcase_add_test(tc, test_5);
  tcase_add_test(tc, test_6);
  tcase_add_test(tc, test_7);
  tcase_add_test(tc, test_8);
  tcase_add_test(tc, test_9);
  tcase_add_test(tc, test_10);
  tcase_add_test(tc, test_11);
  tcase_add_test(tc, test_12);
  tcase_add_test(tc, test_13);
  tcase_add_test(tc, test_14);
  tcase_add_test(tc, test_15);
  tcase_add_test(tc, test_16);
  tcase_add_test(tc, test_17);
  tcase_add_test(tc, test_18);
  tcase_add_test(tc, test_19);
  tcase_add_test(tc, test_20);
  tcase_add_test(tc, test_21);
  tcase_add_test(tc, test_22);
  tcase_add_test(tc, test_23);
  suite_add_tcase(suite, tc);

  srunner_run_all(sr, CK_VERBOSE);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;

  return 0;
}
