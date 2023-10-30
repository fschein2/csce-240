// Copyright 2023 fschein
// Define Polynomial class for polynomial expressions in one variable
// e.g., 3x^2 + 2x - 4
// data members: degree of polynomial, coefficients
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include<iostream>
using std::ostream;

class Polynomial {
  // an operator is a function with a special name that is called in a 
  // special way 
  // +             =             << 
  // operator +    operator =    operator <<
  // x + y    operator + ( x, y )  if the operator is a standalone function
  //          x.operator + (y)     if the operator is a member function

  // cout << x    since the left operand is not a polynomial object,
  //              the operator will not be a member function of our class
  // we'll make the stream insertion operator a friend of our class to give it
  // access to the private data members
  // cout << x << " " << y << endl;
  friend ostream& operator << ( ostream& whereto, const Polynomial& p );

 public:
  // recall, we'll make all constructors that can take exactly one argument
  // explicit
  explicit Polynomial(int degree=0);
  void SetDegree(int degree);

  // assignment operator will take a Polynomial object on the left, so this
  // operator can be a member of our class
  // x = y
  // x = y = z same as y = z; x = y;
  // any time we have pointers as data members we need:
  // - a copy constructor
  // - an overloaded assignment operator
  // - a destructor
  Polynomial& operator = (const Polynomial& rightoperand);
  Polynomial(const Polynomial& tocopy);  // copy constructor
  ~Polynomial() { delete [] coefficients_; }

  // let's overload the [] operator to index individual coefficients
  // Polynomial p(3);  p[3]
  double& operator [] (int term);
  double operator [] (int term) const; // constant version that allows constant
                                       // objects to view individual coefficients

  static void SetVariable(char var);
  
  // + takes a Polynomial object as it's left operand, so we can make this 
  // a member of our class
  Polynomial operator + (const Polynomial& rightoperand) const;

 private:
  int degree_;  // degree_ must be >= 0
  double * coefficients_;  // the number of coefficients is 1 more than
                           // the degree of the polynomial
  static char variable_;  // static means there's exactly one of these for the
                          // entire class
};

#endif  // _POLYNOMIAL_H_