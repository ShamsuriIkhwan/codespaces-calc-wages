// Employee.h
#include <iostream>
#include <string>
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H


const int MAX_EMPLOYEES = 100;
const float OVERTIME_RATE = 1.5;
const int REGULAR_HOURS = 208;// 26 days * 8 hours per day in every month

struct Employee {
    string name;
    float baseWage;
    float overtimeWage;
    float totalWage;
    int absentWage;
    int absentDays;
};

void inputEmployeeData(Employee employees[], int numEmployees, int j);
void calculateWages(Employee employees[], int numEmployees, int j);
void calculateAbsentWages(Employee employees[], int numEmployees, int j);
void displayPayslip(Employee employees[], int numEmployees);
void printToFile(Employee employees[], int numEmployees);

#endif // EMPLOYEE_H
