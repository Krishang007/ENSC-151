#include <iostream>
using namespace std;

int main()
{

    float age;
    cout << "Enter your age:\n";
    // printf("Enter your age:\n ");
    cin >> age;

    // scanf("%f",&age );
    float dogyear;
    dogyear = age * 7;

    cout << "Age in dog years is: " << dogyear << "\n";

    return 0;
}