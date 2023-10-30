// Copyright 2023 fschein
#include"polynomial.h"
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

// we initialize static data members on the class, not in the constructor
char Polynomial::variable_ = 'y';

void Polynomial::SetVariable(char var) {
  if ( var >= 'a' && <= 'z' )
    variable_ = var;
}

Polynomial::Polynomial(int degree) : degree_(0), coefficients_(nullptr) {
  if ( degree >= 0 )
    degree_ = degree;
  // dynamically allocate a block of degree_ + 1 doubles to hold the values
  // of our polynomial's coefficients
  coefficients_ = new double[degree_ + 1];
  // backwards compatibility for older compilers
  if ( coefficients_ == nullptr ) {
    cout << "Couldn't allocate requested memory" << endl;
    exit(1);
  }
  // initializaing all of the coefficients to 1 by default
  for ( int i = degree_; i >=0; --i )
    coefficients_[i] = 1;
}

Polynomial::Polynomial(const Polynomial& tocopy) {
  degree_ = tocopy.degree_;
  coefficients_ = new double [ degree_ + 1 ];
  for( int i = 0; i <= degree_; ++i )
    coefficients_[i] = tocopy.coefficients_[i];
}

// This function is called on an existing object, so if we have to reallocate
// memory, we need to make sure we deallocate (release) previously allocatied
// memory to avoid a memory leak
void Polynomial::SetDegree(int degree) {
  if ( degree == degree_ || degree < 0)
    return;

  degree_ = degree;
  delete [] coefficients_;  // free up the previously dynamically allocated memory
  coefficients_ = new double[degree_ + 1];
  // backwards compatibility for older compilers
  if ( coefficients_ == nullptr ) {
    cout << "Couldn't allocate requested memory" << endl;
    exit(1);
  }
  // initializaing all of the coefficients to 1 by default
  for ( int i = degree_; i >=0; --i )
    coefficients_[i] = 1;
}

// note: friend keyword only used in the class definition 
// this operator/function is not a member, not tied to class
ostream& operator << ( ostream& whereto, const Polynomial& p ) {
  // friendship allows this non-member function to directly acces degree_
  // and coeffiecients_
  for  ( int i = p.degree_; i >=0; --i )
    if ( p.coefficients_[i] != 0 )
      whereto << p.coefficients_[i] 
              << p.variable_ << "^" << i << (i > 0 ? " + " : "");
  return whereto;
}

Polynomial& Polynomial::operator = (const Polynomial& rightoperand) {
  if ( degree_ != rightoperand.degree_ ) {
    degree_ = rightoperand.degree_;
    // coefficients = rightoperand.coefficients_;
    delete [] coefficients_;
    coefficients_ = new double [ degree_ + 1 ];
  }
  for( int i = 0; i <= degree_; ++i )
    coefficients_[i] = rightoperand.coefficients_[i];

  // return the value of the object that we just updated
  // this pointer = holds the address of the object
  return *this;  // return *this to allow cascaded = ( eg x = y = z )
}

double& Polynomial::operator [] (int term) {
  // we can design this different ways, but the key is to ensure that we stay
  // in bounds
  if ( term < 0 )
    term = 0;
  // if setting a coefficient that's larger than the degree, let's
  // increase the degree of the polynomial to fit
  if ( term > degree_ ) {
    double * newcoefficients = new double [term + 1];
    // copy over the old coefficients
    for ( int i = 0; i <= degree_; ++i ) 
      newcoefficients[i] = coefficients_[i];
    // place 0s in the new spots larger than degree_ 
    for ( int j = degree + 1; j <= term; ++j )
      newcoefficients[j] = 0; 
    delete [] coefficients_;
    coefficients_ = newcoefficients;
    degree_ = term;
  }
  return coefficients_[term];
}

double Polynomial::operator [] (int term) const {
  if (term < 0 )
    term = 0;
  if ( term > degree_ )
  //  term = degree_;
    return 0;
  return coefficients_[term];
}

Polynomial Polynomial::operator + (const Polynomial& rightoperand) const {
  int maxdegree = ( degree_ >= rightoperand.degree_ ? degree_ 
                    : rightoperand.degree_ );
  Polynomial resut(maxdegree);
  for ( int i = 0; i <= maxdegree; ++i ) {
    if ( i > degree_ )
      result[i] = (*this)[i] + rightoperand[i];
    else if ( i > rightoperand.degree_ )
      result[i] = (*this)[i];
    else
      result[i] = (*this)[i] + rightoperand[i];
  }
  return result;
}