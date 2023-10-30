// Copyright 2023 fschein
// Introduction to Arrays in C++
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<iomanip>
using std::setw;
using std::setiosflags;

// write a print function for an array of doubles
void PrintArray( const double numbers[], int size ) {
  cout << setiosflags( std::ios::fixed | std::ios::showpoint );
  for ( int i = 0; i < size; ++i )
    cout << setw(10) << numbers[i];
}

// LinearSearch
// return type = int = the position of the search value in the array
int LinearSearch ( const double numbers[], int size, double search_value ) {
  int found_position = -1, i = 0;
  while( found_position == -1 && i < size )
    found_position = (numbers[i] == search_value ? i : -1);
  return found_position;

}

int main() {
  const int kArraySize = 5;  // Google style guide - begin constant
                             // variable names with a k
  const double fixed_values[3] = {3.14, 2.718};
  PrintArray(fixed_values, 2); // if the PrintArray function doesn't 
                               // have a const on the array parameter
                               // we won't be able to send it a 
                               // constant array

  // can declare and initialize in a single statement, if there are
  // fewer values in the list than the size, the remaining values
  // will be set to 0 (for an int, float, or double array)
  double some_doubles[kArraySize] = { 1.2, 3.7 };

  for ( int j = 0; j < kArraySize; ++j)
    some_doubles[j] *= 3;

  PrintArray( some_doubles, kArraySize );
  /* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  for ( int i = 0; i < kArraySize; ++i )
    cout << "some_doubles[" << i << "] = " << some_doubles[i] << " ";
  cout << endl;

  cout << some_doubles << endl;
  cout << some_doubles + 1 << endl;  // adding an integer to memory
  // location adds the int * size of what the memory location holds
  */
  
  // a character array, c-string
  // leaving the [] empty is the same as [5] in this example - 
  // an exact fit to the initialized values
  char word[] = "Word";  // same as {'W', 'o', 'r', 'd', '\0'}
  cout << word << endl;
  // the line above is equivalent to 
  int k = 0; 
  while (word[k] != '\0' )
    cout << word[k++];
  cout << endl;

  /*
  cout << "Enter a new word ";
  cin >> word;  // Danger! don't do this because if the input
                // is longer than the array, it will overstep the
                // array bounds
  cout << "The character array word now holds " << word << endl;
  */

  return 0;
}