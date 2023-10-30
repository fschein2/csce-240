// Copyright 2023 fschein
// Define a SalariedEmployee Class
#ifndef _SALARIED_EMPLOYEE_H_
#define _SALARIED_EMPLOYEE_H_

#include"employee.h"

namespace CSCE240_Employees {
  
  class SalariedEmployee : public Employee {
   public: 
    // constructor to set all data members
    explicit SalariedEmployee(string first = "Jane", string last = "Doe",
                     string job_title = "TBD", int pays = 52,
                     double salary = 0);
    // constructor to take an Employee object and add a salary to create a 
    // SalariedEmployee
    explicit SalariedEmployee(const Employee& emp, double salary = 0);
    virtual ~SalariedEmployee() { cout << "~SalariedEmployee called on "
                               << GetLast() << endl; }
    // accessor function for annual salary
    double GetSalary() const { return annual_salary_; }
    // mutator function for annual salary
    void SetSalary(double salary);
    // Print
    virtual void Print() const;
    // Pay
    virtual double Pay() const;
   private:
    double annual_salary_;
  };  // end SalariedEmployee class

}  // end namespace CSCE240_Employees

#endif  // _SALARIED_EMPLOYEE_H_
