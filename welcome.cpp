//welcome.cpp

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

bool login() {
    string pass = "";
    char ch;

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t     PROGRAMMING 4LIFE SDN.BHD HUMANS' RESOURCES' \n\n";
    cout << "\t\t\t\t\t------------------------------";
    cout << "\n\t\t\t\t\t\t     LOGIN \n";
    cout << "\t\t\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t\tEnter Password: ";

    ch = _getch();
    while (ch != 13) // character 13 is enter
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    if (pass == "4life") {
        cout << "\n\n\n\t\t\t\t\t\t       Access Granted!     \n";
        system("PAUSE");
        system("CLS");
        return true;
    } else {
        cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
        system("PAUSE");
        system("CLS");
        return false;
    }
}

// Function to get the number of employees from the user
int getNumEmployees() {
    int numEmployees;

    cout << "\nEnter the number of employees: \n";
    cin >> numEmployees;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (numEmployees > MAX_EMPLOYEES) {
        cout << "Error: maximum number of employees is " << MAX_EMPLOYEES << ". Please re-enter: \n";
        cin >> numEmployees;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return numEmployees;
}
