// Copyright 2023 fschein
// arithmetic operators, cin, decisions, case
#include<iostream>
using std::cout;
using std::endl;
using std::cin; // object for accepting input from the standard input device

int main() {
  /*
  int x, y;
  double z;
  cout << "Enter two integer values: ";
  cin >> x >> y; // equivalent to cin >> x; and cin >> y;
  cout << "x / y = " << x / y << endl;
  cout << "x % y = " << x % y << endl;
  z = x / static_cast<double>(y);
  cout << "z = " << z << endl;
   
  int num1 = 3, num2= 3;
  cout << "++num1 = " << ++num1;
  cout << "\n after the statement num1 = " << num1;
  cout << "\nnum2++ = " << num2++;
  cout << "\n after the statement num2 = " << num2 << endl;
  */
  
  /*
  double grade;
  cout << "Enter your numeric grade ";
  cin >> grade;
  if ( grade > 59.5 )
    cout << "You passed\n";
  else
    cout << "You didn't pass\n";
  
  // ?: conditional operator
  // logical expression ? true side : false side
  cout << "You" << (grade >= 59.5 ? " " : " didn't ") << "pass\n";
  */

  char choice;
  cout << (E)nglish, (S)panish ";
  cin >> choice;
  switch(choice) {
    case 'E':
    case 'e':
      cout << "Hello";
      break;
    case 'S':
    case 's':
      cout << "Hola";
      break;
    default:
      cout "Invalid";
  }
  return 0;
}
