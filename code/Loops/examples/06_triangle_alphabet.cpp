#include <iostream>
using namespace std;

/*
 * PATTERN: Right Triangle - Alphabets
 *
 * Output (n=5):
 * A
 * AB
 * ABC
 * ABCD
 * ABCDE
 *
 * CONCEPT: Using ASCII values to convert numbers to letters
 * - 'A' = 65 in ASCII
 * - j + 64: when j=1 → 65='A', j=2 → 66='B', etc.
 */

int main() {
  int n = 5;

  cout << "Right Triangle - Alphabets:\n";

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << static_cast<char>(j + 64); // Convert number to letter
    }
    cout << "\n";
  }

  return 0;
}

/*
 * TRACE:
 * i=1: j=1       → j+64=65 → 'A'
 * i=2: j=1,2     → 65,66 → 'AB'
 * i=3: j=1,2,3   → 65,66,67 → 'ABC'
 * i=4: j=1,2,3,4 → 65,66,67,68 → 'ABCD'
 * i=5: j=1,2,3,4,5 → 65,66,67,68,69 → 'ABCDE'
 *
 * ASCII REFERENCE:
 * A=65, B=66, C=67, D=68, E=69...
 * So: j + 64 gives us the letter at position j
 */
