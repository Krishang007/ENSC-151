/******************************************************************
 * selectiomSort.cpp  -- sorts an array of numbers using the selection sort algorithm
 * Description:
 *    This program implements the selection sort algorithm to sort an array of numbers
 *    in ascending order. The program prompts the user to enter the size of the array
 *    and the elements of the array. It then sorts the array using the selection sort
 *    algorithm and displays both the original and sorted arrays.
 * Input:
 *    the numbeer of elements in the array and the elements themselves
 *    the  content of the array to be sorted
 * Output:
 * 
 * 
 * 
 * 
 * 
 * 
 *    the original array and the sorted array
 * Author: Krishang Sarkar
 *******************************************************************/
// preprocessor directives and librabies used in the program
#include <iostream>
#include <algorithm>
using namespace std;

// function definition
void getData(double arr[], int n);
void selectionSort(double arrSorted[], int n);
void outData(double arr[], double arrSorted[], int n);

//  define the max size of array as arrays are not dynamic in C++
const int SIZE = 100;
/******************************************************************
 * main -- controls overall program flow
 * Parameters: none
 * Modifies: cout, cin -- for user interaction
 * Returns: 0 upon successful completion
 *******************************************************************/
int main()
{
    int n;
    double arr[SIZE];
    double arrSorted[SIZE];

    // prompt user to enter size and numbers
    cout << "\nEnter the size: ";
    cin >> n;

    getData(arr, n);

    // copy array
    for (int i = 0; i < n; i++)
    {
        arrSorted[i] = arr[i];
    }

    // call selection sort
    selectionSort(arrSorted, n);

    // correct function call
    outData(arr, arrSorted, n);

    return 0;
}

// function implementation
/******************************************************************
 * * getData  -- prompts the user to enter the number of inputs in the array
 * Parameters:arr[] -- array to store numbers
 *            int n -- number of elements in the array
 * Modifies: cin -- reads values from the user
 * Returns: nothing as its void
 *******************************************************************/
void getData(double arr[], int n)
{
    cout << "\nEnter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
/******************************************************************
 * selectionSort  -- sorts the array using selection sort algorithm
 * Parameters:double arr[] -- array to store numbers
 *            int n -- number of elements in the array
 * Modifies:  arrsorted -- sorts the array in ascending order
 * Returns:   nothing as its void
 *******************************************************************/
void selectionSort(double arrSorted[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) // number of comparisons
        {
            if (arrSorted[i] > arrSorted[j])
            {
                swap(arrSorted[i], arrSorted[j]);
            }
        }
    }
}
/******************************************************************
 * outData  -- displays the original and sorted arrays
 * Parameters:arr[] -- array to store numbers
 *                 arrsorted[] -- sorted array
 *                 int n -- number of elements in the array
 * Modifies: cout -- displays the original and sorted arrays
 * Returns: nothing as its void
 *******************************************************************/
void outData(double arr[], double arrSorted[], int n)
{
    cout << "\nThe original sequence are:\t";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << "\nThe sorted number are:\t";
    for (int i = 0; i < n; i++)
    {
        cout << arrSorted[i] << "\t";
    }
}