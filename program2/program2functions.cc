// Copyright 2023 fschein
// Program 2
#include"program2functions.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

bool LeapYear(int year) {
  if ( year % 100 == 0 ) {
    if ( year % 400 == 0 )
      return true;

    return false;
  }

  if ( year % 4 == 0 )
    return true;

  return false;
}

int LastDayOfMonth(int month, int year) {
  if ( month == 1 ) {
    return 31;
  } else if ( month == 3 ) {
      return 31;
  } else if ( month == 5 ) {
      return 31;
  } else if ( month == 7 ) {
      return 31;
  } else if ( month == 8 ) {
      return 31;
  } else if ( month == 10 ) {
      return 31;
  } else if ( month == 12 ) {
      return 31;
  } else if ( month == 4 ) {
      return 30;
  } else if ( month == 6 ) {
      return 30;
  } else if ( month == 9 ) {
      return 30;
  } else if ( month == 11 ) {
      return 30;
  } else if ( month == 2 ) {
      if ( year == 0 ) {
        return 0;
      } else if ( !LeapYear(year) ) {
          return 28;
      } else if ( LeapYear(year) ) {
          return 29;
      }
  }

  return 0;
}

bool ValidDate(int month, int day, int year) {
  if ( month > 12 )
    return false;
  if ( month < 1 )
    return false;

  int lastDay = LastDayOfMonth(month, year);
  if ( day > lastDay )
    return false;
  if ( day < 1 )
    return false;

  if ( year < 1 )
    return false;

  return true;
}

int NextDate(int &month, int &day, int &year) {
  if ( !ValidDate(month, day, year) )
    return 0;

  ++day;

  if ( day > LastDayOfMonth(month, year) ) {
    day = 1;
    ++month;
  }

  if ( month > 12 ) {
    month = 1;
    ++year;
  }

  return 0;
}

int PreviousDate(int &month, int &day, int &year) {
  if ( !ValidDate(month, day, year) )
    return 0;

  --day;

  if ( day < 1 ) {
    --month;
    if ( month == 0 ) {
      day = LastDayOfMonth(12, year);
    } else {
        day = LastDayOfMonth(month, year);
    }
  }

  if ( month < 1 ) {
    --year;
    month = 12;
  }

  return 0;
}
