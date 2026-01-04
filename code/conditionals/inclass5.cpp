/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * inclass5.cpp --
 * Input: Prompt the user to enter three numbers.
 * Output: A value-returning function that computes the average 
 *         of the three numbers. 
 *         A void function that returns the max and min of the 
 *         three numbers.
 * The output of the results will be from the main function.
 * Author: Krishang Sarkar
 * Date: October 30, 2025
 *******************************************************************/

// Libraries and preprocessor directives
#include <iostream>
using namespace std;

// Function declarations
void promptUser(double &num1, double &num2, double &num3);
double average(double num1, double num2, double num3);
void minMax(double num1, double num2, double num3, double &min, double &max);

/******************************************************************
 * main --
 *
 * Description: defins variables, calls functions to get user input
 *
 * Parameters: none
 * Modifies: cout, cin -- for user interaction
 *
 * Returns: 0 upon successful completion
 *******************************************************************/
int main() {
    double num1, num2, num3;
    double min, max;
    double avg;

    // Get user input
    promptUser(num1, num2, num3);

    // Compute average
    avg = average(num1, num2, num3);

    // Compute min and max
    minMax(num1, num2, num3, min, max);

    // Output results
    cout << "The average of the three numbers is: " << avg << endl;
    cout << "The minimum number is: " << min << endl;
    cout << "The maximum number is: " << max << endl;

    return 0;
}

/******************************************************************
 * promptUser --
 * Prompts the user to enter three numbers.
 *******************************************************************/
void promptUser(double &num1, double &num2, double &num3) {
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
}

/******************************************************************
 * average --
 * Computes and returns the average of three numbers.
 *******************************************************************/
double average(double num1, double num2, double num3) {
    return (num1 + num2 + num3) / 3.0;
}

/******************************************************************
 * minMax --
 * Determines the minimum and maximum of three numbers.
 *******************************************************************/
void minMax(double num1, double num2, double num3, double &min, double &max) {
    // Find minimum
    if (num1 <= num2 && num1 <= num3)
        min = num1;
    else if (num2 <= num1 && num2 <= num3)
        min = num2;
    else
        min = num3;

    // Find maximum
    if (num1 >= num2 && num1 >= num3)
        max = num1;
    else if (num2 >= num1 && num2 >= num3)
        max = num2;
    else
        max = num3;
}