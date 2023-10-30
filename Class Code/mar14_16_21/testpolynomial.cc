// Copyright 2023 fschein
// test drive the functionality of the Polynomial class
#include<iostream>
using std::cout;
using std::endl;
#include"polynomial.h"

int main () {
  // day 3
  Polynomial::SetVariable('r');  // can call static function without
                                 // having an object 
  Polynomial p1(5);
  const Polynomial p2(3);
  cout << p1 << "\n" << p2 << endl;
  p1.SetVariable('z');  // this is changing static that belongs to
                        // the entire class
  p1[8] = 7;
  cout << p1 << "\n" << p2 << endl;
  cout << p2[10] << endl;
  cout << p1 + p2 << endl;

  // day 2
  /*
  Polynomial p1(2);
  const Polynomial p2(5);
  cout << p1[0] << endl;
  p1[2] = 1;
  p1[1] = 3;
  p1[0] = 6;
  p1[8] = 11;
  cout << p2 << endl;
  cout << p2[10] << endl;
  */
  
  // day 1
  /*
  cout << p1 << "\n" << p2 << endl;
  p1.SetDegree(3)
  cout << p1 << endl;
  p2 = p1;  // if we don't overload this ourselves - this will do a member-wise
            // copy of the data members
            // when we have a pointer as a data member, we need to overload
            // the operator to ensure that two object's data members don't
            // point to the same location
  Polynomial p3 = p2;  // for the same reason, we need to write a copy constructor
  
  cout << p1 << endl;
  cout << p2 << endl;
  p1.SetDegree(5);
  cout << p1 << endl;
  cout << p2 << endl;
  p2.SetDegree(10);
  cout << p2 << endl;
  cout << p3 << endl;
  */

  return 0;
}