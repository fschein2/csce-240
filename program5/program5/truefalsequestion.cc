// Copyright 2023 fschein
// Implement the TrueFalseQuestion class functionality
#include"truefalsequestion.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"question.h"

namespace csce240_program5 {
  TrueFalseQuestion::TrueFalseQuestion(string q, bool a) : 
                     Question(q), tf_answer_(true) {
    SetTFAnswer(a);
  }

  void TrueFalseQuestion::SetTFAnswer(bool a) {
    if ( a == true || a == false )
      tf_answer_ = a;
  }

  void TrueFalseQuestion::Print(bool x) const {
    Question::Print();
    if ( x == true ) {
      cout << "Correct Answer: ";
      if ( tf_answer_ == true )
        cout << "true" << endl;
      if ( tf_answer_ == false )
        cout << "false" << endl;
    }
  }

}  // end namespace csce240_program5