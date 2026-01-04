// quickSort
#include <iostream>
#include <vector>
using namespace std;

// Function declarations
int partitionVec(vector<double> &arr, int start, int end);
void quickSort(vector<double> &arr, int start, int end);

int main()
{
    vector<double> arr = {12, 31, 36, 8.32, 17};


    //print unsorted array
    cout << "unserted array: ";
    for (double val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    // CALL QUICK SORT
    quickSort(arr, 0, arr.size() - 1);
    // PRINT SORTED OUTPUT
    for (double val : arr)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// QUICK SORT
void quickSort(vector<double> &arr, int start, int end)
{
    if (start < end)
    {
        int pivIdx = partitionVec(arr, start, end);

        quickSort(arr, start, pivIdx - 1); // left side
        quickSort(arr, pivIdx + 1, end);   // right side
    }
}

// PARTITION FUNCTION
int partitionVec(vector<double> &arr, int start, int end)
{
    double pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]); // place pivot in correct position
    return i + 1;
}