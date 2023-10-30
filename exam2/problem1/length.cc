// Copyright 2023 fschein
#include"length.h"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::ostream;
using std::string;

Length::Length(double v, string u) : value_(0), units_("inches") {
  if ( v >= 0 )
    value_ = v;
  if ( u == "inches" || u == "centimeters" )
    units_ = u;
}

void Length::SetUnits(string u) {
  if ( u == "inches" || u == "centimeters" )
    units_ = u;
}

void Length::SetValue(double v) {
  if ( v >= 0 )
    value_ = v;
}

void Length::Convert(string u) {
  if ( units_ == "inches" ) {
    if ( u == "centimeters" ) {
      value_ = value_ * 2.54;
      units_ = u;
    }
  }

  if ( units_ == "centimeters" ) {
    if ( u == "inches" ) {
      value_ = value_ / 2.54;
      units_ = u;
    }
  }
}

ostream& operator << (ostream& whereto, const Length& l) {
  whereto << l.value_ << " " << l.units_;
  return whereto;
}

Length Length::operator + (const Length right) const {
  Length l;
  l.SetUnits(units_);
  if ( units_ == right.units_ ) {
    l.SetValue(value_ + right.value_);
  } else if ( units_ != right.units_ ) {
      if ( units_ == "inches" ) {
        l.SetValue(value_ + (right.value_ / 2.54) );
      } else if ( units_ == "centimeters" ) {
          l.SetValue(value_ + (right.value_ * 2.54) );
      }
  }
  return l;
}

bool Length::operator == (const Length right) const {
  if ( units_ == right.units_ ) {
    if ( value_ == right.value_ ) {
      return true;
    }
  } else if ( units_ != right.units_ ) {
      if ( units_ == "inches" ) {
        if (value_ == (right.value_ / 2.54)) {
          return true;
        }
      } else if ( units_ == "centimeters" ) {
          if (value_ == (right.value_ * 2.54)) {
            return true;
          }
      }
  }
  return false;
}

bool Length::operator < (const Length right) const {
  if ( units_ == right.units_ ) {
    if ( value_ < right.value_ ) {
      return true;
    }
  } else if ( units_ != right.units_ ) {
    if ( units_ == "inches" ) {
      if (value_ < (right.value_ / 2.54)) {
        return true;
      }
    } else if ( units_ == "centimeters" ) {
        if (value_ < (right.value_ * 2.54)) {
          return true;
        }
    }
  }
  return false;
}