// Copyright 2023 fschein
// implement the member functions for our template Set class
#include"set.h"

namespace csce240_set {

  // preconditions: values points to a block of memory with at least
  //                size values
  template<class TheType>
  void Set<TheType>::SetValues(int new_size, const TheType * new_values) {
    if ( new_size < 0 )
      return;
    if ( new_size != size_ ) {
      if ( size_ != 0 )  // if (values_ != nullptr)
        delete [] values_;
      if ( new_size == 0 )
        values_ = nullptr;
      else
        values_ = new TheType[new_size];
    }
    size_ = new_size;
    for ( int i = 0; i < size_; ++i )
      values_[i] = new_values[i];
  }
  
  template<class TheType>
  void Set<TheType>::Print() const {
    cout << "{";
    for ( int i = 0; i < size_; ++i )
      cout << values_[i] << (i < size_ - 1 ? ", " : "");
    cout << "}" << endl;
  }

  template<class TheType>
  Set<TheType>::Set(const Set& tocopy) {
    size_ = 0;
    values_ = nullptr;
    SetValues(tocopy.size_, tocopy.values_);
  }

  template<class TheType>
  Set<TheType> Set<TheType>::operator = (const Set& tocopy) {
    SetValues(tocopy.size_, tocopy.values_);
    return *this;
  }

}  // namespace csce240_set