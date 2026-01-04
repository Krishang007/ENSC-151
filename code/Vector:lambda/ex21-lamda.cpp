 #include <iostream>
#include <vector>
#include <algorithm>   // sort, for_each, count_if, transform
#include <string>

using namespace std;

int main() {
    // 1. Simple lambda
    auto greet = []() {
        cout << "=== Lambda Demo ===" << endl;
    };
    greet();

    // 2. Vector of integers
    vector<int> nums = {3, -7, 2, 9, -4, 10};

    // 3. Use for_each + lambda to print original numbers
    cout << "Original: ";
    for_each(nums.begin(), nums.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;

    // 4. Transform numbers to their absolute values using lambda
    vector<int> absNums(nums.size());
    transform(nums.begin(), nums.end(), absNums.begin(),
              [](int x) {
                  return (x < 0) ? -x : x;
              });

    cout << "Absolute: ";
    for (int x : absNums) {
        cout << x << " ";
    }
    cout << endl;

    // 5. Count how many numbers are even using lambda
    int evenCount = count_if(nums.begin(), nums.end(),
                             [](int x) {
                                 return x % 2 == 0;
                             });

    cout << "Even count: " << evenCount << endl;

    // 6. Sum numbers using capture by reference
    int sum = 0;
    for_each(nums.begin(), nums.end(),
             [&sum](int x) {
                 sum += x;
             });

    cout << "Sum of nums: " << sum << endl;

    // 7. Using a captured threshold to filter values
    int threshold = 3;
    vector<int> filtered;
    copy_if(nums.begin(), nums.end(), back_inserter(filtered),
            [threshold](int x) {
                return x > threshold;
            });

    cout << "Filtered (x > " << threshold << "): ";
    for (int x : filtered) {
        cout << x << " ";
    }
    cout << endl;

    // 8. Sorting a vector of pairs with a lambda
    vector<pair<string, int>> students = {
        {"Alice", 85},
        {"Bob", 92},
        {"Carol", 78},
        {"David", 92}
    };

    sort(students.begin(), students.end(),
         [](const pair<string,int>& a, const pair<string,int>& b) {
             if (a.second != b.second)
                 return a.second > b.second;   // higher score first
             return a.first < b.first;         // if tie, name ascending
         });

    cout << "Students sorted (score desc, name asc):\n";
    for (const auto& s : students) {
        cout << "  " << s.first << " - " << s.second << endl;
    }

    // 9. Explicit iterator usage with lambda
    cout << "Using iterators to print nums squared: ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        auto square = [](int x) {
            return x * x;
        };
        cout << square(*it) << " ";
    }
    cout << endl;

    return 0;
}
