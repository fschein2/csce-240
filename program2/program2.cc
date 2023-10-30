// Copyright 2023 fschein
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include"program2functions.h"

int main() {
  int month1, month2, day1, day2, year1, year2;
  int monthO, dayO, yearO;  // stores the original dates of date1
  char char1, char2, char3, char4;
  bool date1or2 = true;  // if true date1 is bigger than date2
                         // if false date2 is bigger than date1
  int dayCount = 0;  // counts the number of days between date 1 and 2
  bool equalDates = false;

  cin >> month1 >> char1 >> day1 >> char2 >> year1;
  cin >> month2 >> char3 >> day2 >> char4 >> year2;

  monthO = month1;
  dayO = day1;
  yearO = year1;

  if ( !ValidDate(month1, day1, year1) ) {
    cout << month1 << char1 << day1 << char2 << year1
         << " is not a valid date" << endl;
  }
  if ( !ValidDate(month2, day2, year2) ) {
      cout << month2 << char3 << day2 << char4 << year2
           << " is not a valid date" << endl;
  }

  if ( ValidDate(month1, day1, year1) && ValidDate(month2, day2, year2) ) {
    if ( year1 > year2 ) {
      date1or2 = true;
    } else if ( year2 > year1 ) {
        date1or2 = false;
    } else if ( year1 == year2 ) {
        if ( month1 > month2 ) {
          date1or2 = true;
        } else if ( month2 > month1 ) {
            date1or2 = false;
        } else if ( month1 == month2 ) {
            if ( day1 > day2 ) {
              date1or2 = true;
            } else if ( day2 > day1 ) {
                date1or2 = false;
            } else if ( day1 == day2 ) {
                cout << month1 << char1 << day1 << char2 << year1
                     << " is 0 days before "
                     << month2 << char3 << day2 << char3 << year2
                     << endl;
                return 0;
            }
        }
    }

    if ( date1or2 == true ) {
      do {
        PreviousDate(month1, day1, year1);
        dayCount++;

      if ( month1 == month2 && day1 == day2 && year1 == year2 )
          equalDates = true;
      } while ( equalDates == false );

      cout << monthO << char1 << dayO << char2 << yearO
           << " is " << dayCount << " days after "
           << month2 << char3 << day2 << char4 << year2 << endl;
    }

    if ( date1or2 == false ) {
      do {
        NextDate(month1, day1, year1);
        dayCount++;

        if ( month1 == month2 && day1 == day2 && year1 == year2 )
          equalDates = true;
        } while ( equalDates == false );

        cout << monthO << char1 << dayO << char2 << yearO
             << " is " << dayCount << " days before "
             << month2 << char3 << day2 << char4 << year2 << endl;
    }
  }

  return 0;
}
