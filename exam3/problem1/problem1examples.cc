// Copyright 2023 bhipp
// check the initial examples provided for problem 2 on project/exam 3
#include<iostream>
using std::cout;
using std::endl;
#include"problem1.h"

int main() {
  const int intarray[5] = {17, 22, 7, 4, 30};
  int x = Project3Problem1::Median(intarray, 5);
  if ( x == 17 )
    cout << "passed example test 1" << endl;
  else
    cout << "failed example test 1" << endl;
  const double doublearray[6] = {-1, -4.6, -8, 2, 8.9, 37.1};
  double y = Project3Problem1::Median(doublearray, 6);
  if ( y == 0.5 )
    cout << "passed example test 2" << endl;
  else
    cout << "failed example test 2" << endl;
  return 0;
}
