//marks and average 
#include <iostream>
using namespace std;

int main() {
    int n;
    int sum = 0;
    
    // Read how many marks the user will input
    cout << "Enter number of students in the class: ";
    cin >> n;
    
    int marks[100];  // Fixed size array (or use dynamic allocation)
    
    // Input marks
    for(int i = 0; i < n; i++) {  // Fixed: i < n
        cout << "Enter marks for student " << i+1 << ": ";
        cin >> marks[i];
    }
    
    // Calculate sum
    for(int i = 0; i < n; i++) {  // Fixed: i < n
        sum += marks[i];
    }
    
    // Calculate average (using double for precision)
    double avg = static_cast<double>(sum) / n;
    
    cout << "Average marks: " << avg << endl;
    
    return 0;
}