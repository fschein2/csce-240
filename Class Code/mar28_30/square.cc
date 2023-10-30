// Copyright 2023 fschein
// implement the functionality of the square class
#include"square.h"
#include"rectangle.h"
#include<iostream>
using std::ostream;

namespace csce240_shapes {
  ostream& operator << (ostream& whereto, const Square& s) {
    whereto << "Square: ";
    // the line below is completely valid to cast a derived class 
    // object as a base class object to use the base class version
    // of the << operator (just commenting it out because the output
    // looks weird in this example)
    // whereto << static_cast<Rectangle>(s);
    whereto << "sides = " << s.GetLength();
    return whereto;
  }

  // important to call the base class constructor in the derived class
  // constructor's member initializer list to set up the base class members
  // correctly before entering the body of the derived class constructor
  Square::Square(double s) : Rectangle(s, s) {
    // length_ = width_ = s;  CAN'T ACCESS private members of the base class
    //                        directly
    // SetLength(s);  - no longer necessary if we call the Rectangle 
    // SetWidth(s);     constructor as above
  }

  void Square::SetWidth(double s) {
    // call the base class version of these redefined fucntions using the
    // base class name and scope resolution operator
    Rectangle::SetLength(s);
    Rectangle::SetWidth(s);
  }

  void Square::SetLength(double s) {
    // call the base class version of these redefined fucntions using the
    // base class name and scope resolution operator
    Rectangle::SetLength(s);
    Rectangle::SetWidth(s);
  }

}  // end namespace csce240_shapes