/******************************************************************
 * Simon Fraser University, School of Engineering Sciecne
 * ENSC 151 Introduction to Software for Engineering
 * printname.cpp -- Demonstrate string expressions.
 *
 *
 * Author: Cheng
 * Date: 2015.10.02
 *
 *******************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

//const string FIRST = "Cheng";       // My first name
//const string LAST = "Li";           // My last name
//const char INITIAL = 'C';           // My initial

/******************************************************************
 * main
 *
 * Parameters: none
 * Modifies: cout -- outputs the name in various forms.
 *
 * Returns: 0
 *******************************************************************/
int main() {
  
  string firstLast;                 // Name in First Last format
  string firstName, lastName;       // First Last name
  char initial;

  cout << "Please enter your name in the order of First, Last, and initial: ";
  cin >> firstName >> lastName >> initial;

  firstLast = firstName + " " + lastName;
  cout << "My name is: " << firstLast << endl;

  string lastFirst;                 // Name in Last, First format
  lastFirst = lastName + ", " + firstName;

  cout << "in last, first format: " << lastFirst;
  cout << ", and with my initial: " << lastFirst << " " 
       << initial << "." << endl;

  return 0;
}

/******************************************************************
 * $RCSfile$   $Revision$
 * $Date$
 * $State$ 
 *
 *                     REVISION HISTORY
 *
 * $Log$
 *
 ******************************************************************/
