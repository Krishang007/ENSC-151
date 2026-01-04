#include <iostream>
using namespace std;

int main()
{

    int n, result = 0, q, rem;

    cout<<"Please enter a number ";
    cin>> n;
    q=n;
    while (q != 0)
    {
        rem = q % 10;

        result = result * 10 + rem;
        q = q / 10;
    }
    if (result==n)
    {
        cout<<"Its a palindrome \n";
   
    }
    else
    cout<<"No its not a palindrome \n";
    
    return 0;
    
    
}