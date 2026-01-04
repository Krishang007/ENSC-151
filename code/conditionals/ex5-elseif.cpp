#include <iostream>
using namespace std;

int main() {
  
  int x; // number input by user
  cout << "Please enter an integer:";
  cin >> x;
  
  if (cin) {
    cout << x;
    if (x == 1 || x == 10 || x == 100 || x == 1000) {
      cout << " is either 1, 10, 100 or 1000" << endl;
    } else if ((1 <= x && x <= 10) || (90 <= x && x <= 99)) {
      cout << " is either between 1 and 10 or 90 and 99" << endl;
    } else {
      cout << " doesn't fit any category tested." << endl;
    }
  } else {
    cout << "Input failed." << endl;
  }
  
  return 0;
}

