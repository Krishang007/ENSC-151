#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const int SIZE = 100;
const int PI = 3.1415;

//void getData (double dada[], int num);

struct complex {
	string name;
	float realPart, imaginaryPart;
	double dist, angle;
};

void getDataFile (complex dada[], int num);
void coordinateToPolar (complex sortedData[], int num);
void bubbleSort (complex dada[], int num);
void outData (complex dada[], complex sortedDada[], int num);

int main() {
 
    complex data[SIZE], sortedData[SIZE];
    int num;

    cout << "\nEnter the size: ";
    cin >> num;

 //   getData (data, num);
   getDataFile (data, num);

    for (int i=0; i<num; i++){
        sortedData[i] = data[i]; //
    }

    coordinateToPolar (sortedData, num);

    bubbleSort (sortedData, num);

    outData (data, sortedData, num);

    return 0;
}

/*
void getData (double data[], int num) {
    cout << "\nEnter the numbers: ";
    for (int i=0; i<num; i++) {
        cin >> data[i];
    }
}
*/


void getDataFile (complex data[], int num) {

    ifstream inDataFile;
    inDataFile.open("dataComplexIn.txt");

    cout << "\nReading from file ... ";
    for (int i=0; i<num; i++) {
        inDataFile >> data[i].name >> data[i].realPart >> data[i].imaginaryPart;
    }
    cout << "\nReading done ... ";
    inDataFile.close();
}

void coordinateToPolar (complex sortedData[], int num) {
    for (int i=0; i<num; i++) {
        sortedData[i].dist = sqrt (sortedData[i].realPart * sortedData[i].realPart + sortedData[i].imaginaryPart * sortedData[i].imaginaryPart);
        sortedData[i].angle = atan (sortedData[i].imaginaryPart/sortedData[i].realPart) * 180 / PI;
    }
}

void bubbleSort (complex sortedData[], int num) {

    complex temp;
    for (int i=0; i<num-1; i++){
        for (int j=0; j<num-1-i; j++){
            if (sortedData[j].dist > sortedData[j+1].dist) {
                temp = sortedData[j];
                sortedData[j] = sortedData[j+1];
                sortedData[j+1] = temp;
            }
        }
    }
}

void outData (complex data[], complex sortedData[], int num){

    ofstream outDataFile;
    outDataFile.open("dataComplexOut.txt");

    cout << "\nThe original sequence are:\n";
    outDataFile << "\nThe original sequence are:\n";

    for (int i=0; i<num; i++) {
        cout << data[i].name <<"\n(" << data[i].realPart << " , " << data[i].imaginaryPart << ")" << endl << endl;
        outDataFile << data[i].name <<"\n(" << data[i].realPart << " , " << data[i].imaginaryPart << ")" << endl << endl;
    }
    cout << "\nThe sorted number are:\n";
    outDataFile << "\nThe sorted number are:\n";
    for (int i=0; i<num; i++) {
        cout << sortedData[i].name <<"\n" << sortedData[i].dist << "\t" << sortedData[i].angle << "\t(" << sortedData[i].realPart << " , " << sortedData[i].imaginaryPart << ")" << endl << endl;
        outDataFile << sortedData[i].name <<"\n" << sortedData[i].dist << "\t" << sortedData[i].angle << "\t(" << sortedData[i].realPart << " , " << sortedData[i].imaginaryPart << ")" << endl << endl;
    }
    outDataFile.close();
}
