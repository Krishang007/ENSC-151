
// libraries and preprocessor directives used in the program
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes/definitions
int getInputCount();
void getValues(double arr[], int n);
double computeAverage(double arr[], int n);
int countAboveAverage(double arr[], int n, double avg);
double findMaximum(double arr[], int n);
void printMaxPositions(double arr[], int n, double maxValue);

/******************************************************************
 * main -- controls overall program flow
 *
 * Parameters: none
 * Modifies: cout, cin -- for user interaction
 *
 * Returns: 0 upon successful completion
 *******************************************************************/
int main()
{   
    // Get number of inputs from user using the declared 
    //get inputcount function 
    int num = getInputCount();

    //array to store the numbers inputed by the user
    double values[100];     // max array size
    getValues(values, num); // get values from user

    // process values from the output returned by the declared functions
    // and store them in variables declared  below
    double avg = computeAverage(values, num);           // compute average
    int numAbove = countAboveAverage(values, num, avg); // count values above average
    double maxVal = findMaximum(values, num);           // find maximum value

    //outpute statements after computations 
    cout << fixed << setprecision(2);
    cout << "\nThe number of values above the average is " << numAbove << "." << endl; // display number of values above average
    cout << "The maxim value was " << maxVal << "." << endl;                       // display maximum value
    cout << "The maximum occurred at the following positions: ";                     // display positions of maximum value
    printMaxPositions(values, num, maxVal);                                          // print positions for maximum value
    cout << endl;

    return 0;
}

// Function implementations
/******************************************************************
 * * getInputCount  -- prompts the user to enter the number of inputs in the array
 *
 * Parameters:none
 *
 * Modifies: cin -- reads values from the user
 *
 * Returns: int n -- number of inputs between 1 and 100
 *******************************************************************/
int getInputCount()
{
    int n;
    do
    {
        cout << "Please state the number of inputs: ";
        cin >> n;

        if (n < 1 || n > 100)
        {
            cout << "Invalid input: number must be between 1 and 100." << endl;
        }
    } while (n < 1 || n > 100);
    return n;
}

/******************************************************************
 *getValues -- takes in the values from the user to fill the array
 *
 * Parameters: double arr[] -- array to store real numbers
 *           int n -- number of elements in the array
 *
 * Modifies: cin -- reads values from the user
 *
 * Returns: nothing as its void
 *******************************************************************/
void getValues(double arr[], int n)
{
    cout <<"\nPlease input all " << n << " values separated by whitespace:  ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

/******************************************************************
 *computeAverage -- computes and returns the average of all array values
 *
 * Parameters: double arr[] -- array of real numbers
 *            int n -- number of elements in the array
 *
 * Modifies: none
 *
 * Returns: average -- average value of the array
 *******************************************************************/
double computeAverage(double arr[], int n)
{
    double sum = 0; // variable intialization
    // for loop to compute sum of array elements
    for (int i = 0; i < n; i++)
    {
        sum += arr[i]; // adding each element to sum until the loop reacher n
    }
    // using the formuna to compute average
    //  the function returns the average value
    return sum / n;
}

/******************************************************************
 *countAboveAverage -- counts how many values are above the average
 * Parameters:double arr[] -- array of real numbers
 *              int n -- number of elements in the array
 *              double avg -- average value of the array
 *
 * Modifies: none
 *
 *
 * Returns: int count -- number of values above the average
 *******************************************************************/
int countAboveAverage(double arr[], int n, double avg)
{
    int count = 0; // loop couter variable intialized to zero
    // for loop to count values above average
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            count++; // increment count if element is above average
        }
    }
    return count;
}

/******************************************************************
 * findMaximum -- finds the maximum value in the array
 *
 * Parameters: double arr[] -- array of  numbers from which to find the maximum
 *             int n -- number of elements in the array
 *
 * Modifies: none
 *
 * Returns: double maxVal -- maximum value in the array
 *******************************************************************/
double findMaximum(double arr[], int n)
{
    double maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
/******************************************************************
 * printMaxPositions -- prints the indices where the maximum value occurs
 *
 * Parameters: double arr[] -- array of real numbers
 *             int n -- number of elements in the array
 *             double maxValue -- maximum value in the array
 *
 * Modifies: cout -- displays the indices of maximum values
 *
 * Returns: nothing
 *******************************************************************/
void printMaxPositions(double arr[], int n, double maxValue)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == maxValue)
        {
            cout << i << " ";
        }
    }
}