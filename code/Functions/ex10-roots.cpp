#include <iostream>
#include <cmath>
using namespace std;

void  calcRoot (double a, double b, double c, double &root1, double &root2);

int main () {

    double a, b, c, root1, root2;

    cout << "Enter the co-efficients of the quadratic equation: ";
    cin >> a >> b >> c;

    calcRoot (a, b, c, root1, root2);

    cout << "The roots of the equstion are: " << root1 << " and " << root2 << endl;

    return 0;
}

void  calcRoot (double a, double b, double c, double &root1, double &root2) {
    root1 = (-b + sqrt(b*b - 4*a*c)) / (2*a);
    root2 = (-b - sqrt(b*b - 4*a*c)) / (2*a);
}
