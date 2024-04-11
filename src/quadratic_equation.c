#include "quadratic_equation.h"

#include <math.h>

//  #define EPSILON 1e-6

QuadraticResult solve_equation(double a, double b, double c) {
  QuadraticResult result;

  if (fabs(a) < EPSILON && fabs(b) < EPSILON && fabs(c) < EPSILON) {
    result.num_roots = -1;  // Infinite roots
    result.root1 = 0;
    result.root2 = 0;
  } else {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > EPSILON) {
      result.num_roots = 2;
      result.root1 = (-b + sqrt(discriminant)) / (2 * a);
      result.root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (fabs(discriminant) < EPSILON) {
      result.num_roots = 1;
      result.root1 = -b / (2 * a);
      result.root2 = result.root1;
    } else {
      result.num_roots = 0;
      result.root1 = 0;
      result.root2 = 0;
    }
  }

  return result;
}
