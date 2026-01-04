/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign8.cpp --
 * Description:
 *     A rational number calculator program that performs arithmetic
 *     operations (addition, subtraction, multiplication, and division)
 *     on fractions entered by the user. The program uses functions,
 *     parameter passing by reference, and reduction to lowest terms.
 *
 * Input:
 *     Prompts the user to select an operation (1–5), then to enter
 *     two rational numbers (each as numerator and denominator).
 *
 * Output:
 *     Displays the simplified operands and the result of the selected
 *     arithmetic operation in reduced fractional form.
 *
 * Author: Krishang Sarkar
 * Date: November 8, 2025
 *******************************************************************/
#include <iostream>
using namespace std;

/* function Prototypes and definitions */
void userPrompt(int &choice);
void add(int &ln, int &ld, int &rn, int &rd);
void subtract(int &ln, int &ld, int &rn, int &rd);
void multiply(int &ln, int &ld, int &rn, int &rd);
void divide(int &ln, int &ld, int &rn, int &rd);
void reduce(int &num, int &den);
int gcd(int x, int y);

/******************************************************************
 * main -- controls overall program flow
 *
 * Parameters: none
 * Modifies: cout, cin -- for user interaction
 *
 * Returns: 0 upon successful completion
 *******************************************************************/
int main()
{
  //declaration and intialization of variables
  int choice = 0;//choice variable 
  int ln = 0, ld = 1, rn = 0, rd = 1; // operands stored here and passed by reference

  //do while loop restricts any outuput  out of the domain of 1-5
  do
  {
    userPrompt(choice); // read menu choice only using switch case
    switch (choice)
    {
    case 1:
      add(ln, ld, rn, rd);
      break;
    case 2:
      subtract(ln, ld, rn, rd);
      break;
    case 3:
      multiply(ln, ld, rn, rd);
      break;
    case 4:
      divide(ln, ld, rn, rd);
      break;
    case 5:
      cout << "Calculator terminated.\n";

      break;
    default:
      cout << "Invalid choice! Please select a number between 1 and 5\n";
      break;
    }
  } while (choice != 5);

  return 0;
}

/******************************************************************
 * userPrompt -- displays the main menu and reads user’s choice
 *
 * Parameters:
 *   choice -- reference variable to store user's selected operation
 *
 * Modifies: cout, cin
 *
 * Returns: nothing
 *******************************************************************/
void userPrompt(int &choice)
{
  //promting statements
  cout << "Rational number calculator\n";
  cout << "1) Add\n";
  cout << "2) Subtract\n";
  cout << "3) Multiply\n";
  cout << "4) Divide\n";
  cout << "5) Exit\n";
  cout << "\nPlease select an operation from above (1 - 5): \n";
  cin >> choice;//intputs choice
}

/******************************************************************
 * reduce -- reduce the rational to lowest terms
 *
 * Parameters:
 *   num -- the numerator of the rational (input/output)
 *   den -- the denominator of the rational (input/output)
 *
 * Returns: nothing
 ******************************************************************/
void reduce(int &num, int &den)
{
  if (den == 0)
  { // Error case. Just make it 0/1
    num = 0;
    den = 1;
  }
  else
  {
    if (den < 0)
    { // Make sure only numerator is negative.
      num *= -1;
      den *= -1;
    }

    int div;
    if (num >= 0)
    {
      div = gcd(num, den);
    }
    else
    {
      div = gcd(-num, den);
    }
    if (div > 1)
    {
      num /= div;
      den /= div;
    }
  }
}

/******************************************************************
 * gcd -- Calculate the greatest common divisor (Euclid's algorithm)
 *
 * Parameters:
 *   x, y -- the numbers to find the gcd of (input)
 *
 * Returns: the greatest common divisor of x and y
 ******************************************************************/
int gcd(int x, int y)
{
  while (y > 0)
  {
    int z;
    z = x % y;
    x = y;
    y = z;
  }
  return (x);
}
/******************************************************************
 * add -- adds two rational numbers and displays the result
 *
 * Parameters:
 *   ln, ld -- left operand numerator and denominator
 *   rn, rd -- right operand numerator and denominator
 *
 * Modifies: cout, cin
 * Returns: nothing
 *******************************************************************/
void add(int &ln, int &ld, int &rn, int &rd)
{
  cout << "Please enter the left operand numerator followed by denominator: " << endl;
  cin >> ln >> ld;
  cout << "Please enter the right operand numerator followed by denominator: " << endl;
  cin >> rn >> rd;

  // Reduce operands before computing (so output shows 1/3 instead of 3/9)
  reduce(ln, ld);
  reduce(rn, rd);

  // Perform addition: (a/b + c/d = (ad + bc)/(bd))
  int num = ln * rd + rn * ld;  // Cross multiply and add numerators
  int den = ld * rd;            // Multiply denominators
  reduce(num, den);             // Reduce the result to lowest terms

  // Display the result
  cout << endl
       << ln << "/" << ld << " + " << rn << "/" << rd << " = " << num << "/" << den << endl;
}
/******************************************************************
 * subtract -- subtracts one rational number from another
 *
 * Parameters:
 *   ln, ld -- left operand numerator and denominator
 *   rn, rd -- right operand numerator and denominator
 *
 * Modifies: cout, cin
 * Returns: nothing
 *******************************************************************/
void subtract(int &ln, int &ld, int &rn, int &rd)
{
  cout << "Please enter the left operand numerator followed by denominator: " << endl;
  cin >> ln >> ld;
  cout << "Please enter the right operand numerator followed by denominator: " << endl;
  cin >> rn >> rd;

  // function call :Reduce operands beforecomputing (so output shows 1/3 instead of 3/9)
  reduce(ln, ld);
  reduce(rn, rd);

  int num = ln * rd - rn * ld;
  int den = ld * rd;
  reduce(num, den);

  cout << endl
       << ln << "/" << ld << " - " << rn << "/" << rd << " = " << num << "/" << den << endl;
}
/******************************************************************
 * multiply -- multiplies two rational numbers
 *
 * Parameters:
 *   ln, ld -- left operand numerator and denominator
 *   rn, rd -- right operand numerator and denominator
 *
 * Modifies: cout, cin
 * Returns: nothing
 *******************************************************************/
void multiply(int &ln, int &ld, int &rn, int &rd)
{
  cout << "Please enter the left operand numerator followed by denominator: " << endl;
  cin >> ln >> ld;
  cout << "Please enter the right operand numerator followed by denominator: " << endl;
  cin >> rn >> rd;
  // function call :Reduce operands beforecomputing (so output shows 1/3 instead of 3/9)
  reduce(ln, ld);
  reduce(rn, rd);
  //computations
  int num = ln * rn;
  int den = ld * rd;
  reduce(num, den);//function call
//output statemtns
  cout << endl
       << ln << "/" << ld << " * " << rn << "/" << rd << " = " << num << "/" << den << endl;
}

/******************************************************************
 * divide -- divides one rational number by another
 *
 * Parameters:
 *   ln, ld -- left operand numerator and denominator
 *   rn, rd -- right operand numerator and denominator
 *
 * Modifies: cout, cin
 * Returns: nothing
 *******************************************************************/
void divide(int &ln, int &ld, int &rn, int &rd)
{
  cout << "Please enter the left operand numerator followed by denominator: " << endl;
  cin >> ln >> ld;
  cout << "Please enter the right operand numerator followed by denominator: " << endl;
  cin >> rn >> rd;
// function call :Reduce operands beforecomputing (so output shows 1/3 instead of 3/9)
  reduce(ln, ld);
  reduce(rn, rd);

  if (rn == 0)
  {
    cout << "Error: division by zero is undefined." << endl;
    return;
  }
  // Perform division: (a/b / c/d = ad/bc)
  int num = ln * rd;            // Cross multiply numerator
  int den = ld * rn;            // Cross multiply denominator
  reduce(num, den);             // Reduce the result to lowest terms

  // Display the result
  cout << endl
       << ln << "/" << ld << " / " << rn << "/" << rd << " = " << num << "/" << den << endl;
}
