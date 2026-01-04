#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main () {

    int i, j, k;
    int level, num;

    cout << "Enter how many levels to display: ";
    cin >> level;
    num = 0;

    for (i=0; i<level; i++) {
        for (j=0; j<=i; j++) {
            cout << num++ << "\t";
            //num ++;
        }
        cout << endl;
    }

    for (i=level-2; i>=0; i--) {
        for (j=0; j<=i; j++) {
            cout << num << "\t";
            num ++;
        }
        cout << endl;
    }

    cout << endl;
    num = 0;

    for (i=0; i<level; i++) {
        for (j=1; j<level-i; j++) {
            cout << "\t";
        }
        for (j=0; j<=i; j++) {
            cout << num++ << "\t";
        }
        cout << endl;
    }

    return 0;
}

