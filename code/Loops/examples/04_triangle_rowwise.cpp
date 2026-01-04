#include <iostream>
using namespace std;

/*
 * PATTERN: Right Triangle - Row-wise Numbers
 *
 * Output (n=5):
 * 1
 * 12
 * 123
 * 1234
 * 12345
 *
 * CONCEPT: Combining triangle shape with row-wise numbers
 * - Triangle shape: j <= i (increasing rows)
 * - Row-wise: print j
 */

int main() {
  int n = 5;

  cout << "Right Triangle - Row-wise Numbers:\n";

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) { // Triangle: j goes from 1 to i
      cout << j;                   // Row-wise: print j
    }
    cout << "\n";
  }

  return 0;
}

/*
 * TRACE:
 * i=1: j runs 1       → prints "1"
 * i=2: j runs 1,2     → prints "12"
 * i=3: j runs 1,2,3   → prints "123"
 * i=4: j runs 1,2,3,4 → prints "1234"
 * i=5: j runs 1,2,3,4,5 → prints "12345"
 */
