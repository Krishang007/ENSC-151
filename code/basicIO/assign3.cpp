/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign3.cpp --
 * The speed after 1 minute, in km/h, with decimal.
 * Output:rate of deceleration,estimated coasting time and the distance that the
 * cyclist will have travelled in that time Author: Krishang Sarkar
 *******************************************************************/
#include <cmath>
#include <iostream>
using namespace std;

/******************************************************************
 * main --
 *
 * Parameters: none
 * Modifies: cin, cout -- for user interaction
 *
 * Returns: 0
 *******************************************************************/

int main() {
  // declare all the variables used in the program
  double initialSpeed, speedAfterOneMinute, vin, vfin;
  double rateOfDeceleration, timeToStop, distance;

  // input and output statement before computation
  cout << "Initial speed=" << endl;
  cin >> initialSpeed;
  cout << "one minute speed =";
  cin >> speedAfterOneMinute;

  /* equations to compute rate of deceleration,estimated coasting time
   and the distance that the cyclist will have travelled in that time*/
  vin = (1000 * initialSpeed) / 3600;
  vfin = (1000 * speedAfterOneMinute) / 3600;
  rateOfDeceleration = fabs((vfin - vin) / 60.0);
  timeToStop = vin / fabs(rateOfDeceleration);
  // total coasting time in seconds (timeToStop is a double)
  int totalSeconds = int(round(timeToStop)); // round to nearest whole second
  int minutes = totalSeconds / 60;           // full minutes
  int seconds = totalSeconds % 60;           // remaining seconds
  distance = (pow(vin, 2)) / (2 * rateOfDeceleration);

  /* output after the computation rate of deceleration,estimated coasting time
   and the distance that the cyclist will have travelled in that time*/

  cout << "deceleration = " << rateOfDeceleration << ",m/s^2";
  cout << "minutes = " << minutes << ", ";
  cout << "seconds = " << seconds << ", ";
  cout << "distance = " << int(round(distance)) << "m" << endl;
}