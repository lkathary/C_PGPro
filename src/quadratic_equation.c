#include "quadratic_equation.h"

#include <math.h>

EquationResult solve_equation(double a, double b, double c) {
  EquationResult result;

  if (a == INFINITY || b == INFINITY || c == INFINITY || a == -INFINITY ||
      b == -INFINITY || c == -INFINITY || a != a || b != b || c != c) {
    // Degenerate coefficients, no roots
    result.num_roots = 0;
    result.root1 = result.root2 = 0;
    return result;
  }

  if (fabs(a) < EPSILON) {
    if (fabs(b) < EPSILON) {
      if (fabs(c) < EPSILON) {
        // Equation 0 = 0, infinite roots
        result.num_roots = -1;
        result.root1 = result.root2 = 0;
      } else {
        // Equation c = 0, at the same time c != 0, no roots
        result.num_roots = 0;
        result.root1 = result.root2 = 0;
      }
    } else {
      // Linear equation bx + c = 0, one real root
      result.num_roots = 1;
      result.root1 = result.root2 = -c / b;
    }
  } else {
    double discriminant = b * b - 4 * a * c;
    if (discriminant > EPSILON) {
      //  Two distinct real roots
      result.num_roots = 2;
      result.root1 = (-b + sqrt(discriminant)) / (2 * a);
      result.root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (fabs(discriminant) < EPSILON) {
      //  One real root
      result.num_roots = 1;
      result.root1 = result.root2 = -b / (2 * a);
    } else {
      //  No roots
      result.num_roots = 0;
      result.root1 = result.root2 = 0;
    }
  }

  return result;
}
