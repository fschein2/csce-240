// Copyright 2023 fschein
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<iomanip>
#include<cmath> // contains a lot of mathematical functions 
                // double pow(double base, double exponent)
                // double sqrt(double)
                // ceil(double)
                // floor(double)

#include"myfunctions.h" // I can now include this header file
                        // in any c++ file that needs to use one
                        // of the functions I've written in it

// write our own function to round to the nearest integer
int RoundToInteger(double); // function prototype

int main() {
  // Functions
  double x;
  cout << "Enter a real number ";
  cin >> x;
  cout << RoundToInteger(x) << endl;
  

  // cmath example
  /*
  cout << pow( 2, 7 ) << endl;
  cout << sqrt( 5 ) << endl;
  cout << ceil( 2.4 ) << endl; // 3
  cout << floor ( 2.4 ) << endl; // 2
  */
  
  // iomanip example
  /* 
  double x;
  cout << "Enter a real number ";
  cin >> x;
  cout << x << endl;
  cout << std::setprecision(3);
  cout << x << endl;
  cout << std::setiosflags( std::ios::showpoint | std::ios::fixed )
  cout << x << endl;
  cout << std::setw(8) << x << endl;
  double y = 12.6;
  cout << std::setw(8) << y << endl;
  cout << x << endl;
  */

  return 0;
}
