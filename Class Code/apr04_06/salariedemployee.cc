// Copyright 2023 fschein
// Implement the HourlyEmployee class functionality
#include"salariedemployee.h"
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"employee.h"

namespace CSCE240_Employees {
  SalariedEmployee::SalariedEmployee(string first, string last, string job_title,
                    int pays, double salary) : Employee(first, last, job_title, pays),
                                               annual_salary_(0) {
    SetSalary(salary);
  }

  SalariedEmployee::SalariedEmployee(const Employee& emp, double salary) :
                    Employee(emp), annual_salary_(0) {
    SetSalary(salary);
  }

  void SalariedEmployee::SetSalary(double salary) {
    if ( salary >= 0 )
      annual_salary_ = salary;
  }

  void SalariedEmployee::Print() const {
    Employee::Print();
    cout << "Annual Salary: $" << annual_salary_ << endl;
  }

  double SalariedEmployee::Pay() const {
    return annual_salary_ / GetPaysPerYear();
  }
}  // end namespace CSCE240_Employees