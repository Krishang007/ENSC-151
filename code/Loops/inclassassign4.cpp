/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * inclassAssign4 -- Multiplication table generator
 * Output: Generates a Multiplication table using for loops tables from 0 to 9 
 * Author: Krishang Sarkar
 * Date :21 Oct 2025
 *******************************************************************/
// libraries and pre processor directives used in the program 
#include <iostream>
using namespace std;
/******************************************************************
 * main --
 * Parameters: none
 * Modifies: cin, cout
 * Returns: 0
 *******************************************************************/
int main() {
    int row, col; // variables to store row and column values

    // Print header row
    cout << "  | ";
    for (col = 0; col <= 9; col++) {
        cout << col << " ";
    }
    cout << endl;

    // Print separator line
    cout << "-----------------------------------------------" << endl;

    // Nested for loops to generate multiplication table
    for (row = 0; row <= 9; row++) {
        cout << row << " |";
        for (col = 0; col <= 9; col++) {
            int val = row * col;

            // Adjust spacing for alignment
            if (val < 10)
                cout << "  " << val;  // extra space for single-digit numbers
            else
                cout << " " << val;   // one space for two-digit numbers
        }
        cout << endl; // end of each row
    }

    return 0; 
}