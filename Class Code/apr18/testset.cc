// Copyright 2023 fschein
#include"set.h"
// IF you implement the member functions in a source file (separate from
// the header file) then you'll have to include the source file whenever
// the class is used. This will give us a cpplint error that we'll have
// to ignore
#include"set.cc"
using namespace csce240_set;

int main() {
  Set<int> s1;

  Set<double> s2;

  return 0;
}