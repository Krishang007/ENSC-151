/******************************************************************
 * Simon Fraser University
 * ENSC-151 – Introduction to Software Development for Engineers
 * assign9.cpp
 *
 * Description:
 *    This program uses structures, vectors, and file input/output
 *    to process employee timesheets and sales data. vectors are used
 *    for dynamic memory management, allowing the list of employees
 *    to grow or shrink without requiring a fixed-size array.
 *
 * Input:
 *    Employee timesheet data (ID, first name, last name, hours)
 *    Employee sales data (ID, sales amount)
 *    data is inputed to the program through readign the two text file
 *    sales.txt and timesheet.txt
 * Output:
 *     Printing  pay stubs for each employee including their:
 *       - Employee name
 *        - Employee number
 *       - Base pay
 *       - Commission
 *       - Total pay
 *
 * Author: Krishang Sarkar
 * Date: November 15, 2025
 *******************************************************************/
#include <fstream>  //file input output stream
#include <iomanip>  // precision for floatign points
#include <iostream> //input out stream
#include <sstream>  // string stream operations
#include <string>   // string openration
#include <vector>   // vector operation for push bac

using namespace std;

// Employee struct groups related data together into one unit.
// Instead of keeping separate arrays for IDs, names, hours, and sales,
// we store all attributes of an employee inside a single structure.
// This makes the program easier to read, maintain, and pass around to
// functions. information acces through timmesheet ans sales file s
struct Employee {
  string id;         // empployee id
  string firstName;  // first name
  string lastName;   // last name
  double hours;      // number of hours worked
  double salesTotal; // total saled
};

// Function prototypes
// functions for file io and printing ouput
// uses pass by refrences when accessing employee
// vector
void readTimesheets(vector<Employee> &employees);
void readSales(vector<Employee> &employees);
void printPayStubs(const vector<Employee> &employees);
// functions for calulcations and used pass by value
double calculateBasePay(double hours);
double calculateCommission(double sales);
double calculateTotalPay(double basePay, double commission);

int main() { // Vector to store Employee structs; allows dynamic resizing as
             // employees are read from files
  vector<Employee> employees;
  // function calling
  readTimesheets(employees); // load hours and names
  readSales(employees);      // add sales amounts

  printPayStubs(employees); // output detailed pay stubs

  return 0;
}
// function declarations
/******************************************************************
 * readTimesheets -- reads employee timesheet data from file
 *
 * Parameters:
 *   employees (vector<Employee>&) - list of employees, updated in-place
 * Modifies:
 *   employees vector - adds new Employee records
 * Returns:
 *   Nothing (void)
 *******************************************************************/
void readTimesheets(vector<Employee> &employees) {
  ifstream indata;
  indata.open("timesheets.txt");

  if (!indata) {
    // I Used cerr for error messages because cerr is unbuffered and outputs
    // immediately, ensuring errors are shown even if the program crashes or
    // the output buffer is not flushed.
    cerr << "Error: Could not open timesheets.txt" << endl;
    return;
  }

  string id;          // employee id
  string first, last; // employee name
  double hours;       // time

  // File format example:
  // inputs  to the struct
  while (indata >> id >> hours >> first >> last) {
    Employee emp;
    emp.id = id;
    emp.firstName = first;
    emp.lastName = last;
    emp.hours = hours;
    emp.salesTotal = 0.0;
    employees.push_back(emp);
  }

  indata.close();
}
/******************************************************************
 * readSales -- reads weekly sales data and updates employee totals
 *
 * Parameters:
 *   employees (vector<Employee>&) - list of all employees, updated in-place
 *
 * Modifies:
 *   employees[i].salesTotal - adds sales amounts to matching employee IDs
 *
 * Returns:
 *   Nothing (void)
 *******************************************************************/
void readSales(vector<Employee> &employees) {
  ifstream indata;
  indata.open("sales.txt");

  if (!indata) {
    // I Used cerr for error messages because cerr is unbuffered and outputs
    // immediately, ensuring errors are shown even if the program crashes or
    // the output buffer is not flushed.
    cerr << "Error: Could not open sales.txt" << endl;
    return;
  }

  string id;         // employee id
  double saleAmount; // sale ammoutnt

  // Read each sale entry: employee ID + sale amount
  // and store it in the employee
  while (indata >> id >> saleAmount) {
    // Search for the employee with the matching ID
    for (auto &emp : employees) {
      if (emp.id == id) {
        // Add the sale amount to that employee's total sales
        emp.salesTotal += saleAmount;
        break; // stop searching once matched
      }
    }
  }

  indata.close();
}

// function for calculautions
/******************************************************************
 * calculateBasePay -- caulate base pay of the employee
 *
 * Parameters:
 *   hours -- number of hourse worked
 * Modifies: none
 *
 * Returns:  base pay
 *******************************************************************/
double calculateBasePay(double hours) { return hours * 16.50; }

/******************************************************************
 * calculateCommission -- calculate commission based on sales
 *
 * Parameters:
 *   sales -- total sales amount
 *
 * Modifies: none
 * Returns: commission (double)
 *******************************************************************/
double calculateCommission(double sales) { return sales * 0.03; }

/******************************************************************
 * calculateTotalPay -- calculate gross total pay
 *
 * Parameters:
 *   basePay -- employee's base pay
 *   commission -- employee's commission
 *
 * Modifies: none
 * Returns: total pay (double)
 *******************************************************************/
double calculateTotalPay(double basePay, double commission) {
  return basePay + commission;
}
/******************************************************************
 * formatoutput -- formats a numeric value with trailing zeros removed
 *
 * Parameters:
 *   value (double) - the numeric value to format
 *   precision (int) - number of decimal places to display
 *
 * Modifies:
 *   None
 *
 * Returns:
 *   string - formatted number without trailing zeros or decimal point
 *
 *******************************************************************/

string formatoutput(double value, int precision) {
  ostringstream oss;
  oss << fixed << setprecision(precision) << value;

  string s = oss.str();

  // Remove trailing zeros
  while (!s.empty() && s.back() == '0')
    s.pop_back();

  // Remove trailing decimal point
  if (!s.empty() && s.back() == '.')
    s.pop_back();

  return s;
}

/******************************************************************
 * printPayStubs -- prints pay information for all employees
 *
 * Parameters:
 *   employees (const vector<Employee>&) - list of all employees
 *
 * Modifies:
 *   cout -- prints formatted pay stubs to standard output
 *
 * Returns:
 *   Nothing (void)
 *******************************************************************/

void printPayStubs(const vector<Employee> &employees) {
  double totalSales = 0.0;
  double totalPayroll = 0.0;

  cout << fixed << setprecision(2); // to ensure money prints with 2 decimals

  for (const auto &emp : employees) {
    // Format name: LastName, FirstInitial
    char firstInitial = emp.firstName[0];
    // string formattedName = emp.lastName + ", " + firstInitial;

    string formattedName = emp.firstName + " " + emp.lastName;

    double basePay = calculateBasePay(emp.hours);
    double commission = calculateCommission(emp.salesTotal);
    double totalPay = calculateTotalPay(basePay, commission);

    // Add to company totals
    // using compound sum operators
    totalSales += emp.salesTotal;
    totalPayroll += totalPay;

    // Output pay stub in assignment format
    
    cout << "Name: " << formattedName << endl;
    cout << "Employee Number: " << emp.id << endl;
    
    cout << "Hours Worked: " << formatoutput(emp.hours, 1) << endl;
    cout << "Base Pay: $" << formatoutput(basePay, 2) << endl;
    cout << "Total Sales: $" << formatoutput(emp.salesTotal, 2) << endl;
    cout << "Commission: $" << formatoutput(commission, 4) << endl;
    cout << "Total Pay: $" << formatoutput(totalPay, 3) << endl;
  }


