// Copyright 2023 fschein
#include<iostream>
using std::cout;
using std::endl; // just like using statement for cout

int main() {
  cout << "I said, \"Hello World\"\n";
  /* the words in double quotes is known as a cstring not to be confused
  with String (which unlike java is not standard and must be imported) */

  cout << "What's up?" << endl;
  /* this is a string manipulator and not an escape character which means
  it must be used on its own */

  const int kConstant = 1;  //k in front of the variable is for google style guide for const vars

  int x, y, z;  // declaring threee integer values
  x = y = z = 13;  // initializes that varibles (commutes right to left)
  cout << "x = " << x << "\ny = " << y << "\nz = " << z << endl;

  return 0;
}
