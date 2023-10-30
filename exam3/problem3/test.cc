#include"set.h"
#include<iostream>
using std::cout;
using std::endl;

using namespace Project3Problem3;

int main() {
  int n[3] = {1, 2, 3};
  int h[3] = {2, 1, 3};
  int x[4] = {1, 2, 3, 4};
  int y[3] = {1, 2, 4};

  Set<int> s1;
  s1.SetValues(3, n);

  Set<int> s2;
  s2.SetValues(3, h);

  Set<int> s3;
  s3.SetValues(4, x);

  Set<int> s4;
  s4.SetValues(3, y);

  if (s1 == s2)
    cout << "true" << endl;
  if (s1 == s3)
    cout << "false1" << endl;
  if (s1 == s4)
    cout << "false2" << endl;

  return 0;
}