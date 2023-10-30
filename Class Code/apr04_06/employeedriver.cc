// Copyright 2023 fschein
// test drive the employee family of classes
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<fstream>
using std::ifstream;
#include"employee.h"
using CSCE240_Employees::Employee;
#include"hourlyemployee.h"
using CSCE240_Employees::HourlyEmployee;
#include"salariedemployee.h"
using CSCE240_Employees::SalariedEmployee;

int main() {
  /*
  Employee just_an_employee("Q", "U");
  just_an_employee.Print();
  HourlyEmployee hourly(just_an_employee, 15, 40);
  hourly.Print();
  HourlyEmployee edefault, einitialized("John", "Smith", "Programmer", 12);
  edefault.Print();
  einitialized.Print();
  SalariedEmployee sal1(just_an_employee), sal2("A", "Jones", "CEO", 24, 30000);
  sal1.Print();
  sal2.Print();
  */

  /*
  Employee * epointer;
  Employee e("Bob", "DaBilder", "Contractor");
  HourlyEmployee he("Thomas", "Train", "Transportation Worker", 52, 12, 60);
  SalariedEmployee se("Oscar", "Grouch", "Sanitation", 52, 125000);
  int which;
  cout << "Enter 1 for employe, 2 for hourly employee, 2 for salaried employee" << endl;
  cin >> which;
  switch(which) {
    case 1:
      epointer = &e;
      break;
    case 2:
      epointer = &he;  // it's ok to have a base class pointer point to a derived
                       // class object - a derived class object IS A base class
                       // object
      break;
    default:
      epointer = &se;
  }
  epointer->Print();
  */

  ifstream infile("someemployees.txt");
  string first, last, jobtitle, emptype;
  int payfrequency, numemployees, i = 0;
  double hourlyrate, hours, salary;
  infile >> numemployees;
  // employee points to a block of pointers to Employees (think dynamically
  // allocated array of pointers)
  Employee ** employees = new Employee * [numemployees];
  do {
    infile >> first >> last >> jobtitle >> payfrequency >> emptype;
    if ( emptype == "hourly" ) {
      infile >> hourlyrate >> hours;
      employees[i] = new HourlyEmployee(first, last, jobtitle, payfrequency, 
                                        hourlyrate,hours);
    } else if( emptype == "salaried" ) {
        infile >> salary;
        employees[i] = new SalariedEmployee(first, last, jobtitle, payfrequency, 
                                            salary);
    } /* else {
        employee[i] = new Employee(first, last, jobtitle, payfrequency);
    } */
  } while ( infile.good() && ++i < numemployees );
  while ( i > 0 ) {
    --i;
    employees[i]->Print();
    cout << "Pay this period: $" << employees[i]->Pay() << endl;
    delete employees[i];
  }
  delete [] employees;

  return 0;
}