/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign.cpp -- Program to compute duration of the flight, and the height at the target of the projectile
 *
 *Input:The distance to the target (in metres, possibly with a decimal).
 *The launch angle of the projectile (in degrees, measured from the horizontal, whole numbers only).
 *The launch speed (in metres/second, possibly with a decimal).
 * Output: duration of the flight time
 * the height at the target
 * Author: Krishang Sarkar
 *******************************************************************/
#include <iostream>
#include <cmath>
using namespace std;
/******************************************************************
 * main --
 *
 * Parameters: none
 * Modifies: nothing
 *
 * Returns: 0
 *******************************************************************/
int main()
{
    /*declaring the input and output variables used in the program
     launch angle of the projectile in degrees
     distance to the target in metres
     launch speed of the projectile in metres per seconds
     duration in seconds
     */
    double angle, distance, launchSpeed, time, height;

    // gravitaiton constant
    const double g = 9.81;

    // input and output statement before computation
    cout << "This program computes the duration of a projectile's flight and its height." << endl;
    cout << "Enter the distance to the target (m): " << endl;
    cin >> distance;
    cout << "Enter the  launch angle (degrees): " << endl;
    cin >> angle;
    cout << "Enter the  launch speed (m/s): " << endl;
    cin >> launchSpeed;

    // equations to compute  time and height of the projectile
    // and converting angle from degrees to radians
    double rad_angle = angle * M_PI / 180.0;
    time = distance / (launchSpeed * cos(rad_angle));
    height = launchSpeed * sin(rad_angle) * time - 0.5 * g * pow(time, 2);

    // output after the computation  of flight time and height
    cout << "Duration of flight: " << time << " s" << endl;
    cout << "Height at the target: " << height << " m" << endl;

    return 0;
}