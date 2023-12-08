// Employee.cpp

#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

void inputEmployeeData(Employee employees[], int numEmployees, int j) {
    cout << "Enter employee " << j + 1 << " name: \n";
    getline(cin >> std::ws, employees[j].name);

    cout << "Enter base wage for " << employees[j].name << ": \n";
    cin >> employees[j].baseWage;
    while (employees[j].baseWage < 0) {
        cout << "Error: base wage cannot be negative. Please re-enter: \n";
        cin >> employees[j].baseWage;
    }
}

void calculateWages(Employee employees[], int numEmployees, int j) {
    float overtimeHours, overtimePay;

    cout << "Enter number of overtime hours for " << employees[j].name << ": \n";
    cin >> overtimeHours;
    while (overtimeHours < 0) {
        cout << "Error: overtime hours cannot be negative. Please re-enter: \n";
        cin >> overtimeHours;
    }

    if (overtimeHours > 0) {
        overtimePay = (employees[j].baseWage / REGULAR_HOURS) * OVERTIME_RATE * overtimeHours;
        employees[j].overtimeWage = overtimePay;
        employees[j].totalWage = employees[j].baseWage + overtimePay;
    } else {
        employees[j].overtimeWage = 0;
        employees[j].totalWage = employees[j].baseWage;
    }
}

void calculateAbsentWages(Employee employees[], int numEmployees, int j) {
    int absentDays;
    float absentWage;

    cout << "Enter number of absent days for " << employees[j].name << ": \n";
    cin >> absentDays;

    while (absentDays < 0 || absentDays > 26) {
        cout << "Error: absent days cannot be negative or greater than 26. Please re-enter: \n";
        cin >> absentDays;
    }

    absentWage = (absentDays * (employees[j].baseWage) / 26);
    employees[j].totalWage -= absentWage;
}

void displayPayslip(Employee employees[], int numEmployees) {
    cout << "Payslip" << endl;
    cout << setw(10) << "Name" << setw(15) << "Base Wage" << setw(15) << "Overtime Wage"
              << setw(15) << "Total Wage" << endl;

    for (int i = 0; i < numEmployees; i++) {
        cout << setw(10) << employees[i].name << setw(15) << employees[i].baseWage << setw(15)
                  << employees[i].overtimeWage << setw(15) << employees[i].totalWage << endl;
    }
}

void printToFile(Employee employees[], int numEmployees) {
    ofstream myFile;
    myFile.open("wages.txt"); // change the file path to match your desktop location
    myFile << setw(78) << "CPP SDN.BHD." << endl;
    myFile << setw(71) << "Payslip" << endl;
    myFile << "*************************************************************************************************************" << endl;
    myFile << setw(10) << "Name" << setw(15) << "Base Wage" << setw(15) << "Overtime Wage"
           << setw(15) << "absent days" << setw(15) << "Total Wage" << endl;

    for (int i = 0; i < numEmployees; i++) {
        myFile << setw(10) << employees[i].name << setw(15) << employees[i].baseWage << setw(15)
               << employees[i].overtimeWage << setw(15) << employees[i].absentDays << setw(15)
               << employees[i].totalWage << endl;
        myFile << "***************************************************************************************************************" << endl;
    }
}
