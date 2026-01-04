#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // declare variables needed for the program
    double num_stridesforfirstmin;
    double num_stridesforlastmin;
    double avg_strides;
    double time;
    double min;
    double hour;
    double time_min;
    double avg_striderate;
    double totaldistance;

    // input and output statements used in the program
    cout << "Please enter the number of strides taken in the first minute:";
    cin >> num_stridesforfirstmin;
    cout << "Please enter the number of strides taken in the last minute: ";
    cin >> num_stridesforlastmin;
    cout << "Please enter the number of hours and minutes jogged:";
    cin >> hour >> min;

    avg_strides = (num_stridesforfirstmin + num_stridesforlastmin) / 2.0;
    avg_striderate = avg_strides;
    time_min = hour * 60 + min;
    totaldistance = (avg_striderate * time_min * 0.75) / 1000.0;
    cout << fixed << setprecision(0);
    cout << "Arnie's estimated average stride rate (strides/minute):" << avg_striderate;
    cout << fixed << setprecision(4);
    cout << "Total distance that Arnie has jogged (km): " << totaldistance << endl;
    return 0;
}
