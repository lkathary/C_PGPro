#include <stdio.h>

#include "quadratic_equation.h"

int main() {
  double a = 1.0;
  double b = -3.0;
  double c = 2.0;

  QuadraticResult result = solve_equation(a, b, c);

  if (result.num_roots == 2) {
    printf("Equation has two roots:\n");
    printf("Root 1: %.2f\n", result.root1);
    printf("Root 2: %.2f\n", result.root2);
  } else {
    printf("Equation does not have two roots.\n");
  }

  return 0;
}
