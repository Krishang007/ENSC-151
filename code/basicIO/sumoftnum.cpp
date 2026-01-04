//the objective of this program is to find the sum of two numbers
// header and pre processor files used in the program
#include<iostream>
using namespace std;

int main(){
    int a;
    int b;
    cout<<"Enter two  numbers: ";
    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;
    int sum = a + b;

    cout<<"The sum of "<<a<<" and "<<b<<" is "<<sum<<endl;
    return 0;
}