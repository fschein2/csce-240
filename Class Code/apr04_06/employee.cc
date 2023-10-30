// Copyright 2023 fschein
// Implement the Employee class functionality
#include"employee.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

namespace CSCE240_Employees {

  Employee::Employee(string first, string last, string job_title, int pays) :
   first_name_("Jane"), last_name_("Doe"), job_title_("TBD"), pays_per_year_(52) {
    SetFirst(first);
    SetLast(last);
    SetJobTitle(job_title);
    SetPaysPerYear(pays);
  }

  void Employee::SetFirst(string f) {
    if ( f.length() > 0 ) 
      first_name_ = f;
  }

  void Employee::SetLast(string l) {
    if( l.length() > 0 )
      last_name_ = l;
  }

  void Employee::SetJobTitle(string j) {
    if( j.length() > 0 )
      job_title_ = j;
  }

  void Employee::SetPaysPerYear(int ppy) {
    if ( ppy == 365 || ppy == 52 || ppy == 26 || 
         ppy == 24 || ppy == 12 )
      pays_per_year_ = ppy;
  }

  void Employee::Print() const {
    cout << "Employee Name: " << first_name_ << " " << last_name_
         << "\nJob Title: " << job_title_ << "\nPays Per Year: " 
         << pays_per_year_ << endl;
  }

}  // end namespace CSCE240_Employees