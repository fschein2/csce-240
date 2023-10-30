// Copyright 2023 fschein
// define a Length class that has a double for the value and a string for
// the units as private data members. The value should always be non-negative,
// and the units should always hold either "inches" or "centimeters"
#ifndef _LENGTH_H_
#define _LENGTH_H_

#include<string>
using std::string;
#include<iostream>
using std::ostream;

class Length {
  // Overload the << operator to output a Length object.
  // For example,
  //    Length l3(4, "centimeters");
  //    cout << l3;  should output "4 centimeters" to the standard output device
  friend ostream& operator << (ostream& whereto, const Length& l);

 public:
  // add constructor that takes a double parameter for the value and a string
  // parameter for the units, with default arguments of 0 and "inches"
  // If a negative number is sent for the value, the value should be set to 0.
  // If an invalid string is sent for the units, the units should be set to
  // "inches"
  explicit Length(double v = 0, string u = "inches");

  // write a SetUnits function that takes a string parameter for the units
  // If the argument is invalid, leave the units data member unchanged.
  void SetUnits(string u);

  // write a SetValue function that takes a double parameter for the value
  // If the argument is negative, leave the value data member unchanged
  void SetValue(double v);

  // Write GetValue and GetUnits functions that return copies of the values
  // of the two private data members
  double GetValue() const { return value_; }
  string GetUnits() const { return units_; }

  // Write a Convert function that takes a string as a parameter.
  // If the string argument is a valid unit, then update the value and units
  // data members to hold the value in the updated units.
  // For example,
  //    Length l1(2, "inches");
  //    11.Convert("centimeters"); // l1 should now hold 5.08 centimeters
  void Convert(string u);

  // Overload the + operator to add two Length objects and return the sum of
  // the two lengths. The units for the returned Length object should be the
  // same as the left operand.
  // For example,
  //    Length l1(2, "inches"), l2(2.54, "centimeters");
  //    l1 + l2 should return 3 inches
  //  and
  //    l2 + l1 should return 7.62 centimeters
  Length operator + (const Length right) const;

  // Overload the == operator to compare two Length objects.
  // For example, 2 inches == 5.08 centimeters should return true.
  bool operator == (const Length right) const;

  // Overload the < operator to compare two Length objects.
  // For example, 2 inches < 6 centimeters should return true.
  bool operator < (const Length right) const;

 private:
  double value_;  // non-negative
  string units_;  // inches or centimeters
};
#endif  // _LENGTH_H_