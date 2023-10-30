// Copyright 2023 bhipp
// initial SetTruth tests for FactCheckedStatement class
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"factcheckedstatement.h"  // expected cpplint error message here
using namespace Project3Problem2;  // expected cpplint error message here

int main() {
  FactCheckedStatement fcs_bad1("I am eight feet tall.");
  fcs_bad1.SetTruth(10);  // attempting to set the data member to a value
  // greater than 1 should leave the data member unchanged.
  if ( fcs_bad1 == "I am eight feet tall."
       && fcs_bad1.GetTruth() == 0 ) {
    cout << "Passed mutator bad value test 1." << endl;
  } else {
    cout << "Failed mutator bad value test 1." << endl;
  }

  FactCheckedStatement fcs_bad2("I am eight feet tall.");
  fcs_bad2.SetTruth(-4);  // attempting to set the data member to a value
  // less than 0 should leave the data member unchanged.
  if ( fcs_bad2 == "I am eight feet tall."
       && fcs_bad2.GetTruth() == 0 ) {
    cout << "Passed mutator bad value test 2." << endl;
  } else {
    cout << "Failed mutator bad value test 2." << endl;
  }

  FactCheckedStatement fcs_good1("I am eight feet tall.");
  fcs_good1.SetTruth(0.6);
  if ( fcs_good1 == "I am eight feet tall."  && fcs_good1.GetTruth() == 0.6 ) {
    cout << "Passed mutator good value test 1." << endl;
  } else {
    cout << "Failed mutator good value test 1." << endl;
  }

  FactCheckedStatement fcs_good2("The book is a classic.", 0.3);
  fcs_good2.SetTruth(1);
  if ( fcs_good2 == "The book is a classic." && fcs_good2.GetTruth() == 1 ) {
    cout << "Passed mutator good value test 2." << endl;
  } else {
    cout << "Failed mutator good value test 2." << endl;
  }
  return 0;
}
