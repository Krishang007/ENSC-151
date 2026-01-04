#include <iostream>
using namespace std;

int main(){
    int a=10;
    int d=10; 
    //post increment operator: value is assigned then the value is incremented
    //a++ is  a=a+1;
    int b =a++;
    int c=++d; //pre increment operator: value is incremented then the value is assigned
    // prints the predecessor  value of a when a++ is used
    // prints the successor value of a when ++a is used
    cout<<a<<endl; //11
    cout<<b<<endl; //10
    cout<<d<<endl; //11
    cout<<c<<endl; //11
    return 0;

}