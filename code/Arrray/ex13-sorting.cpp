#include <iostream>
using namespace std;

const int SIZE = 100;

void getData (double dada[], int num);
void bubbleSort (double dada[], int num);
void outData (double dada[], double sortedDada[], int num);

int main() {

    double data[SIZE], sortedData[SIZE];
    int num;

    cout << "\nEnter the size: ";
    cin >> num;

    getData (data, num);

    for (int i=0; i<num; i++){
        sortedData[i] = data[i]; //
    }

    bubbleSort (sortedData, num);

    outData (data, sortedData, num);

    return 0;
}

void getData (double data[], int num) {
    cout << "\nEnter the numbers: ";
    for (int i=0; i<num; i++) {
        cin >> data[i];
    }
}

void bubbleSort (double sortedData[], int num) {

    double temp;
    for (int i=0; i<num-1; i++){
        for (int j=0; j<num-1-i; j++){
            if (sortedData[j] > sortedData[j+1]) {
                temp = sortedData[j];
                sortedData[j] = sortedData[j+1];
                sortedData[j+1] = temp;
            }
        }
    }
}


void outData (double data[], double sortedData[], int num){
    cout << "\nThe original sequence are:\t";
    for (int i=0; i<num; i++) {
        cout << data[i] <<"\t";
    }
    cout << "\nThe sorted number are:\t";
    for (int i=0; i<num; i++) {
        cout << sortedData[i] <<"\t";
    }
}
