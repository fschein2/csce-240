// Copyright 2023 fschein
// Define the Employee class
#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;

namespace CSCE240_Employees {
  
  class Employee {
   public:
    explicit Employee(string first = "Jane", string last = "Doe",
                      string job_title = "TBD", int pays = 52);
    virtual ~Employee() { cout << "~Employee called on " << last_name_ << endl; }
    void SetFirst(string f);
    void SetLast(string l);
    void SetJobTitle(string j);
    void SetPaysPerYear(int ppy);
    string GetFirst() const { return first_name_; }
    string GetLast() const { return last_name_; }
    string GetJobTitle() const { return job_title_; }
    int GetPaysPerYear() const { return pays_per_year_; }
    virtual void Print() const;

    // = 0 on the end here makes Pay() a pure virtual function, and
    // makes Employee an abstarct class
    virtual double Pay() const = 0;  // { return 0; }

   private:
    string first_name_;
    string last_name_;
    string job_title_;
    int pays_per_year_;
  };  // end Employee class

}  // end namespace CSCE240_Employees

#endif // _EMPLOYEE_H_