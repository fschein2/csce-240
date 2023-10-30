// Copyright 2023 fschein
// implement the functions in mynumericfunctions header file
#include"mynumericfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<cmath>

int Factorial(int n) {
  int total = 1;
  if ( n < 0 ) {
    cout << "Factorial is not defined for negative integers" << endl;
    total = 0;
  }
  for ( int i = 2; i <= n; ++i )
    total *= i;
  return total;
}

bool QuadraticFormula(double a, double b, double c, double& root1,
                      double& root2) {
  double discriminant = b * b - 4 * a * c;
  if ( discriminant < 0 )
    return false;
  root1 = (-1 * b + sqrt(discriminant)) / (2 * a);
  root2 = (-1 * b - sqrt(discriminant)) / (2 * a);
  return true;
}

double Average(double x, double y) {
  return (x + y) / 2;
}

double Average(double x, double y, double z) {
  return (x + y + z) / 3;
}

char Average(char a, char b) {
  return (a + b) / 2;
}

double Average(double a, double b, double c, double d, double e) {
  return (a + b + c + d + e) / 5;
}

int Fibonacci(int which ) {
  if ( which < 2 )
    return 1;
  else
    return Fibonacci(which - 1) + Fibonacci(which - 2);
}