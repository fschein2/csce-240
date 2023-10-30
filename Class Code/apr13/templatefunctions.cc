// Copyright 2023 bhipp
// introduction to template functions
#include<iostream>
using std::cout;
using std::endl;

// int Average(int x, int y) { return (x + y) / 2; }
// double Average(double x, double y) { return ( x + y ) / 2; }
// char Average(char x, char y) { return ( x + y ) / 2; }

template<class T>  // this applies to the next thing that's defined
T Average(T x, T y) { return (x + y) / 2; }

template<class SomeType>  // SomeType applies to the Smaller function
                          // implementation
SomeType Smaller(SomeType a, SomeType b) {
  if ( a < b ) return a;
  return b;
}

int main() {
  int a = 2, b = 3;
  cout << Average(a, b) << endl;
  double c = 2, d = 3;
  cout << Average(c, d) << endl;
  cout << Average('e', 'g') << endl;
  float e = 2, f = 2.3;
  cout << Average(e, f) << endl;
  cout << Smaller(e, f) << endl;
  // the template function expects both arguments to be the same type, if
  // each argument could be cast as the other type, then a compilation error
  // will occur
  cout << Smaller(static_cast<float>(a), f) << endl;
  return 0;
}
