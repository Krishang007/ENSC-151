#include <iostream>
using namespace std;
// pass by value 
int main()
{
    int a;
    cout << "Enter a:";
    cin >> a;
    int b;
    cout << "Enter b:";
    cin >> b;
    swap(a,b);
     cout << "x:" << a;
    cout << "\ny:" << b << "\n";
    return 0;
}
// pass by value
void swap(int x, int y)
{

    x = x + y;

    y = x - y;
    x = x - y;

   
}