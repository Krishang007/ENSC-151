#include <iostream>
using namespace std;

/*
 * PATTERN: Isosceles (Centered) Triangle
 *
 * Output (n=5):
 *     *       (4 spaces, 1 star)
 *    ***      (3 spaces, 3 stars)
 *   *****     (2 spaces, 5 stars)
 *  *******    (1 space,  7 stars)
 * *********   (0 spaces, 9 stars)
 *
 * CONCEPT: Spaces + Stars based on position
 * Total width: 2*n - 1 (always odd for symmetry)
 *
 * For row i:
 * - Stars appear from position (n - i + 1) to (n + i - 1)
 * - Everything else is a space
 */

int main() {
  int n = 5;

  cout << "Isosceles Triangle (n=" << n << "):\n";

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 2 * n - 1; j++) {
      // Check if current position should be a star
      if (j >= n - (i - 1) && j <= n + (i - 1)) {
        cout << "*";
      } else {
        cout << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}

/*
 * DETAILED TRACE (n=5):
 *
 * Row 1 (i=1):
 *   Star range: 5-(1-1)=5 to 5+(1-1)=5 → position 5 only
 *   j=1-4: space, j=5: star, j=6-9: space
 *   Output: "    *    "
 *
 * Row 2 (i=2):
 *   Star range: 5-(2-1)=4 to 5+(2-1)=6 → positions 4,5,6
 *   j=1-3: space, j=4-6: stars, j=7-9: space
 *   Output: "   ***   "
 *
 * Row 3 (i=3):
 *   Star range: 5-2=3 to 5+2=7 → positions 3,4,5,6,7
 *   j=1-2: space, j=3-7: stars, j=8-9: space
 *   Output: "  *****  "
 *
 * Row 4 (i=4):
 *   Star range: 5-3=2 to 5+3=8 → positions 2-8
 *   Output: " ******* "
 *
 * Row 5 (i=5):
 *   Star range: 5-4=1 to 5+4=9 → positions 1-9
 *   Output: "*********"
 *
 * FORMULA BREAKDOWN:
 * - Center position: n
 * - Offset from center: (i-1)
 * - Left boundary: n - (i-1)
 * - Right boundary: n + (i-1)
 */
