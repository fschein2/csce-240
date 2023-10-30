// Copyright 2023 fschein
// Loops and Functions
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<cstdlin> // rand, srand
#include<ctime> // system clock

// function to return a random number between 1 and 6
// function prototype: 
int dice(); // allows us to not worry about where dice() is located
            // in this case it is not needed because dice() is written
            // before it is called

// function implementation
int dice() {
  srand( time(0) ); // seed the random function with the current time
                    // in order to get a different list of values each
                    // time the program runs
  return rand() % 6 + 1 // "% 6 + 1" sets the list of random
                        // numbers from 1 to 6
}

int main() {
  for ( int k = 1; k < 10; ++k )
    cout << dice() << endl;

  int stopping_point;
  do {
    cout << "Enter a positive integer. ";
    cin >> stopping_point;
  } while ( stopping_point < 1 );

  int i = 1;
  while ( i <= stopping_point ) {
    cout << i++ << "\n";
    // i += 1; // i = i + 1; ++i, i++;
  }

  for ( int j = 1; j <= stopping_point; ++j )
    cout << j << "\n";

  cout << "At the end of main, i = " << i
  // cout << " and j = " << j << endl;
  // j is not visible outside of the for loop
  
  return 0;
}
