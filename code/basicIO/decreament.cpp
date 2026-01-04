#include <iostream>
using namespace std;

int main(){
    int a = 10;
     int b = a--;  // post-decrement: value is assigned then the value is decremented
   // int b = --a;      // pre-decrement: value is decremented then the value is assigned
    cout << a << endl;//9 when a-- is used 
    cout << b << endl;// 9 when --a is used and 10 when a-- is used
    return 0;
}