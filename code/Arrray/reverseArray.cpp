#include <iostream>
//#include <algorithm> // for swap
using namespace std;

void reverseArray(int arr[], int sz) {
    int start = 0;
    int end = sz - 1;

    while (start < end) {
        //swap(arr[start], arr[end]);
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

int main() {
    int arr[] = {4, 2, 7, 8, 1, 2, 5};
    int sz = 7;
    cout << "array: ";
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
     cout << endl;

    reverseArray(arr, sz);

    cout << "Reversed array: ";
    for (int i = 0; i < sz; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}