// Copyright 2023 fschein
#ifndef _MYNUMERICFUNCTIONS_H_
#define _MYNUMERICFUNCTIONS_H_

// prototype for a function
// precondition: we expect the argument to be a non-negative int
// postcondition: function returns n!
//                if the argument is negative, the function returns
//                0 and outputs a message to the standard output
//                device
int Factorial(int n);

// function to find the roots of a quadratic using the
// quadratic formula
// Preconditions: function is sent the coefficient of x^2,
//                the coefficient of x and the constant
//                coefficient for a quadratic polynomial
//                followed by two variables to hold the roots
// Postconditions: The function will return true if the quadratic has
//                 root(s) and false if not
//                 if the quadratic has real roots the
//                final two arguments will hold those values
bool QuadraticFormula(double a, double b, double c, double& root1,
                      double& root2);

// average function that finds the average of two doubles
double Average(double, double);
// average function that finds the average of three doubles
double Average(double, double, double);
// average function that finds the average of two characters
char Average(char, char);
// average function that takes 5 double arguments and returns their average,
// defaulting the 5th to 0 if it's left off
double Average(double, double, double, double, double=0);

// Fibonacci sequence - 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
int Fibonacci(int which);

#endif  //_MYNUMERICFUNCTIONS_H_