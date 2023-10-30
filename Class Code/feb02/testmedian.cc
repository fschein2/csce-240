// Copyright 2023
// test median functions
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"somefunctions.h"  // expected cpplint message about path

int main() {
  cout << median(2, 3) << endl;
  double a, b, c;
  cout << "Enter three numbers ";
  cin >> a >> b >> c;
  cout << "The median of " << a << ", " << b << ", and " << c
      << " is " << median(a, b, c) << endl;
  return 0;
}
