// Copyright 2023 fschein
// Define the HourlyEmployee class
#ifndef _HOURLY_EMPLOYEE_H_
#define _HOURLY_EMPLOYEE_H_

#include<string>
using std::string;

namespace CSCE240_Employees {
  
  class HourlyEmployee : public Employee {
   public:
    explicit HourlyEmployee(string first = "Jane", string last = "Doe",
                            string job_title = "TBD", int pays = 52,
                            double rate = 7.25, double hrs = 0);
    // constructor to take an existing Employee object and create an 
    // HourlyEmployee version
    // NOTE: derived class object IS A base class object - implicit casting pk
    //       base class object IS NOT A derived class object - constructor
    //       below allows us to explicitly cast 

    // This constructor would no longer be needed if we make Employee
    // an abstarct class since there can't be Employee objects (the first
    // argument can't exist anymore!!)
    explicit HourlyEmployee(const Employee& emp, double rate = 7.25, double hrs = 0);
    virtual ~HourlyEmployee() { cout << "~HourlyEmployee called on " 
                             << GetLast() << endl; }
    void SetRate(double r);
    void SetHoursWorked(double hrs);
    double GetRate() const { return hourly_rate_; }
    double GetHoursWorked() const { return hours_worked_; }
    // redefine the Print function
    // if a function is virtual in the base class - it's virtual in the derived
    // class automatically, but we'll state it for clarity
    virtual void Print() const;
    virtual double Pay() const;
   private:
    double hourly_rate_;
    double hours_worked_;
  };  // end HourlyEmployee class

}  // end namespace CSCE240_Employees

#endif  // _HOURLY_EMPLOYEE_H_