
#include <iostream>
using namespace std;

void bearingCalculator(double heading_angle);

int main()
{
    double heading_angle;
    
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Please enter heading [0, 360): ";  
        cin >> heading_angle;
        bearingCalculator(heading_angle);
    }

    return 0;
}

void bearingCalculator(double heading_angle)
{
    string dir1, dir2;
    double bearingAngle;

   
    if (heading_angle < 0 || heading_angle >= 360)
    {
        cout << heading_angle << " is an invalid input." << endl;
        return;  // Stop execution for invalid input
    }

    // Special edge cases (favor North for 90/270, favor East for 0/180)
    if (heading_angle == 0)
    {
        dir1 = "North";
        bearingAngle = 0;
        dir2 = "East";
    }
    else if (heading_angle == 90)
    {
        dir1 = "North";
        bearingAngle = 90;
        dir2 = "East";
    }
    else if (heading_angle == 180)
    {
        dir1 = "South";
        bearingAngle = 0;
        dir2 = "East";
    }
    else if (heading_angle == 270)
    {
        dir1 = "North";
        bearingAngle = 90;
        dir2 = "West";
    }
    // Quadrant 1: 0° < angle < 90°
    else if (heading_angle > 0 && heading_angle < 90)
    {
        dir1 = "North";
        bearingAngle = heading_angle;
        dir2 = "East";
    }
    // Quadrant 2: 90° < angle < 180°
    else if (heading_angle > 90 && heading_angle < 180)
    {
        dir1 = "South";
        bearingAngle = 180 - heading_angle;
        dir2 = "East";
    }
    // Quadrant 3: 180° < angle < 270°
    else if (heading_angle > 180 && heading_angle < 270)
    {
        dir1 = "South";
        bearingAngle = heading_angle - 180;
        dir2 = "West";
    }
    // Quadrant 4: 270° < angle < 360°
    else
    {
        dir1 = "North";
        bearingAngle = 360 - heading_angle;
        dir2 = "West";
    }

    cout << "Heading of : " << heading_angle << " degrees is "
         << dir1 << " " << bearingAngle << " " << dir2 << endl;
}