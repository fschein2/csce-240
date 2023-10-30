// Copyright 2023 fschein
// define the Temperature class
#ifndef _TEMPERATURE_H_
#define _TEMPERATURE_H_

#include<string>  // string class defined in the standard library
using std::string;  // string is in the std namespace

class Temperature {
 public:
  // constructor
  // if a constructor can be called with a single argument, we'll make the 
  // constructor explicit to ensure that it's only called if we explicitly
  // ask for it to be called (Temperatures won't be created out of doubles
  // without us specifically called the constructor)
  explicit Temperature(double v = 0, string u = "Celsius");
  // destructor - no return type, name = ~classname()
  ~Temperature();

  // mutator function
  void SetValue(double v);
  void SetUnits(string u);

  // accessor functions
  double GetValue() const { return value_; }
  string GetUnits() const { return units_; }

  // convert from one usit of measure to another
  void Convert(string newunits);

  void Print() const;
 private:
  double value_;
  // using an object of one class as a data member in another
  // class is called "composition"
  // one class "has a(n)" object of another class as a data member
  string units_;  // Fahrenheit, Celsius, Kelvin
};

#endif // end _TEMPERATURE_H_