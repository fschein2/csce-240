// Copyright 2023 fschein
// Implement the ShortAnswerQuestion class functionality
#include"shortanswerquestion.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"question.h"

namespace csce240_program5 {
  ShortAnswerQuestion::ShortAnswerQuestion(string q, string a) :
                       Question(q), sa_answer_("") {
    SetSAAnswer(a);
  }

  void ShortAnswerQuestion::SetSAAnswer(string a) {
    if ( a.length() > 0 )
      sa_answer_ = a;
  }

  void ShortAnswerQuestion::Print(bool x) const {
    Question::Print(x);
    if ( x == true )
      cout << "Correct Answer: " << sa_answer_ << endl;
  }

  bool ShortAnswerQuestion::CheckAnswer(string a) const {
    if ( a == sa_answer_ )
      return true;

    return false;
  }

}  // end namespace csce240_program5