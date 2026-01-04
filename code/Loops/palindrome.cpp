#include <iostream>
using namespace std;

int main()
{
    int n, q, rem, result = 0;
    cout << "please enter a number= ";
    cin >> n;
    q = n;
    
    while (q != 0)
    {
        rem = q % 10;
        result = result * 10 + rem;
        q = q / 10;
    }
    if (result == n) 
        cout << "It is a palindrome " << endl;
    else // Otherwise, it's not a palindrome
        cout << "It is not a palindrome" << endl;
    return 0;
}