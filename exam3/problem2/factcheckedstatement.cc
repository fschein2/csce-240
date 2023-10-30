// Copyright 2023 fschein
// Problem 2 implementation
#include"factcheckedstatement.h"
#include"sentence.h"
#include<string>
using std::string;
#include<iostream>
using std::ostream;
using std::endl;

namespace Project3Problem2 {

FactCheckedStatement::FactCheckedStatement(string s, double t) : 
                      Sentence(s), truth_(0) {
  if (s[0] >= 'A' && s[0] <= 'Z' && s[s.length() - 1] == '.')
    string::operator = (s);
  else
    string::operator = ("This is an unverified statement."); 

  SetTruth(t);
}

void FactCheckedStatement::SetTruth(double t) {
  if (t <= 1 && t >= 0)
    truth_ = t;
}

Sentence& FactCheckedStatement::operator = (const string& right) {
  if (right[0] >= 'A' && right[0] <= 'Z' && right[right.length() - 1] == '.') {
    string::operator = (right);
    SetTruth(0);
  }
  
  return *this; 
}

ostream& operator << (ostream& whereto, const FactCheckedStatement& f) {
  whereto << f;
  whereto << " (" << f.GetTruth() * 100 << "% true)" << endl;
  return whereto;
}

}  // end namespace Project3Problem2