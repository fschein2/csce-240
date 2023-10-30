// Copyright 2023 fschein
// Define a TrueFalseQuestion Class
#ifndef _TRUE_FALSE_QUESTION_H_
#define _TRUE_FALSE_QUESTION_H_

#include"question.h"
#include<string>
using std::string;


namespace csce240_program5 {

  // TrueFalseQuestion should be a child of the Question class
  class TrueFalseQuestion : public Question {
   public:
    // Create an explicit constructor that allows the question and answer to be
    // initialized when an object is instantiated. The question and answer
    // parameters should have default arguments of "?" and true, respectively.
    explicit TrueFalseQuestion(string q = "?", bool a = true);

    // Add an accessor and mutator function for the data member tf_answer_
    bool GetTFAnswer() const { return tf_answer_; }

    void SetTFAnswer(bool a);

    // Add a Print function that takes a bool parameter: void Print(bool) const;
    // This fuction should create 1 or 2 lines of output to the standard output
    // device, using cout.
    // The first line of output should be "Question: " followed by the value of
    // the question data member.
    // If the Print function's argument is true, it should output a second line
    // that is "Correct Answer: " followed by "true" or "false" depending on the
    // value of the private data member.
    virtual void Print(bool x) const;

    virtual ~TrueFalseQuestion() {};

    virtual bool CheckAnswer(string a) const;

   private:
    // The class should have a private bool data member that holds whether the
    // answer to the question is true or false.
    bool tf_answer_;
  };  // end TrueFalseQuestion Class

}  // end namespace csce240_program5

#endif  // _TRUE_FALSE_QUESTION_H_