//libraries and preprocesser directives used in the program
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // declare variables needed for the program
    double num_stridesforfirstmin;
    double num_stridesforlastmin;
    double avg_striderate;
    double min;
    double hour;
    double time_min;
    // as the unit conversion for stride and metres does not change therefore it 
    const double stride_length =0.75;
    double totaldistance;

    //input and output statements to input and store value to variables  before computing 
    cout << "Please enter the number of strides taken in the first minute:"<<endl;
    cin >> num_stridesforfirstmin;
    cout <<"Please enter the number of strides taken in the last minute:"<<endl;
    cin >> num_stridesforlastmin;
    cout << "Please enter the number of hours and minutes jogged:"<<endl;
    cin >> hour >> min;

    // compute average strides per minute
     avg_striderate= (num_stridesforfirstmin + num_stridesforlastmin) / 2.0;

    // convert jogging time into total minutes
    time_min = (hour * 60) + min;


    // this equation computes total distance jogged in km (stride length = 0.75 m)
    totaldistance =  (avg_striderate * time_min * stride_length) / 1000.0;

    // output functions for the program
    //cout << fixed << setprecision(0);
    cout << "Arnie's estimated average stride rate (strides/minute): " << avg_striderate << endl;
    //rounded to 4 sig figs 
    //cout << fixed << setprecision(4);
    cout << "Total distance that Arnie has jogged (km): " << totaldistance << endl;

    return 0;
}