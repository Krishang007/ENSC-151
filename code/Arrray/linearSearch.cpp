#include <iostream>

using namespace std;

// function declaration
int linearSearch(int arr[], int sz, int target);

// function implementation (pass-by-value)
int linearSearch(int arr[], int sz, int target)
{
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1; // not found
}
int main()
{
    // declaring variable and intializing them
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    int sz = 7;
    int target = 0;
    cout << "Enter target:";
    cin >> target;
    int position = linearSearch(arr, sz, target);
    cout << "\nposition:" << position;
    cout << "target:" << arr[position] << endl;
    return 0;
}