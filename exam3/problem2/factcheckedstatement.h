// Copyright 2023 fschein
#ifndef _FACT_CHECKED_STATEMENT_H_
#define _FACT_CHECKED_STATEMENT_H_

#include"sentence.h"
#include<string>
using std::string;
#include<iostream>
using std::ostream;

namespace Project3Problem2 {
// Define the FactCheckedStatement class as a child of the Sentence class
class FactCheckedStatement : public Sentence {

  // Overload the stream insertion operator to output a FactCheckedStatement
  // object. The output should be the statement string followed by percent
  // truth in parenthesis.
  // For example, if the FactCheckedStatement x is 
  // "The third exam/project for CSCE240 is due by 11:59pm on May 2." with a
  // truth value of 1, then cout << x should print
  // "The third exam/project for CSCE240 is due by 11:59pm on May 2. (100% true)"
  // to the standard output device. 
  // See testoutput.cc and correctoutput.txt for additional examples of the
  // expected output for example FactCheckedStatement objects.
  friend ostream& operator << (ostream& whereto, const FactCheckedStatement& f);

 public:
  // Add a constructor that takes a string parameter for the statement and
  // and a double parameter for the verified truth of the statement (a value
  // between 0 and 1, inclusive).
  // Provide a default argument of 0 for the double parameter.
  // If the string argument is not a valid statement (doesn't start with an
  // uppercase alphabetic character or doesn't end with a period), the statement
  // should default to "This is an unverified statement." 
  explicit FactCheckedStatement(string s = "", double t = 0);

  // Overload the assignment operator.
  // If the string (the right operand) begins with an uppercase alphabetic
  // character and ends with a period, the FactCheckedStatement should be
  // set to that string and the data member holding the truth of the statement
  // should be set to 0.
  // If the right operand does not start with an uppercase alphabetic character
  // or it does not end with a period, the FactCheckedStatement object should
  // remain unchanged by the operation.
  Sentence& operator = (const string& right);

  // Add an accessor function for the double data member holding the truth
  // of the statement.
  double GetTruth() const { return truth_; }

  // Add a mutator function for the double data member holding the truth of
  // the statement that takes a double parameter. 
  // If the argument sent to the function is a value between 0 and 1, inclusive,
  // the data member should be set to the argument's value.
  // If the argument sent to the function is not between 0 and 1, the data
  // member should remain unchanged by the function call.
  void SetTruth(double c);

 private:
  double truth_;

};  // end class FactCheckedStatement

}  // end namespace Project3Problem2

#endif  // _FACT_CHECKED_STATEMENT_H_