/*  the objective of this program is to compute the area and perimeter when  lenght and width 
is inputed by the user 
*/
// preproceer directive 
#include<iostream>

using namespace std;
int main ()
{
    // declare variables for the program 
    double length ;
    double width;
    double area ;
    double perimeter;

    cout<<"Program to computer and output the perimeter and  "
        << "area of reactangle"<<endl;

    length =6.0;

    width = 4.0;
    perimeter= 2*(length+width);

    area=length*width;

    cout<<"Length="<<length<<endl;;
    cout<<"Width="<<width <<endl;
    cout<<"Perimeter="<<perimeter<<endl;
    cout<<"Area="<<area<<endl;

    return 0;


}