
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {

  double x; // First number input by user
  double y; // Second number input by user

  cout << "Please enter two floating-point numbers: ";
  cin >> x >> y;
  cout << "\nTable of library functions : " << endl;
  cout << "Function\tValue" << endl;
  cout << "--------\t------" << endl;

  cout << "abs(" << int(x) << ") =\t" << abs(int(x)) << endl;
  cout << "abs(" << int(y) << ") =\t" << abs(int(y)) << endl;
  cout << "ceil(" << x << ") =\t" << ceil(x) << endl;
  cout << "ceil(" << y << ") =\t" << ceil(y) << endl;
  cout << "cos(" << x << ") =\t" << cos(x) << endl;
  cout << "cos(" << y << ") =\t" << cos(y) << endl;
  cout << "exp(" << x << ") =\t" << exp(x) << endl;
  cout << "exp(" << y << ") =\t" << exp(y) << endl;
  cout << "fabs(" << x << ") =\t" << fabs(x) << endl;
  cout << "fabs(" << y << ") =\t" << fabs(y) << endl;
  cout << "floor(" << x << ") =\t" << floor(x) << endl;
  cout << "floor(" << y << ") =\t" << floor(y) << endl;
  cout << "log(" << x << ") =\t" << log(x) << endl;
  cout << "log(" << y << ") =\t" << log(y) << endl;
  cout << "log10(" << x << ") =\t" << log10(x) << endl;
  cout << "log10(" << y << ") =\t" << log10(y) << endl;
  cout << "pow(" << x << ", " << y << ") =\t" << pow(x, y) << endl;
  cout << "pow(" << y << ", " << x << ") =\t" << pow(y, x) << endl;
  cout << "sin(" << x << ") =\t" << sin(x) << endl;
  cout << "sin(" << y << ") =\t" << sin(y) << endl;
  cout << "sqrt(" << x << ") =\t" << sqrt(x) << endl;
  cout << "sqrt(" << y << ") =\t" << sqrt(y) << endl;
  cout << "tan(" << x << ") =\t" << tan(x) << endl;
  cout << "tan(" << y << ") =\t" << tan(y) << endl;

  return 0;
}

