// Copyright 2023 fschein
// define the Square class
#ifndef _SQUARE_H_
#define _SQUARE_H_

#include"rectangle.h"
#include<iostream>
using std::ostream;

namespace csce240_shapes {
  class Square : public Rectangle {
     friend ostream& operator << (ostream& whereto, const Square& s);
   public:
    explicit Square(double s);
    // redefining the SetWidth and SetLength functions
    void SetWidth(double s);
    void SetLength(double s);
  };  // end class Square
}  // end namespace csce240_shapes

#endif  // _SQUARE_H_