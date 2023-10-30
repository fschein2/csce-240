// Copyright 2023 fschein
// Introduction to Structure Types
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

// defining a two-dimensional point in the cartesian plane
struct Point {
  // default access is public
  double x;
  double y;
};

int main() {
  Point some_point, some_other_point;
  cout << "Enter the x and y coordinates of the first point: ";
  cin >> some_point.x >> some_point.y;
  cout << "Enter the x and y coordinates of the second point: "
  cin >> some_other_point.x >> some_other_point.y;
  cout << "The points are (" << some_point.x << ", " << some_point.y 
       << ") and" << " (" << some_other_point.x << ", " 
       << some_other_point.y << ")" << endl;
  
  Point * pointpointer = &some_point;
  // can access public members on a pointer either by dereferencing 
  // and using the dot operator, or equivalently using the arrow operator
  cout << "accessing the x coordinate " << (*pointpointer).x << "\n"
       << pointpointer->x << endl;

  Point bunch_of_points[5];
  cout << "Enter 5 points ";
  for ( int i = 0; i < 5; ++i)
    cin >> bunch_of_points[i].x >> bunch_of_points[i].y;
    
  return 0;
}