// Copyright 2023 fschein
// Introduction to Classes
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

class School {
  public:
   School(); // {  // constructor for our School class - default constructor is
                   // a constructor that can be called with no arguments 
     // enrollment = 1000;
   // }  // IMPLEMENTED INSIDE OF THE CLASS DEFINITION

   // accessor function - public member that provides a copy of the value 
   // of a private.protected data member
   // const on the end of teh function means the member function won't modify 
   // the object its called on (won't change the values of the data members)
   int GetEnrollment() const { return enrollment_; }

   // mutator function - public member used to update the value of a 
   // private/protected data member
   void SetEnrollment(int newenrollment);

  private:  // make members private that we want to restrict access to
            // keep in a consistent state
   int enrollment_;
};

// implement the constructor outside of the class definition
// to specify that it's coming from the School class, needs to be tied to the 
// class using the scope resolution operator (::)
School::School() {
  enrollment_ = 1000;
}

void School::SetEnrollment(int newenrollment) {
  if ( newenrollment > 0 )
    enrollment_ = newenrollment;
}

int main() {
  School my_school;  // declared a variable of our class type
                     // a variable of a class type is called an object
                     // instantiate - create an instance of 
                     // (declare/initiate an object) of a class
  cout << my_school.GetEnrollment() << endl;
  int x;
  cout << "What's the actual enrollment? "
  cin >> x;
  my_school.SetEnrollment(x);
  cout << my_school.GetEnrollment() << endl;

  return 0;
}