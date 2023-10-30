// Copyright 2023 bhipp
// initial assignment operator tests for FactCheckedStatement class
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"factcheckedstatement.h"  // expected cpplint error message here
using namespace Project3Problem2;  // expected cpplint error message here

int main() {
  FactCheckedStatement fcs_bad1("I am eight feet tall.");
  fcs_bad1 = "yo";  // "yo" is not a valid statement so fcs_bad1 should remain
                    // unchanged by the operation.
  if ( fcs_bad1 == "I am eight feet tall."
       && fcs_bad1.GetTruth() == 0 ) {
    cout << "Passed bad value assignment test 1." << endl;
  } else {
    cout << "Failed bad value assignment test 1." << endl;
  }

  FactCheckedStatement fcs_bad2("I am eight feet tall.");
  fcs_bad2 = "Yippie!";  // "Yippie!" is not a valid statement (ends with an
                         // exclamation points). So, fcs_bad2 should remain
                         // unchanged by the operation.
  if ( fcs_bad2 == "I am eight feet tall."
       && fcs_bad2.GetTruth() == 0 ) {
    cout << "Passed bad value assignment test 2." << endl;
  } else {
    cout << "Failed bad value assignment test 2." << endl;
  }

  FactCheckedStatement fcs_good1("I am eight feet tall.");
  fcs_good1 = "Ice cream is not cold.";
  if ( fcs_good1 == "Ice cream is not cold."  && fcs_good1.GetTruth() == 0 ) {
    cout << "Passed good assignment test 1." << endl;
  } else {
    cout << "Failed good assignment test 1." << endl;
  }

  FactCheckedStatement fcs_good2("The book is a classic.", 0.3);
  fcs_good2 = "The politician is trustworthy.";
  if ( fcs_good2 == "The politician is trustworthy."
       && fcs_good2.GetTruth() == 0 ) { // note: the version of this file
     // initially uploaded checked for 0.3 instead of 0. As a result, the
     // assignment operator will be counted as correct if it leaves the truth
     // data member unchanger OR it resets it to 0.
    cout << "Passed good assignment test 2." << endl;
  } else {
    cout << "Failed good assignment test 2." << endl;
  }
  return 0;
}
