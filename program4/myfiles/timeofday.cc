// Copyright 2023 fschein
#include"timeofday.h"
#include<iostream>
using std::cout;
using std::endl;

TimeOfDay::TimeOfDay(int h, int m, int s) :
  hour_(0), minute_(0), second_(0) {
  if ( h >= 0 && h < 24 )
    hour_ = h;
  if ( m >= 0 && m < 60 )
    minute_ = m;
  if ( s >= 0 && s < 60 )
    second_ = s;
}

void TimeOfDay::SetHour(int h) {
  if ( h >= 0 && h < 24 )
    hour_ = h;
}

void TimeOfDay::SetMinute(int m) {
  if ( m >= 0 && m < 60 )
    minute_ = m;
}

void TimeOfDay::SetSecond(int s) {
  if ( s >= 0 && s < 60 )
    second_ = s;
}

void TimeOfDay::Print(bool military, bool seconds) const {
  if ( military == true ) {
    if ( hour_ >= 10 ) {
      cout << hour_;
    } else if ( hour_ < 10 ) {
        cout << "0" << hour_;
    }
  } else if ( military == false ) {
      if ( hour_ == 0 ) {
        cout << "12";
      } else if ( hour_ > 0 && hour_ <= 9 ) {
          cout << "0" << hour_;
      } else if ( hour_ >= 10 && hour_ <= 12 ) {
          cout << hour_;
      } else if ( hour_ >= 13 && hour_ <= 21 ) {
          cout << "0" << hour_ - 12;
      } else if ( hour_ >= 22 && hour_ <= 23 ) {
          cout << hour_ - 12;
      }
  }

  cout << ":";
  if ( minute_ <= 9 ) {
    cout << "0" << minute_;
  } else if ( minute_ > 9 ) {
      cout << minute_;
  }

  if ( seconds == true ) {
    cout << ":";
    if ( second_ <= 9 ) {
      cout << "0" << second_;
    } else if ( second_ > 9 ) {
        cout << second_;
    }
  }

  if ( military == false ) {
    if ( hour_ >= 12 ) {
      cout << " p.m.";
    } else if ( hour_ < 12 ) {
        cout << " a.m.";
    }
  }

  cout << endl;
}