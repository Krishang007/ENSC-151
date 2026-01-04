#include <iostream>
using namespace std;
long rec(int x);
int main()
{
    
    unsigned int n = 0;
    unsigned long fact = 1;

    cout << "Enter a positve number:";
    cin >> n;

    fact = rec(n);
    cout << "Factorial = " << fact<<endl;
    return 0;
}

long rec(int x)
{
    int f;
    if (x == 1)
    {
        return 1;
    }
    else
        f = x * rec(x - 1);
    return f;
}