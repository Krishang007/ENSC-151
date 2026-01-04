#include <iostream>
using namespace std;

/*
 * PATTERN: Right Triangle with Stars
 *
 * Output (n=5):
 * *
 * **
 * ***
 * ****
 * *****
 *
 * CONCEPT: Increasing pattern
 * Row 1: 1 star
 * Row 2: 2 stars
 * Row i: i stars
 *
 * KEY: Inner loop limit changes based on row number (i)
 */

int main() {
  int n = 5;

  cout << "Right Triangle (n=" << n << "):\n";

  for (int i = 1; i <= n; i++) {   // Outer: row number (1 to 5)
    for (int j = 1; j <= i; j++) { // Inner: print i stars in row i
      cout << "*";
    }
    cout << "\n";
  }

  return 0;
}

/*
 * TRACE TABLE:
 * i=1: j <= 1, so j runs 1       → prints "*"
 * i=2: j <= 2, so j runs 1,2     → prints "**"
 * i=3: j <= 3, so j runs 1,2,3   → prints "***"
 * i=4: j <= 4, so j runs 1,2,3,4 → prints "****"
 * i=5: j <= 5, so j runs 1,2,3,4,5 → prints "*****"
 *
 * NOTICE: The inner loop limit (i) grows with each row!
 */
