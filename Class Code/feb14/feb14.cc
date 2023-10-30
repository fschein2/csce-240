// Copyright 2023 fschein
// More with arrays in C++
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstdlib> // for srand
#include<ctime> // for time
#include<iomanip> // for setw

// MULTIPLE SUBSCRIPTED ARRAYS
int main() {
  const int kRows = 4, kCols = 7;
  int my_big_array[kRows][kCols] = {{1, 2}, {3}, {-4, 5}}
  for ( int r = 0; r < kRows; ++r ) {
    for ( int c = o; c < kCols; ++c ) {
      cout << std::setw(5) << my_big_array[r][c];
    }
    cout << endl;
  }
  cout << my_big_array[1][7] << endl;
  // equivalent to my_big_array[2][0]

  for ( int i = 0; i < kRows * kCols; ++i )
    cout << std::setw(5) << my_big_array[0][i] 
         << ( ( i + 1 ) % kCols == 0? "\n" : "");

  const int kDepth = 3;
  int even_bigger_array[kRows][kCols][kDepth] = {0};
  
  cout << even_bigger_array[2][3][4];
  // 2 * 28 + 3 * 7 + 4

  return 0;
}

/* ARRAYS SEARCHING AND SORTING
// Populate function will fill the array with "random" integers
void Populate( int n[], int size );
// Print function will output the values to the standard output device
void Print( const int n[], int size );
// Insertiion Sort - N^2 average and worst case sort method with an 
//                   awesome N best case
void InsertionSort( int n[], int size );
// BinarySearch - only works on sorted arrays - returns position of the
// found value or -1 if the value is not in the array
int BinarySearch( const int n[], int search_value, int top, int bottom = 0 );

int main() {
  srand(time(0));
  const int kSize = 15;
  int my_array[kSize] = { };
  Print(my_array, kSize);
  Populate(my_array, kSize);
  Print(my_array, kSize);
  InsertionSort(my_array, kSize);
  Print(my_array, kSize); 
  int lookin4;
  cout << "What are you looking for? ";
  cin >> lookin4;
  cout << BinarySearch(my_array, lookin4, kSize-1) << endl;
  return 0;
}

void Print( const int n[], int size) {
  for ( int i = 0; i < size; ++i )
    cout << std::setw(5) << n[i];
  cout << endl;
}

void populate ( int n[], int size ) { 
  for ( int i = 0; int < size, ++i )
    n[i] = rand() % 100;
}

void InsertionSort( int n[], int size ) {
  for ( int sorted = 1; sorted < size; ++ sort ) {
    int next = sorted;  // this is the position of the next item to insert
                        // in the sorted sub-array

    // find where this value needs to be added
    while ( n[next] < n[next - 1] && next > 0 ) {
      int temp = n[next - 1];  // swap the new value with the one before it
                               // if it's smaller than the one before it
      n[next - 1] = n[next];
      n[next] = temp;
      --next;
    }  // end while loop
  }  // end for loop
}  // end InsertionSort

int BinarySearch(const int n[], int search_value, int top, int bottom) {
  int middle = (bottom + top) / 2;
  if ( n[middle] == search_value )
    return middle;
  if ( top <= bottom )
    return -1;
  if ( n[middle] > search_value )
    return BinarySearch(n, search_value, middle - 1, bottom);
  return BinarySearch (n, search_value, top, middle + 1);
}
*/