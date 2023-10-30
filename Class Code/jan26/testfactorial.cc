// Copyright 2023 fschein
// test the Factorial function
#include<iostream>
using std::cout;
using std::endl;
#include"mynumericfunctions.h"

int main() {
  int x = 4;
  if ( Factorial(x) == 24 ) {
    if ( x == 4 ) {
      cout << "Passed Factorial(x) test " << endl;
    } else {
     cout << "Failed Factorial(x) test " << endl;
    }
  } else {
    cout << "Failed Factorial(4) test" << endl;
  }

  if ( Factorial(0) == 1 )
    cout << "Passed Factorial(0) test" << endl;
  else
    cout << "Failed Factorial(0) test" << endl;

  if ( Factorial(5) == 120 )
    cout << "Passed Factorial(5) test" << endl;
  else
    cout << "Failed Factorial(5) test" << endl;

  if ( Factorial(-4) == 0 )
    cout << "Passed invalid argument test - Factorial(-4)" << endl;
  else
    cout << "Failed invalid argument test - Factorial(-4)" << endl;
  return 0;
}