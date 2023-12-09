// Employee.cpp

#include "Employee.h"
#include "welcome.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


void inputEmployeeData(Employee employees[], int numEmployees, int j) {
    cout << "Enter employee " << j + 1 << " name: \n";
    getline(cin >> std::ws, employees[j].name);

    cout << "Enter employee " << j + 1 << " ID number: \n";
    cin >> employees[j].idnumber;

    cout << "Enter base wage for " << employees[j].name << ": \n";
    cin >> employees[j].baseWage;
    validateBaseWage(employees[j].baseWage);
    }

bool validateBaseWage(float& baseWage) {
    while (baseWage < 0 || cin.fail()) {
        cin.clear(); // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Error: base wage must be a non-negative number. Please re-enter: \n";
        cin >> baseWage;
    }
    return true;
}

void calculateWages(Employee employees[], int numEmployees, int j) {
    float overtimeHours;
     double overtimePay;

    cout << "Enter number of overtime hours for " << employees[j].name << ": \n";
    cin >> overtimeHours;
    employees[j].overtimeHours = overtimeHours;
    validateOvertimeHours(overtimeHours);
        
    if (overtimeHours > 0) {
        overtimePay = (employees[j].baseWage / REGULAR_HOURS) * OVERTIME_RATE * overtimeHours;
        employees[j].overtimeWage = overtimePay;
        employees[j].totalWage = employees[j].baseWage + overtimePay;
    } else {
        employees[j].overtimeWage = 0;
        employees[j].totalWage = employees[j].baseWage;
    }
}

bool validateOvertimeHours(float& overtimeHours) {
    while (overtimeHours < 0 || cin.fail()) {
        cin.clear(); // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Error: overtime hours must be a non-negative number. Please re-enter: \n";
        cin >> overtimeHours;
    }
    return true;
}

void calculateAbsentWages(Employee employees[], int numEmployees, int j) {
    int absentDays;
    float absentWage;

    cout << "Enter number of absent days for " << employees[j].name << ": \n";
    cin >> absentDays;
    employees[j].absentDays = absentDays;
    validateAbsentDays(absentDays);

    absentWage = (absentDays * (employees[j].baseWage) / 26);
    employees[j].absentWage = absentWage;
    employees[j].totalWage -= absentWage; 
}

bool validateAbsentDays(int& absentDays) {
    while (absentDays < 0 || absentDays > 26 || cin.fail()) {
        cin.clear(); // Clear the fail state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Error: absent days must be between 0 and 26. Please re-enter: \n";
        cin >> absentDays;
    }
    return true;
}

void calculateTax(Employee employees[], int numEmployees, int j){
float absentWage;

  employees[j].totalWagetax = employees[j].totalWage - (employees[j].totalWage * TAX_RATE);


}
 
void displayPayslip(Employee employees[], int numEmployees) {
    cout << "Payslip" << endl;
    cout << setw(10) << "Name" << setw(10) << "id number" << setw(15) << "Base Wage" << setw(15) << "Overtime Wage"
              << setw(15) << "Tax" << setw(15) << "Total Wage"  << endl;

    for (int i = 0; i < numEmployees; i++) {

        float taxAmount = employees[i].totalWage * TAX_RATE;
        cout << setw(10) << employees[i].name << setw(10) << employees[i].idnumber << setw(15) << employees[i].baseWage << setw(15)
                  << employees[i].overtimeWage << setw(15) << taxAmount << setw(15) << employees[i].totalWage << endl;
    }
}


void printToFile(Employee employees[], int numEmployees) {
   
  ofstream myFile;
    myFile.open("wages.txt"); // change the file path to match your desktop location
   
	
	 for (int i = 0; i < numEmployees; i++) 
	 	{
            employees[i].absentDays;
	 		myFile << "\n\t\t                       PROGRAMMING 4LIFE SDN.BHD.                              "<<endl;
    	    myFile << "\n\t\t                      monthly payslip                              "<<endl;
    myFile << "\t\t	/////////////////////////////////////////////////////////////////////////////////////"<<endl;
    myFile << "\t\t	| Workers  Name   :"<<"------------------------------------|"<<employees[i].name  <<endl;
    myFile << "\t\t	| Id Number       :"<<"------------------------------------|" << fixed << setprecision(5) <<employees[i].idnumber  <<endl;              
    myFile << "\t\t	| Basic salary    :"<<"------------------------------------|"<<"RM "<<employees[i].baseWage   <<endl;  
    myFile << "\t\t	| overtime hours  :"<<"------------------------------------|"<< fixed  << employees[i].overtimeHours   <<endl;  
    myFile << "\t\t	| overtime salary :"<<"------------------------------------|"<<  employees[i].overtimeWage  <<endl; 
	myFile << "\t\t	| Absent deductions:"<<"-----------------------------------|"<<"RM"<<employees[i].absentWage   <<endl;
    myFile << "\t\t	| Absent Days:"<<"-----------------------------------------|"<< employees[i].absentDays   <<endl;
    myFile << "\t\t	| Tax Amount    :"<<"--------------------------------------|"<<"RM "<< fixed << setprecision(4)  <<employees[i].totalWage * TAX_RATE    <<endl;
    myFile << "\t\t	| total salary    :"<<"------------------------------------|"<<"RM "<<employees[i].totalWagetax  <<endl;    
    
    myFile << "\t\t	 _____________________________________________________________________________________"<<endl;
    myFile << "\t\t	 # This is a computer generated payslip and it does not"<<endl;
    myFile << "\t\t	 require an authorised signture #"<<endl;
    myFile <<" "<<endl;
    myFile << "\t\t	//////////////////////////////////////////////////////////////////////////////////////"<<endl;
    myFile << "\t\t	keep the hardwork and dont ever give up in your life       "<<endl;
    myFile << "\t\t	thank you"<<endl;
    myFile << "\t\t	//////////////////////////////////////////////////////////////////////////////////////"<<endl;

		}
}