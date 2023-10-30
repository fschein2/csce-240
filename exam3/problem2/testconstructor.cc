// Copyright 2023 bhipp
// initial constructor and GetTruth tests for FactCheckedStatement class
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"factcheckedstatement.h"  // expected cpplint error message here
using namespace Project3Problem2;  // expected cpplint error message here

int main() {
  const FactCheckedStatement fcs_bad1("yo.");  // Argument doesn't begin with
  // an uppercase character so the object should hold the default statement.
  if ( fcs_bad1 == "This is an unverified statement."
       && fcs_bad1.GetTruth() == 0 ) {
    cout << "Passed bad value constructor test 1." << endl;
  } else {
    cout << "Failed bad value constructor test 1." << endl;
  }

  FactCheckedStatement fcs_bad2("How about this?", -0.25);  // Argument 1 does
  // not end with a period so the object should hold the default statement.
  // Argument 2 is not a value between 0 and 1 inclusive, so the truth data
  // member should hold the default value of 0.
  if ( fcs_bad2 == "This is an unverified statement."
       && fcs_bad2.GetTruth() == 0 ) {
    cout << "Passed bad value constructor test 2." << endl;
  } else {
    cout << "Failed bad value constructor test 2." << endl;
  }

  FactCheckedStatement fcs_good1("Ice cream is not cold.");
  if ( fcs_good1 == "Ice cream is not cold."  && fcs_good1.GetTruth() == 0 ) {
    cout << "Passed good constructor test 1." << endl;
  } else {
    cout << "Failed good constructor test 1." << endl;
  }

  FactCheckedStatement fcs_good2("The politician is trustworthy.", 0.3);
  if ( fcs_good2 == "The politician is trustworthy."
       && fcs_good2.GetTruth() == 0.3 ) {
    cout << "Passed good constructor test 2." << endl;
  } else {
    cout << "Failed good constructor test 2." << endl;
  }
  return 0;
}
