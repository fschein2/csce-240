// Copyright 2023 bhipp
// File contains the definition of the Sentence class in the Project3Problem2
// namepace.
// Do not modify the code in this file.
#ifndef _SENTENCE_H_
#define _SENTENCE_H_

#include<string>
using std::string;
#include<iostream>
using std::istream;

namespace Project3Problem2 {

// The Sentence class is a child of the string class - a Sentence IS A string
// that begins with an uppercase alphabetic character, and ends with a period,
// question mark, or exclamation point
class Sentence : public string {
 public:
  // The Sentence constructor takes a string parameter and initializes the
  // object to the string, as long the string begins with an uppercase
  // alphabetic character and ends with a period, question mark, or exclamation
  // point. If the string does not begin with an uppercase alphabetic character
  // or it doesn't end with a period, question mark, or exclamation, then the
  // Sentence will be set to "This is a sample sentence."
  explicit Sentence(string s) { 
    string::operator = ("This is a sample sentence."); 
    *this = s;
  }

  // The assignment operator will set a Sentence object to a string if the
  // string (the right operand) begins with an uppercase alphabetic character
  // and ends with a period, question mark, or exclamation point.
  // If the right operand does not start with an uppercase alphabetic character
  // or it does not end with a period, question mark, or exclamation point,
  // the Sentence object will remain unchanged by the operation.
  Sentence& operator = (const string& right) {
    if ( ( right[0] >= 'A' && right[0] <= 'Z') && 
         ( right[right.length() - 1] == '.' ||
           right[right.length() - 1] == '?' ||
           right[right.length() - 1] == '!' ) 
       )
      string::operator = (right);
    return *this;
  }

};  // class Sentence

}  // namespace Project3Problem2

#endif  // _SENTENCE_H_