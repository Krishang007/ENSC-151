#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "Enter a:";
    cin >> a;
    int b;
    cout << "Enter b:";
    cin >> b;
}
void swap(int x, int y)
{

    x = x + y;
    y = x - y;
    x = x - y;

    cout << "x:" << x;
    cout << "\ny:" << y << "\n";
}