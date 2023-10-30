// Copyright 2023 fschein
// test drive the Rectangle class
#include<iostream>
using std::cout;
using std::endl;
//#include"rectangle.h"
#include"square.h"
using namespace csce240_shapes;

void PrintSquare(const Square& s) {
  for ( int i = 0; i < s.GetLength(); ++i )
    cout << "*";
  for ( int i = 0; i < s.GetLength() - 2; ++i) {
    cout << "\n*";
    for ( int j = 0; j < s.GetLength() - 2; ++j)
      cout << " ";
    cout << "*\n";
  }
  for ( int i = 0; i < s.GetLength(); ++i )
    cout << "*";
  cout << endl;
}

int main() {
  Rectangle r;
  cout << r << endl;
  r.SetWidth(4.2);
  cout << r << endl;
  Square s(5);  // calls Square constructor - Rectangle constructor
                // executes before the body of the Square constructor
  cout << s << endl;
  s.SetWidth(3);
  cout << s << endl;
  PrintSquare(s);
  // PrintSquare(7);
  PrintSquare(Square(7));
  return 0;
}