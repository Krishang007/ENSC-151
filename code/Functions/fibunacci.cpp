//fibunacci series
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
 int fibunacci (int n);

 int main(){
    int num ;

    cout<<"Fibonacci Series using recursion"<<endl;


    cout<<"Enter the number of terms: ";
    cin>>num;

    cout<<"Fibonacci Series: "<<endl;
    //using reccursion
    for (int i=1;i<num;i++){
       cout<< fibunacci(i);
        }
        

    return 0;
}

int fibunacci (int n) {
    if (n <= 1)
        return n;
    return fibunacci(n - 1) + fibunacci(n - 2);
}