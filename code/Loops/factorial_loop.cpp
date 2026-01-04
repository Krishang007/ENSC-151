#include <iostream>
using namespace std;

int main()
{
    unsigned int n = 0;
    unsigned long fact = 1;

    cout << "Enter a number ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        fact *= i;
    }

    cout << "Factorial = " << fact << endl;
    return 0;
}