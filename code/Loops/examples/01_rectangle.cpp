#include <iostream>
using namespace std;

/*
 * PATTERN: Rectangle (3x5)
 *
 * Output:
 * * * * * *
 * * * * * *
 * * * * * *
 *
 * CONCEPT: Fixed rows, fixed columns
 * Outer loop: controls rows (3 times)
 * Inner loop: controls columns (5 times per row)
 */

int main() {
  int rows = 3, cols = 5;

  cout << "Rectangle Pattern (" << rows << "x" << cols <<  "):\n";

  for (int i = 1; i <= rows; i++) {   // Outer: 3 rows
    for (int j = 1; j <= cols; j++) { // Inner: 5 stars per row
      cout << "* ";
    }
    cout << "\n"; // New line after each row
  }

  return 0;
}

/*
 * TRACE TABLE:
 * i=1: j runs 1,2,3,4,5 → prints "* * * * * " then newline
 * i=2: j runs 1,2,3,4,5 → prints "* * * * * " then newline
 * i=3: j runs 1,2,3,4,5 → prints "* * * * * " then newline
 */
