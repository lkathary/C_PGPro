#ifndef SRC_QUADRATIC_EQUATION_H_
#define SRC_QUADRATIC_EQUATION_H_

#define EPSILON 1e-6

typedef struct {
  int num_roots;  //  -1  Infinite roots
  double root1;
  double root2;
} EquationResult;

EquationResult solve_equation(double a, double b, double c);

#endif  // SRC_QUADRATIC_EQUATION_H_
