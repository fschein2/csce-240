// Copyright 2023 fschein
// test drive the Temperature class
#include"temperature.h"
#include<iostream>
using std::cout;
using std::endl;

int main() {
  // NOTE: to call the defult constructor, don't put parenthesis after
  //       the object name - if you do, the compiler thinks you're defining
  //       a new function
  Temperature t;  // instantiate an object of the Temperature class
  cout << t.GetValue() << " " << t.GetUnits() << endl;
  t.SetValue(72);
  t.SetUnits("Fahrenheit");
  cout << t.GetValue() << " " << t.GetUnits() << endl;

  // to call constructor with initial values, send in parenthesis
  Temperature t2(60), t3(80, "Fahrenheit");
  cout << t2.GetValue() << " " << t2.GetUnits() << endl;
  cout << t3.GetValue() << " " << t3.GetUnits() << endl;
  t3 = t;  // if we don't overload the assignment operator, = will perform
           // a memberwise copy (if we have pointers as data members, this
           // would be bad)
  cout << t3.GetValue() << " " << t3.GetUnits() << endl;

  Temperature t4 (100, "Celsius");
  t4.Print();
  t4.Convert("Fahrenheit");
  t4.Print();
  t4.Convert("Kelvin");
  t4.Print();
  t4.Convert("Fahrenheit");
  t4.Print();
  t4.Convert("Celsius");
  t4.Print();

  return 0;
}