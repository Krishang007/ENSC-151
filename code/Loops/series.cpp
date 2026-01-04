#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // geometric progression
    int i = 1;
    //int r = 2;
     
    float r, e,u;
    // enter the common ratio
    cout << "Enter the common ratio: ";
    cin >> r;
    cout << "Enter the number of terms: ";
    //  number of terms=e
    cin>>e;
    // using
    while (i <= e)
    {
        u = pow(r, i - 1);
        cout << u << " ";
        i++;
    }
    //  print convergence of of series if -1<r >1
    //  print the assymptie convergence value if series is convergent
    if (r > -1 && r < 1)
    {
        float sum = 1 / (1 - r);
        cout << "\nThe series is convergent and the sum is: " << sum << endl;
        
    }
    else
    {
        cout << "\nThe series is divergent" << endl;
    }
}
