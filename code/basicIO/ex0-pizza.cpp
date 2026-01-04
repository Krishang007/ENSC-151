#include <iostream>
#include <iomanip>
using namespace std;

int main () {

    int num;
    const double UNIT_PRICE = 9.99;
    double taxRate = 0.06;
    double total, subTotal;

    cout << "Please enter the number of pizza: ";
    cin >> num;

    subTotal = num * UNIT_PRICE;
    total = subTotal * (1 + taxRate);

    cout << "Subtotal is: " << setprecision (4) << subTotal << endl;
    cout << "Total is: " << setprecision (4) << total << endl;

    return 0;
}