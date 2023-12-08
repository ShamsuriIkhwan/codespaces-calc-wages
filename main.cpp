// main.cpp

using namespace std;
#include "Employee.h"
#include <iostream>
#include <limits>  // Add this line

int main() {
    Employee employees[MAX_EMPLOYEES];
    int numEmployees;
    int j = 0;

    cout << "Enter the number of employees: \n";
    cin >> numEmployees;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (numEmployees > MAX_EMPLOYEES) {
        cout << "Error: maximum number of employees is " << MAX_EMPLOYEES << ". Please re-enter: \n";
        cin >> numEmployees;
    }

    for (int i = 0; i < numEmployees; i++) {
        inputEmployeeData(employees, numEmployees, j);
        calculateWages(employees, numEmployees, j);
        calculateAbsentWages(employees, numEmployees, j);
        j++;
    }

    displayPayslip(employees, numEmployees);
    printToFile(employees, numEmployees);

    return 0;
}
