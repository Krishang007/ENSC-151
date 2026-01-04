// preprocessor directives and header files used in the program
#include <iostream>
using namespace std;

// declaring functions used in the program
// factorial function
long long fact(int n); // long is used to prevent overflow
// combination function
long long ncr(int n, int r); // long is used to prevent overflow

int main()
{
    int j, i, n;
    long long x;

    do
    {
        cout << "Enter number of rows: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "re enter" << endl; // Added endl for better output formatting
        }
    } while (n <= 0);

    for (i = 0; i < n; i++)
    {
        // Leading spaces for centering
        for (j = 0; j < n - i - 1; j++)
        {                 // Corrected: increment j, not i
            cout << "  "; // two spaces for better visual separation
        }

        // Print nCr values for this row
        for (j = 0; j <= i; j++)
        {
            // calling ncr function using pass by value
            x = ncr(i, j);
            cout << x << "   "; // Added spacing after each number
        }
        cout << endl; // Move to next row
    }
    return 0;
}

// function implementation
// used to calculate factorial
long long fact(int n)
{
    /* for (int i = 1; i <= n; i++) {
        f *= i;
    }
    */

    if (n <= 1)
    {
        return 1;
    }
    // recursive case
    else
        return n * fact(n - 1);
}

// applying ncr and the binomial theorem
// to print the pascal triangle
long long ncr(int n, int r)
{
    // to calculate nCr the combination formula is used
    // and is calling the factorial function
    return fact(n) / (fact(r) * fact(n - r));
}