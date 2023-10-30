// Copyright 2023 fschein
// Implement the MultipleChoiceQuestion class functionality
#include"multiplechoicequestion.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"question.h"

namespace csce240_program5 {
  MultipleChoiceQuestion::MultipleChoiceQuestion(string q, int n, string * c, bool * x) :
                                                 Question(q), number_of_choices_(0), 
                                                 choices_(nullptr), correct_(nullptr) {
    SetNumberOfChoices(n);
    SetAnswerChoices(n, c, x);

    if ( c == nullptr ) {
      choices_ = new string[number_of_choices_];
      for ( int i = 0; i < number_of_choices_; ++i )
        choices_[i] = "";
    }
    if ( x == nullptr ) {
      correct_ = new bool[number_of_choices_];
      for ( int i = 0; i < number_of_choices_; ++i )
        correct_[i] = true;
    }
  }

  MultipleChoiceQuestion::MultipleChoiceQuestion(const MultipleChoiceQuestion& tocopy) :
                                                 Question(tocopy.GetQuestion()),
                                                 number_of_choices_(tocopy.number_of_choices_),
                                                 choices_(nullptr), correct_(nullptr) {
    SetAnswerChoices(tocopy.number_of_choices_, tocopy.choices_, tocopy.correct_);
  }

  void MultipleChoiceQuestion::SetNumberOfChoices(int n) {
    if ( n > 0 )
      number_of_choices_ = n;
  }

  MultipleChoiceQuestion MultipleChoiceQuestion::operator = (const MultipleChoiceQuestion& rightoperand) {
    choices_ = nullptr;
    correct_ = nullptr;
    
    delete [] choices_;
    delete [] correct_;

    SetQuestion(rightoperand.GetQuestion());
    number_of_choices_ = rightoperand.number_of_choices_;
    SetAnswerChoices(rightoperand.number_of_choices_, rightoperand.choices_, rightoperand.correct_);

    return *this;
  }

  void MultipleChoiceQuestion::SetAnswerChoices(int n, string * c, bool * x) {
    choices_ = nullptr;
    correct_ = nullptr;
    
    delete [] choices_;
    delete [] correct_;

    number_of_choices_ = n;
    choices_ = new string[number_of_choices_];
    correct_ = new bool[number_of_choices_];

    for ( int i = 0; i < number_of_choices_; ++i ) {
      if ( c != nullptr ) {
        choices_[i] = c[i];
      } else {
          choices_[i] = "";
      }

      if ( x != nullptr ) {
        correct_[i] = x[i];
      } else {
          correct_[i] = true;
      }
    }
  }

  void MultipleChoiceQuestion::Print(bool x) const {
    Question::Print();
    cout << "Answer Choices:" << endl;
    for ( int i = 0; i < number_of_choices_; ++i ) {
      cout << choices_[i];
      if (x) {
        if ( correct_[i] ) {
          cout << " - correct";
        } else {
            cout << " - incorrect";
        }
      }
      cout << endl;
    }
  }

}  // end namespace csce240_program5