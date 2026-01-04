#include <iostream>
using namespace std;

/*
 * PATTERN: Right Triangle - Column-wise Numbers
 *
 * Output (n=5):
 * 1
 * 22
 * 333
 * 4444
 * 55555
 *
 * CONCEPT: Combining triangle shape with column-wise numbers
 * - Triangle shape: j <= i (increasing rows)
 * - Column-wise: print i
 */

int main() {
  int n = 5;

  cout << "Right Triangle - Column-wise Numbers:\n";

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) { // Triangle: j goes from 1 to i
      cout << i;                   // Column-wise: print i
    }
    cout << "\n";
  }

  return 0;
}

/*
 * TRACE:
 * i=1: j runs 1       → prints "1" (i is 1)
 * i=2: j runs 1,2     → prints "22" (i is 2, repeated)
 * i=3: j runs 1,2,3   → prints "333" (i is 3, repeated)
 * i=4: j runs 1,2,3,4 → prints "4444" (i is 4, repeated)
 * i=5: j runs 1,2,3,4,5 → prints "55555" (i is 5, repeated)
 */
