#include <iostream>
#include <cmath>
//#include <test.h>

using namespace std;

int mul (int, int);

int main (){
    int a, b;

//    cout << "Hello World!\n";
//    cout << "Enter two numbers:";
    
//    cin >> a >> b;

    cout << "The product is: " << mul (a, b) << endl;

    return 0;
}

int mul (int a, int b){

    return log2(a * b);
}
