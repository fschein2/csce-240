// Copyright 2023 fschein
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#include"mynumericfunctions.h"

int main() {
  double a, b, c, r1 = -1, r2 = -1;
  cout << "Enter the coefficients of the quadratic" << endl;
  cin >> a >> b >> c;
  if ( QuadraticFormula(a, b, c, r1, r2 ) )
    cout << "Real roots! " << r1 << " and " << r2 << endl;
  else
    cout << "Imaginary roots (r1 and r2 unchanged - " << r1 << " " << r2
         << ")" << endl;
  return 0;
}