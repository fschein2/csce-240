// Copyright 2023 fschein
// Define the Set Template class
#ifndef _SET_H_
#define _SET_H_
// set - unordered (order doesn't matter) collection of distinct (no dups)
//       objects
#include<iostream>
using std::cout;
using std::endl;

namespace csce240_set {

template<class TheType>
class Set {
 public:
  Set() {
    size_ = 0;
    values_ = nullptr;
  }

  ~Set() {
    if ( values_ != nullptr )
      delete [] values_;
  }

  // copy constructor
  Set(const Set& tocopy );

  //assignment operator
  Set operator = (const Set& tocopy);

  void SetValues(int new_size, const TheType * new_values);

  void Print() const;

 private:
  int size_;  // cardinality / cardinal number
  TheType * values_;  // pointer to a block of memory with the values
                      // that are in the set
};  // class Set

}  // namespace csce240_set


#endif  // _SET_H_