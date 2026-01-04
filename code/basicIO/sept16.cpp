/* this program focusses on a local pizza store
    by taking the input of how many number of pizza  the customer
    wants  and computing their subtotal and total after taxes
*/
// preprocces directive and libraries used   
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // variable decleration for the program
    // price  of large  pizza
    const float price_largepizza = 9.99;
    // number of pizza
    int num;

    // Input and output functions of  the program
    cout << "Input the number of pizzas you want to buy:" << endl;
    cin >> num;
    // Subtotal before taxes
    float subtotal = num * price_largepizza;
    // allows floating point of the output to be rounded to 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subtotal << "\n";
    // total ammount need to be paid by the customer after 6% of tax
    float total = subtotal * 1.06;
    cout << "Total due: $" << total << "\n";

    // exit
    return 0;
}