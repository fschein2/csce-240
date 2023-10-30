// Copyright 2023 fschein
// Merge function implemented by fschein
// Print function implemented by bhipp
#include"pointerproblemfunctions.h"
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setw;

// do not modify the implementation of the Print function
void Print(const SortedDynamicArray * nums) {
  for ( int i = 0; i < nums->size; ++i )
    cout << setw(4) << nums->values[i];
  cout << endl;
}

// implement the Merge function (described in pointerproblemfunctions.h) here
void Merge(SortedDynamicArray * const array1,
           const SortedDynamicArray * const array2) {
  // Determine the size of the new array by counting
  // distinct values within each array
  int newSize = 0;
  int i = 0;  // associated with array1
  int j = 0;  // associated with array2
  while (i < array1->size && array2->size) {
    if ( array1->values[i] < array2->values[j] ) {
      ++newSize;
      ++i;
    } else if ( array1->values[i] > array2->values[j] ) {
        ++newSize;
        ++j;
    } else if ( array1->values[i] == array2->values[j] ) {
        ++newSize;
        ++i;
        ++j;
    }
  }
  for (int s = i; s < array1->size; ++s)
    ++newSize;
  for (int s = j; s < array2->size; ++s)
    ++newSize;

  // Properly merge the two arrays
  int *newVals = new int[newSize];
  i = 0;
  j = 0;
  int k = 0;  // associated with newVals
  while (i < array1->size && array2->size) {
    if ( array1->values[i] < array2->values[j] ) {
      newVals[k] = array1->values[i];
      ++i;
      ++k;
    } else if ( array1->values[i] > array2->values[j] ) {
        newVals[k] = array2->values[j];
        ++j;
        ++k;
    } else if ( array1->values[i] == array2->values[j] ) {
        newVals[k] = array1->values[i];
        ++i;
        ++j;
        ++k;
    }
  }
  for (int s = i; s < array1->size; ++s) {
    newVals[k] = array1->values[s];
    ++k;
  }
  for (int s = j; s < array2->size; ++s) {
    newVals[k] = array2->values[s];
    ++k;
  }

  delete[] array1->values;
  array1->values = newVals;
  array1->size = newSize;
}