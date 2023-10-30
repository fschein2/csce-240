// Copyright 2023
// implement functions in somefunctions.h
#include "somefunctions.h"  // cpplint will say use full path
                            // we're not worried about that at the moment

double median(double x, double y) {
  return ( x + y ) / 2;
}

double median(double x, double y, double z) {
  double small = x, large = x;
  if ( y < small ) 
    small = y;
  if ( z < small )
     small = z;
  if ( y > large )
    large = y;
  if ( z > large )
    large = z;
  return x + y + z - small - large;
}
