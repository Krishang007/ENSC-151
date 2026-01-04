/*  this program focusses on a local pizza store
*   by taking the input of how many number of pizza  the customer
*   wants  and computing their subtotal and total after taxes
*/
// preprocces directive and libraries used : input/output and precission
#include <iostream>
#include <iomanip>

using namespace std;

void welcome();//function declaation
double  calcSubTotal(int num,double unitPrice);
int main()
{
    // variable decleration for the program
    // price  of large  pizza
    const double unit_price = 9.99;
    // tax rate 6%
    const double tax = 0.06;
    // number of pizza the user buys
    int num;

    // Input and output functions of  the program
    welcome();//function call
    cout << "Please enter the number of pizzas :" << endl;
    cin >> num;

   
    // Subtotal before taxes
    //float subtotal = num * unit_price;
    double subTotal = calcSubTotal(num,unit_price);
    // total ammount need to be paid by the customer after 6% of tax
    float total = subTotal *(1+tax);

    // allows floating point of the output to be rounded to 2 decimal places
    cout << fixed << setprecision(2);
    cout << "Subtotal: $" << subTotal; // endl;
    cout << "\nTotal is: $" << total << "\n";

    // exit
    return 0;
}
//function implementation
void welcome(){
   cout<<"Welcome to Pizza price calculator!\n";
   cout<<"user will enter the number  of pizzas\n";
   cout<<"Program wil calculate the cost of the pixzaa \n";
}
double calcSubTotal(int num,double unit_Price){
        double subtotal;
         subtotal = num * unit_Price;
     // return num*unit_Price;
}