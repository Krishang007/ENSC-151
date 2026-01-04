/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign5.cpp -- Surveyor's Assistant
 *
 * Input: a single compass heading in degrees (0–360),
 *        possibly with a decimal point value.
 * Output: equivalent bearing in the form dir1 ang dir2 such as
 *         South 70 East
 *
 * Author: Krishang Sarkar
 *******************************************************************/
// Libraries and preprocesser directives used in the program
#include <iostream>
using namespace std;

// Function Declarations for the program
void angleToBearing(double angle_input);
/******************************************************************
 * main --
 * Parameters: none
 * Modifies: cin, cout
 * Returns: 0
 *******************************************************************/
int main()
{
    //variable declaration for the main function
    //angle_input would act as a global variable for the program
    double angle_input;
    //for loop coutner variable
    int i;
    // Each run of the program will take 5 iterations before the program exit.

    for (i = 0; i < 5; i++)
    {
        cout << "Please enter heading [0, 360):" << endl;
        cin >> angle_input;
        // calling the angleToBearing function
        angleToBearing(angle_input);
    }

    return 0;
}
//function implementation
/******************************************************************
 * angleToBearing -- compute and display the compass bearing
 *
 * Parameters: angle_input -- compass heading in degrees
 * Modifies: cout
 * Precondition: 0 <= angle_input < 360
 * Returns: nothing
 *******************************************************************/
void angleToBearing(double angle_input)
{
    //declare local variables for this function
    string dir1, dir2;
    double angle_bearing;

    // Invalid input
    if (angle_input < 0 || angle_input > 360)
    {
        cout << angle_input << " is an invalid input." << endl;
        return;
    }

    // Quadrant 1: 0°–90°
    if (angle_input >= 0 && angle_input < 90)
    {
        dir1 = "North";
        dir2 = "East";
        angle_bearing = angle_input;
    }
    // Quadrant 2: 90°–180°
    else if (angle_input >= 90 && angle_input < 180)
    {
        dir1 = "South";
        dir2 = "East";
        angle_bearing = 180 - angle_input;
    }
    // Quadrant 3: 180°–270°
    else if (angle_input >= 180 && angle_input < 270)
    {
        dir1 = "South";
        dir2 = "West";
        angle_bearing = angle_input - 180;
    }
    // Quadrant 4: 270°–360°
    else
    {
        dir1 = "North";
        dir2 = "West";
        angle_bearing = 360 - angle_input;
    }
    // Output the result of the bearing conversion
    cout << "Heading of : " << angle_input << " degrees is "
         << dir1 << " " << angle_bearing << " " << dir2 << endl;
}