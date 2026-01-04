#include <iostream>
using namespace std;

/*
 * PATTERN: Row-wise vs Column-wise Numbers
 *
 * Row-wise (print j):        Column-wise (print i):
 * 1234                       1111
 * 1234                       2222
 * 1234                       3333
 * 1234                       4444
 *
 * KEY CONCEPT:
 * - j changes with each column → row-wise pattern
 * - i stays same in each row → column-wise pattern
 */

int main() {
  int n = 4;

  // ROW-WISE: Print j
  cout << "Row-wise Numbers (print j):\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << j; // j changes: 1,2,3,4 in each row
    }
    cout << "\n";
  }

  cout << "\nColumn-wise Numbers (print i):\n";
  // COLUMN-WISE: Print i
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << i; // i stays same: all 1s, then all 2s, etc.
    }
    cout << "\n";
  }

  return 0;
}

/*
 * ROW-WISE TRACE (print j):
 * i=1: j=1,2,3,4 → prints 1234
 * i=2: j=1,2,3,4 → prints 1234
 * i=3: j=1,2,3,4 → prints 1234
 * i=4: j=1,2,3,4 → prints 1234
 *
 * COLUMN-WISE TRACE (print i):
 * i=1: j=1,2,3,4 → prints 1111 (i is always 1)
 * i=2: j=1,2,3,4 → prints 2222 (i is always 2)
 * i=3: j=1,2,3,4 → prints 3333 (i is always 3)
 * i=4: j=1,2,3,4 → prints 4444 (i is always 4)
 *
 * REMEMBER: What changes determines the pattern direction!
 */
