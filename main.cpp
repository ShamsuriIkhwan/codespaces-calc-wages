// main.cpp

#include "Employee.h"
#include "welcome.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>

// Modified main function
int main() {
    welcome obj1; // object created for welcome class
    obj1.welcum(); // welcum function is called

    if (!login()) {
        return 0; // Exit the program if login fails
    }

    Employee employees[MAX_EMPLOYEES];
    int numEmployees;
    int j = 0;

    numEmployees = getNumEmployees();

    for (int i = 0; i < numEmployees; i++) {
        inputEmployeeData(employees, numEmployees, j);
        calculateWages(employees, numEmployees, j);
        calculateAbsentWages(employees, numEmployees, j);
        calculateTax(employees, numEmployees, j);
        j++;
    }

    displayPayslip(employees, numEmployees);
    printToFile(employees, numEmployees);

    return 0;
}