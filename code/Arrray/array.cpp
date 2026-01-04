#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter number of students in the class: ";
  cin >> n;

  int marks[100];         // declare array after reading n
  int sum = 0;            // summation variable
  int i;                  // loop counter variable
  double variance = 0.00; // output variable
  double standardDeviation = 0.00;

  // Input marks
  for (i = 0; i < n; i++) {
    cout << "Enter marks for student " << i + 1 << ": ";
    // store marks in the array
    cin >> marks[i];
  }

  // Calculate sum
  for (i = 0; i < n; i++) {
    sum = sum + marks[i]; // iteration for calculating sum
  }
  double avg = static_cast<double>(sum) / n;
  cout << "Average marks: " << avg << endl;

  // calculate standard deviation  and variance
  double numerator = 0.00;
  for (i = 0; i < n; i++) {
    numerator += pow((marks[i] - avg), 2);
  }

  // after summation and iteration
  variance = numerator / (n - 1);
  standardDeviation = sqrt(variance);

  cout << "Variance: " << variance << endl;
  cout << "Standard deviation: " << standardDeviation << endl;

  // Count students above and below average
  int above = 0, below = 0;
  for (int i = 0; i < n; i++) {
    if (marks[i] > avg)
      above++;
    else if (marks[i] < avg)
      below++;
  }

  cout << "Students above average: " << above << endl;
  cout << "Students below average: " << below << endl;

  return 0;
}
