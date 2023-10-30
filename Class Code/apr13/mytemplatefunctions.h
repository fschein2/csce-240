// Copyright 2023 bhipp
// Template functions 2
#ifndef _MY_TEMPLATE_FUNCTIONS_H_
#define _MY_TEMPLATE_FUNCTIONS_H_

namespace MyTemplateFunctions {

// implement these template functions in the header file - not a source
// file to give object to our user since the object code can't anticipate
// all possible versions for overloading
template<class T>
void TradeValues(T& x, T& y) {
  T temp = x;
  x = y;
  y = temp;
}

template<class T>
void QuickSort(T thevalues[], int bottom, int top) {
  if ( bottom >= top ) return;
  int i = bottom + 1, j = top;
  while ( i < j ) {
    while ( i < top && thevalues[i] <= thevalues[bottom] )
      ++i;
    while ( j > bottom && thevalues[j] >= thevalues[bottom] )
      --j;
    if ( i < j )
      TradeValues(thevalues[i], thevalues[j]);
  }
  if ( thevalues[bottom] > thevalues[j] )
    TradeValues(thevalues[bottom], thevalues[j]);
  QuickSort(thevalues, bottom, j-1);
  QuickSort(thevalues, j+1, top);
}  // QuickSort

}  // namespace MyTemplateFunctions

#endif

