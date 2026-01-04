/******************************************************************
 * Simon Fraser University
 * ENSC-151 Introduction to Software Development for Engineers
 * assign6.cpp -- Thermal Conduction Calculator
 *
 * Description: Solves for unknowns (k, T2, or X) using H = kA(T2 - T1)/X.
 * Input: User selects which variable to solve for (1, 2, or 3; 0 to exit),
 *        then enters the required known quantities.
 * Output: Displays all thermal values (H, k, A, T1, T2, X) with labels and units.
 * DAte: October 25, 2025
 * Author: Krishang Sarkar
 *******************************************************************/
//libraies and preprocessor directives used in the program
#include <iostream>
using namespace std;

// Function Declarations for the program 
// function called using pass by value 
int menu();
void printPromptsList(int choice);
void getInputValues(int choice, double &H, double &k, double &A, double &T1, double &T2, double &X);
void displayResults(double H, double k, double A, double T1, double T2, double X);
// functions: Take all variables using pass  by reference to update them, return the calculated value.
double solveForK(double &H, double &k, double &A, double &T1, double &T2, double &X);
double solveForT2(double &H, double &k, double &A, double &T1, double &T2, double &X);
double solveForX(double &H, double &k, double &A, double &T1, double &T2, double &X);

/******************************************************************
 * main --
 *
 * Description: Controls the overall program flow for solving
 *              thermal conduction problems using the formula
 *              H = kA(T2 - T1) / X.
 *
 * Parameters: none
 * Modifies: cout, cin -- for user interaction
 *
 * Returns: 0 upon successful completion
 *******************************************************************/
int main()
{
    // user choice variable to chose which variable to solve for
    int choice;
    double H = 0.0, k = 0.0, A = 0.0, T1 = 0.0, T2 = 0.0, X = 0.0;
    
    // Main program loops until user chooses to exit
    do
    {
        choice = menu();

        switch (choice)
        {
        case 1:
            k = solveForK(H, k, A, T1, T2, X);// Call function to solve for k
            displayResults(H, k, A, T1, T2, X);//call function to display results
            break;
        case 2:
            T2 = solveForT2(H, k, A, T1, T2, X);// Call function to solve for T2
            displayResults(H, k, A, T1, T2, X);//call function to display results
            break;
        case 3:
            X = solveForX(H, k, A, T1, T2, X);// Call function to solve for X
            displayResults(H, k, A, T1, T2, X);//call function to display results
            break;
        case 0:
            cout << "Program exiting." << endl;// Exit message
            break;
        default:
            cout << "Invalid choice. Please select 0, 1, 2, or 3." << endl;// Handle invalid input
        }
    } while (choice != 0);

    return 0;
}

/******************************************************************
 * getInputValues -- prompts the user to enter thermal conduction values
 *
 * Parameters:
 *    choice -- integer indicating which variable to solve for:
 *              1 = k, 2 = T2, 3 = X
 *    H  -- rate of heat transfer (W), input by user
 *    k  -- thermal conductivity (W/m·K), input unless solving for k
 *    A  -- cross-sectional area (m^2), input by user
 *    T1 -- temperature at side 1 (K), input by user
 *    T2 -- temperature at side 2 (K), input unless solving for T2
 *    X  -- thickness of the conductor (m), input unless solving for X
 *
 * Modifies: cin -- reads values from the user
 *
 * Returns: nothing
 *******************************************************************/
void getInputValues(int choice, double &H, double &k, double &A, double &T1, double &T2, double &X)
{
    // H is always required
    cout << "Enter H (rate of heat transfer, W): ";
    cin >> H;
    
    // k is skipped if solving for k
    if (choice != 1) {
        cout << "Enter k (coefficient of thermal conductivity, W/m-K): ";
        cin >> k;
    }
    
    // A is always required
    cout << "Enter A (cross-sectional area, m^2): ";
    cin >> A;
    
    // T1 is always required
    cout << "Enter T1 (temp. at side 1, K): ";
    cin >> T1;
    
    // T2 is skipped if solving for T2
    if (choice != 2) {
        cout << "Enter T2 (temp. at side 2, K): ";
        cin >> T2;
    }
    
    // X is skipped if solving for X
    if (choice != 3) {
        cout << "Enter X (thickness, m): ";
        cin >> X;
    }
}

// Function implementations

/******************************************************************
 * choice -- prompt user to select a variable to solve for
 *
 * Parameters: none
 * Modifies: cout, cin -- prompts for user input and displays menu
 *
 * Returns: int -- the user's choice (1, 2, 3, or 0)
 *******************************************************************/

int menu()
{
    // declare local variable
    int choice;
    cout << "Please select one of the following options:\n";
    // Display menu options
    cout << "1) k\n";
    cout << "2) T2\n";
    cout << "3) X\n";
    cout << "0) Exit\n";
    cout << "Selection:\n";
    cin >> choice;
    return choice;
}


/******************************************************************
 * solveForK -- compute the thermal conductivity 'k'
 *
 * Parameters:
 *    H  -- rate of heat transfer (W)
 *    A  -- cross-sectional area (m^2)
 *    T1 -- temperature at side 1 (K)
 *    T2 -- temperature at side 2 (K)
 *    X  -- thickness of the conductor (m)
 *
 * Modifies: cout, cin -- inputs values from user
 *
 * Returns: double -- the computed value of k (W/m·K)
 *******************************************************************/
double solveForK(double &H, double &k, double &A, double &T1, double &T2, double &X)
{
    // Take all inputs, updating H, k, A, T1, T2, X by reference
    getInputValues(1, H, k, A, T1, T2, X);
    return (H * X) / (A * (T2 - T1));
}

/******************************************************************
 * solveForT2 -- compute temperature at side 2 (T2)
 *
 * Parameters:
 *    H  -- rate of heat transfer (W)
 *    k  -- thermal conductivity (W/m·K)
 *    A  -- cross-sectional area (m^2)
 *    T1 -- temperature at side 1 (K)
 *    X  -- thickness of conductor (m)
 *
 * Modifies: cout, cin -- inputs values from user
 *
 * Returns: double -- computed value of T2 (K)
 *******************************************************************/
// double solveForT2(double H, double k, double A, double T1, double X)
// {
double solveForT2(double &H, double &k, double &A, double &T1, double &T2, double &X)
{
    getInputValues(2, H, k, A, T1, T2, X);
    return (H * X) / (k * A) + T1;
}
/******************************************************************
 * solveForX -- compute the conductor thickness 'X'
 *
 * Parameters:
 *    H  -- rate of heat transfer (W)
 *    k  -- thermal conductivity (W/m·K)
 *    A  -- cross-sectional area (m^2)
 *    T1 -- temperature at side 1 (K)
 *    T2 -- temperature at side 2 (K)
 *
 * Modifies: cout, cin -- inputs values from user
 *
 * Returns: double -- computed value of X (m)
 *******************************************************************/
double solveForX(double &H, double &k, double &A, double &T1, double &T2, double &X)
{
    getInputValues(3, H, k, A, T1, T2, X);
    return (k * A * (T2 - T1)) / H;
}

/******************************************************************
 * displayResults -- prints all thermal conduction variables
 *
 * Parameters:
 *    H  -- rate of heat transfer (W)
 *    k  -- thermal conductivity (W/m·K)
 *    A  -- cross-sectional area (m^2)
 *    T1 -- temperature at side 1 (K)
 *    T2 -- temperature at side 2 (K)
 *    X  -- thickness of the conductor (m)
 *
 * Modifies: cout -- displays the values of all variables
 *
 * Returns: nothing
 *******************************************************************/
void displayResults(double H, double k, double A, double T1, double T2, double X)
{
    cout << "------------------------------------------------\n";
    cout << "H = " << H << " W\n";
    cout << "k = " << k << " W/m-K\n";
    cout << "A = " << A << " m^2\n";
    cout << "T1 = " << T1 << " K\n";
    cout << "T2 = " << T2 << " K\n";
    cout << "X = " << X << " m\n";
}