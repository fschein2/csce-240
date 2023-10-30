// Copyright 2023 fschein
// Define a MultipleChoiceQuestion Class
#ifndef _MULTIPLE_CHOICE_QUESTION_H_
#define _MULTIPLE_CHOICE_QUESTION_H_

#include"question.h"
#include<string>
using std::string;


namespace csce240_program5 {
  // MultipleChoiceQuestion should be a child of the Question class
  class MultipleChoiceQuestion : public Question {
   public:
    // Create an explicit constructor that allows the question, the number of
    // choices, the answer choices, and the answer correct/incorrect values to be
    // initialized when the object is instantiated. The parameters should have
    // default argments of "?", 0, nullptr, and nullptr, respectively.
    // If all but the last two arguments are provided, make all of the answer
    // choices the empty string "", and all of the correct/incorrect values true.
    // If all but the last argument is provided, default all correct/incorrect
    // values to true.
    // The prototype is provided below
    explicit MultipleChoiceQuestion(string q = "?", int n = 0, string * c = nullptr,
                                    bool * x = nullptr);

    // Create a copy constructor
    MultipleChoiceQuestion(const MultipleChoiceQuestion& tocopy);

    // Add an accessor and mutator function for the data member number_of_choices_
    int GetNumberOfCChoices() const { return number_of_choices_; }

    void SetNumberOfChoices (int n);

    // Overload the assignment operator
    MultipleChoiceQuestion operator = (const MultipleChoiceQuestion& rightoperand);

    // Create a destructor that frees up all dynamically allocated memory
    virtual ~MultipleChoiceQuestion() { delete [] choices_;
                                        delete [] correct_; }

    // Add a SetAnswerChoices function that sets the number of choices, the values
    // of the answer choices, and the answer correct/incorrect values. This function
    // will dynamically allocate and deallocate memory for the data members, as
    // necessary. The prototype is provided below
    void SetAnswerChoices(int n, string * c, bool * x);

    // Add a Print function that takes a bool parameter: void Print(bool) const;
    // This fuction should send output to the standard output device, using cout.
    // The first line of output should be "Question: " followed by the value of
    // the question data member.
    // The next line of output should be "Answer Choices:"
    // The following lines should print each answer a separate line.
    // If the Print function's argument is true, each answer choice should be
    // followed by " - correct" or " - incorrect"
    virtual void Print(bool x) const;

    virtual bool CheckAnswer(string a) const;
    
   private:
    // The class should have a private integer data member that holds the number
    // of answer choices for the question.
    int number_of_choices_;
    // The class should have a private string pointer data member that holds the
    // answer choices for the question.
    string * choices_;
    // The class should have a private bool pointer data member that holds whether
    // each of the answer choices for the question is correct or not.
    bool * correct_;
  };  // end MultipleChoiceQuestion class

}  // end namespace csce240_program5

#endif  // _MULTIPLE_CHOICE_QUESTION_H_