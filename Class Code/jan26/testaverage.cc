// Copyright 2023 fschein
// test the overloaded Average fucntions
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"mynumericfunctions.h"

int main() {
  cout << "Average(2.3, 5.7, 6.1) = " << Average(2.3, 5,7, 6.1) 
       << endl;
  cout << "Average(2.3, 5.7) = " << Average(2.3, 5.7) << endl;
  cout << "Average('a', 'c') = " << Average('a', 'c') << endl;

  // cout << "Average('a', 5.0) = " << Average('a', 5.0) << endl;
  // does not work because we don't have char and double
  // cout << "Average(3, 4) = " << Average(3, 4) << endl;
  // does not work because int can be cast as double or char
  // we confuse the compiler it is "ambigious"

  cout << "Average(1.2, 1.3, 1.9, 3.7, 8.6) = " 
       << Average(1.2, 1.3, 1.9, 3.7, 8.6) << endl;
  cout << "Average(1.2, 1.3, 1.9, 3.7) = "
       << Average(1.2, 1.3, 1.9, 3.7) << endl;

  // *ALSO* include fibonacci test
  int x;
  cout << "Which Fibonacci number do you want? ";
  cin >> x;
  double start = clock();
  cout << Fibonacci(x) << "\ntook " << (clock() - start)
       << " milliseconds" << endl;

  return 0;
}