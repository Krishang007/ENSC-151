/*
 *  This program generates a 6-digit random number to simulate an OTP (One-Time Password) for an authentication system.
 *  The user is prompted to enter the OTP, and the program checks if the entered OTP matches the generated one.
 *  author: Krishang Sarkar
 */
//  library ,header and pre processor files used in the program
//  are standard input output stream, cstdlib and ctime
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 *  main function - entry point of the program
 *  parameters - none
 *  return type - int (returns 0 on successful execution)
 */
int main()
{
    srand(time(0)); // seed using current time
    //  6 digit random number for a authentication system
    int random = 100000 + rand() % 900000; // range: 100000–999999
    int password;
    cout << "otp:" << random << endl;
    //  enter the password
    cout << "Enter the password: ";
    cin >> password;
    //  check the password
    if (password == random)
    {
        cout << "Correct password" << endl;
    }
    else
    {
        cout << "Wrong password" << endl;
    }
    return 0;
}
