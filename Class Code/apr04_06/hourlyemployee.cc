// Copyright 2023 fschein
// Implement the HourlyEmployee class functionality
#include"hourlyemployee.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"employee.h"

namespace CSCE240_Employees {
  HourlyEmployee::HourlyEmployee (string first, string last,
                  string job_title,int pays, double rate, 
                  double hrs) : Employee(first, last, job_title, pays),
                                hourly_rate_(7.25), hours_worked_(0) {
    SetRate(rate);
    SetHoursWorked(hrs);
  }

  HourlyEmployee::HourlyEmployee(const Employee& emp, double rate,
                  double hrs) : Employee(emp), hourly_rate_(7.25),
                                hours_worked_(0) {
    SetRate(rate);
    SetHoursWorked(hrs);
  }

  void HourlyEmployee::SetRate(double r) {
    if ( r >= 7.25 )
      hourly_rate_ = r;
  }

  void HourlyEmployee::SetHoursWorked(double hrs) {
    if (hrs >= 0 && hrs <= 365.0 / GetPaysPerYear() * 24 )
      hours_worked_ = hrs;
  }

  void HourlyEmployee::Print() const {
    // call the base class version of this function first
    Employee::Print();
    cout << "Hourly Rate: $" << hourly_rate_ << "\nHours Worked: "
         << hours_worked_ << endl;
  }

  // not accounting for overtime at the moment
  double HourlyEmployee::Pay() const {
    return hours_worked_ * hourly_rate_;
  }
}  // end namespace CSCE240_Employees