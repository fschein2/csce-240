// Copyright 2023 fschein
// Define the ShortAnswerQuestion class
#ifndef _SHORT_ANSWER_QUESTION_H_
#define _SHORT_ANSWER_QUESTION_H_

#include"question.h"
#include<string>
using std::string;

namespace csce240_program5 {

  // ShortAnswerQuestion should be a child of the Question class
  class ShortAnswerQuestion : public Question {
   public:
    // Create an explicit constructor that allows the question and answer to be
    // initialized when instantiated. The question and answer parameters should
    // have default arguments of "?" and "", respectively.
    explicit ShortAnswerQuestion(string q = "?", string a = "");

    // Add an accessor and mutator function for the data member sa_answer_
    string GetSAAnswer() const { return sa_answer_; }

    void SetSAAnswer(string a);

    // Add a Print function that takes a bool parameter: void Print(bool) const;
    // This fuction should create 1 or 2 lines of output to the standard output
    // device, using cout.
    // The first line of output should be "Question: " followed by the value of
    // the question data member.
    // If the Print function's argument is true, it should output a second line
    // that is "Correct Answer: " followed by the value of the correct answer
    // private data member.
    void Print(bool x) const;

   private:
    // The class should have a private string data member that holds the correct
    // answer to the question.
    string sa_answer_;


  };  // end ShortAnswerQuestion class

}  // end namespace csce240_program5

#endif // _SHORT_ANSWER_QUESTION_H_