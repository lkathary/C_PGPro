#include <gtest/gtest.h>
#include <math.h>

extern "C" {
#include "quadratic_equation.h"
}

TEST(quadratic_equation, test_1) {
  EquationResult result = solve_equation(0.0, 0.0, 0.0);
  ASSERT_EQ(result.num_roots, -1);  // Infinite roots
}

TEST(quadratic_equation, test_2) {
  EquationResult result = solve_equation(0.0, 0.0, 2.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_3) {
  EquationResult result = solve_equation(0.0, 0.0, -3.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_4) {
  EquationResult result = solve_equation(0.0, 2.0, 0.0);
  ASSERT_EQ(result.num_roots, 1);
  ASSERT_NEAR(result.root1, 0.0, EPSILON);
  ASSERT_NEAR(result.root2, 0.0, EPSILON);
}

TEST(quadratic_equation, test_5) {
  EquationResult result = solve_equation(0.0, 2.0, 5.0);
  ASSERT_EQ(result.num_roots, 1);
  ASSERT_NEAR(result.root1, -2.5, EPSILON);
  ASSERT_NEAR(result.root2, -2.5, EPSILON);
}

TEST(quadratic_equation, test_6) {
  EquationResult result = solve_equation(2.0, 0.0, 0.0);
  ASSERT_EQ(result.num_roots, 1);
  ASSERT_NEAR(result.root1, 0, EPSILON);
  ASSERT_NEAR(result.root2, 0, EPSILON);
}

TEST(quadratic_equation, test_7) {
  EquationResult result = solve_equation(2.0, 0.0, -8.0);
  ASSERT_EQ(result.num_roots, 2);
  ASSERT_NEAR(result.root1, 2.0, EPSILON);
  ASSERT_NEAR(result.root2, -2.0, EPSILON);
}

TEST(quadratic_equation, test_8) {
  EquationResult result = solve_equation(2.0, 0.0, 8.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_9) {
  EquationResult result = solve_equation(2.0, 4.0, 0.0);
  ASSERT_EQ(result.num_roots, 2);
  ASSERT_NEAR(result.root1, 0.0, EPSILON);
  ASSERT_NEAR(result.root2, -2.0, EPSILON);
}

TEST(quadratic_equation, test_10) {
  EquationResult result = solve_equation(2.0, -4.0, 0.0);
  ASSERT_EQ(result.num_roots, 2);
  ASSERT_NEAR(result.root1, 2.0, EPSILON);
  ASSERT_NEAR(result.root2, 0.0, EPSILON);
}

TEST(quadratic_equation, test_11) {
  EquationResult result = solve_equation(1.0, -3.0, 2.0);
  ASSERT_EQ(result.num_roots, 2);
  ASSERT_NEAR(result.root1, 2.0, EPSILON);
  ASSERT_NEAR(result.root2, 1.0, EPSILON);
}

TEST(quadratic_equation, test_12) {
  EquationResult result = solve_equation(1.0, -4.0, 4.0);
  ASSERT_EQ(result.num_roots, 1);
  ASSERT_NEAR(result.root1, 2.0, EPSILON);
  ASSERT_NEAR(result.root2, 2.0, EPSILON);
}

TEST(quadratic_equation, test_13) {
  EquationResult result = solve_equation(-2.0, 4.0, -5.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_14) {
  EquationResult result = solve_equation(NAN, -3.0, 2.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_15) {
  EquationResult result = solve_equation(1.0, NAN, 2.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_16) {
  EquationResult result = solve_equation(1.0, -3.0, NAN);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_17) {
  EquationResult result = solve_equation(INFINITY, -3.0, 2.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_18) {
  EquationResult result = solve_equation(1.0, INFINITY, 2.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_19) {
  EquationResult result = solve_equation(1.0, -3.0, INFINITY);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_20) {
  EquationResult result = solve_equation(-INFINITY, -3.0, 2.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_21) {
  EquationResult result = solve_equation(1.0, -INFINITY, 2.0);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_22) {
  EquationResult result = solve_equation(1.0, -3.0, -INFINITY);
  ASSERT_EQ(result.num_roots, 0);
}

TEST(quadratic_equation, test_23) {
  EquationResult result = solve_equation(1e-12, -2e-6, 1);
  ASSERT_EQ(result.num_roots, 1);
  ASSERT_NEAR(result.root1, 1e6, EPSILON);
  ASSERT_NEAR(result.root2, 1e6, EPSILON);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
