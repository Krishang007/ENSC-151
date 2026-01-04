#include <iostream>
#include <iomanip>
using namespace std;

void welcome ();    // function declaration
double calcSubTotal (int num, double unitPrice);

int main () {

    int num;    // user input of # of pizza
    const double UNIT_PRICE = 9.99;
    const double tax = 0.06;
    double subTotal, total;

    welcome ();     // function call
    
    cout << "Please enter the number of pizza: ";
    cin >> num;

//    subTotal = num * UNIT_PRICE;

    subTotal = calcSubTotal (num, UNIT_PRICE);
    total = subTotal * (1 + tax);

    cout << "Sub-total is: " << setprecision(3) << subTotal; // <<endl;
    cout << "\nTotal is: " << setprecision (4) << total << endl;

    return 0;
}

// Function Implementation
void welcome () {
    cout << "Welcome to use the Pizza calculator!\n";
    cout << "User will enter the number pizza\n";
    cout << "Program calculate the value with Tax.\n";
}

double calcSubTotal (int num, double unitPrice) {
//    return num * unitPrice;
    double subTotal;
    subTotal = num * unitPrice;
    return subTotal;
}
