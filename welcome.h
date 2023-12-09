//welcome.h
#include "Employee.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <dos.h>

class welcome //welcome class
{
	public:
	int welcum()
	{
 ifstream in("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353

  if(!in) 
  {
    cout << "Cannot open input file.\n";
  }
  char str[1000];
  while(in) 
  {
    in.getline(str, 1000);  // delim defaults to '\n' cp
    if(in) cout << str << endl;
  }
  in.close();
  sleep(1);
  cout<<"\nStarting the program please wait....."<<endl;
  sleep(1);
  cout<<"\nloading up files....."<<endl;
  sleep(1); //function which waits for (n) seconds
  system ("CLS"); //cleares screen
    return 0; }
};
bool login();
int getNumEmployees();