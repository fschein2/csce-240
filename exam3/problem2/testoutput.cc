// Copyright 2023 bhipp
// initial stream insertion operator tests for FactCheckedStatement class
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"factcheckedstatement.h"  // expected cpplint error message here
using namespace Project3Problem2;  // expected cpplint error message here

int main() {
  FactCheckedStatement fcs1("Whassup?");
  cout << fcs1 << endl;
  FactCheckedStatement fcs2("The semester just started.", -2.3);
  cout << fcs2 << endl;
  const FactCheckedStatement fcs3("The Gamecocks are the best.", 1);
  cout << fcs3 << endl;
  FactCheckedStatement fcs4("It is hot in Columbia in May.", 0.73);
  cout << fcs4 << endl;
  return 0;
}
