#include<iostream>
#include<cmath>
using namespace std;

int main(){
    //3d Vectors A and B with magnitudes 
    int vectorA[3];
    int vectorB[3];
    int dP = 0;
    int i;
     // Input Magnitudes
    for (i = 0; i < 3; i++)
    {
        cout << "Enter Magnitudes for Vector A " << i + 1 << ": ";
        // store Magnitudes in the array
        cin >> vectorA[i];
    }
    for (i = 0; i < 3; i++)
    {
        cout << "Enter Magnitudes for Vector B " << i + 1 << ": ";
        // store Magnitudes in the array
        cin >> vectorB[i];
    }

    //calculatte dot product
    for(i=0;i<3;i++){
    dP+=vectorA[i]*vectorB[i];

    }
    cout<<"Dot Product of the two vectors :"<<dP<<endl;

}

