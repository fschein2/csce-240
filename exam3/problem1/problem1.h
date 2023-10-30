// Copyright 2023 fschein
// problem 1
#ifndef _PROBLEM_1_H_
#define _PROBLEM_1_H_

namespace Project3Problem1 {

template<class T>
T Median(const T array[], int size) {
  T n[size];
  for (int i = 0; i < size; ++i) {
    n[i] = array[i];
  }

  for ( int sorted = 1; sorted < size; ++sorted ) {
    int next = sorted;
    while ( n[next] < n[next - 1] && next > 0 ) {
      T temp = n[next - 1];
      n[next - 1] = n[next];
      n[next] = temp;
      --next;
    }  // end while loop
  }  // end for loop

  if ( size % 2 == 1 ) {
    size  = size / 2;
    return n[size];
  }

  size = size / 2;
  return ( n[size] + n[size - 1] ) / 2;
}

}

#endif  // _PROBLEM_1_H_