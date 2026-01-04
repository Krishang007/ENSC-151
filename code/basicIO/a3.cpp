
#include <cmath>
#include <iostream>
using namespace std;

// Function prototypes (declarations)
void programDescription();//no parameters
double calcDeceleration(double vfin, double vin, double time);//3 parameters
double calcTime(double vin, double rateOfdeceleration);//2 parameters
double calcDistance(double vin, double rateOfdeceleration);//2 parameters
int main() {
  // variable declaration and intializating
  double initialSpeed = 0.0, speedAfterOneMinute = 0.0;
  programDescription();
  // Prompting statements
  cout << "initial speed = ";
  cin >> initialSpeed;
  cout << " km/h" << endl;

  cout << "one minute speed = ";
  cin >> speedAfterOneMinute;
  cout << " km/h" << endl;

  // computation and calculation for the program
  double vin = initialSpeed * (1000.0 / 3600.0);
  double vfin = speedAfterOneMinute * (1000.0 / 3600.0);
  // Call functions to perform calculations
  double rateOfdeceleration =
      calcDeceleration(vfin, vin, 60.0); // Pass 3 arguments
  double estimatedCoastingTime =
      calcTime(vin, rateOfdeceleration);                   // Use function
  double distance = calcDistance(vin, rateOfdeceleration); // Use function

  // double estimatedCoastingTime = vin / rateOfdeceleration;
  int totalTime = int(round(estimatedCoastingTime));//type cast
  int min = totalTime / 60;//type cast and integer division
  int sec = totalTime % 60;//remainder of the division

  // double distance = pow(vin, 2) / (2 * rateOfdeceleration);
  int distance_round = int(round(distance));

  // output
  cout << "deceleration=" << rateOfdeceleration;
  cout << "minutes=" << min;
  cout << "seconds=" << sec;
  cout << "distance=" << distance_round;
  return 0;
}
//function implementation
//header comment for function
/*
*function name: programDescription
*description: This function prints a description of the program
*parameters: none
*return value: none
*/
void programDescription() {
  cout << "This program calculates:" << endl;
  cout << "  - Rate of deceleration" << endl;
  cout << "  - Coasting time until stop" << endl;
  cout << "  - Total distance traveled" << endl;
  cout << endl;
}
/*
*function name: calcDeceleration
*description: computes deceleration
*parameters: vfin, vin, time
*return value: deceleration
*/
double calcDeceleration(double vfin, double vin, double time) {
  return fabs(vfin - vin) / time;
}

/*
*function name: calcTime
*description: computes time
*parameters: vin, rateOfdeceleration
*return value: time
*/
double calcTime(double vin, double rateOfdeceleration) {
  return vin / rateOfdeceleration;
}

/*
*function name: calcDistance
*description: computes distance
*parameters: vin, rateOfdeceleration
*return value: distance
*/
double calcDistance(double vin, double rateOfdeceleration) {
  return pow(vin, 2) / (2 * rateOfdeceleration);
}

/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Variable declaration and initialization
    double initialSpeed = 0.0, speedAfterOneMinute = 0.0;

    // Prompting statements
    cout << "Enter initial speed of the cycle in km/h: ";
    cin >> initialSpeed;
    cout << "Enter speed of the cycle after 1 minute in km/h: ";
    cin >> speedAfterOneMinute;

    // Convert speeds from km/h to m/s
    double vin = kmhToMs(initialSpeed);
    double vfin = kmhToMs(speedAfterOneMinute);

    // Calculate deceleration (1 minute = 60 seconds)
    double rateOfDeceleration = calculateDeceleration(vin, vfin, 60.0);

    // Calculate estimated coasting time
    double estimatedCoastingTime = calculateCoastingTime(vin,
rateOfDeceleration); int totalTime = int(round(estimatedCoastingTime));

    // Extract minutes and seconds
    int min = getMinutes(totalTime);
    int sec = getSeconds(totalTime);

    // Calculate distance
    double distance = calculateDistance(vin, rateOfDeceleration);
    int distance_round = int(round(distance));

    // Output
    // cout << "\nResults:" << endl;
    cout << "deceleration = " << rateOfDeceleration << " m/s^2" << endl;
    cout << "minutes = " << min << "seconds" << sec << endl;
    cout << "Distance = " << distance_round;

    return 0;
}

// Function to convert km/h to m/s
double kmhToMs(double speedKmh)
{
    return speedKmh * (1000.0 / 3600.0);
}

// Function to calculate deceleration (m/s^2)
double calculateDeceleration(double initialSpeedMs, double finalSpeedMs, double
timeSeconds)
{
    return fabs(finalSpeedMs - initialSpeedMs) / timeSeconds;
}

// Function to calculate coasting time (seconds)
double calculateCoastingTime(double initialSpeedMs, double deceleration)
{
    return initialSpeedMs / deceleration;
}

// Function to calculate distance traveled (meters)
double calculateDistance(double initialSpeedMs, double deceleration)
{
    return pow(initialSpeedMs, 2) / (2 * deceleration);
}

// Function to extract minutes from total seconds
int getMinutes(int totalSeconds)
{
    return totalSeconds / 60;
}

// Function to extract remaining seconds
int getSeconds(int totalSeconds)
{
    return totalSeconds % 60;
}
    */