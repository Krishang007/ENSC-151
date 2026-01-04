#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Create an empty vector
    vector<int> v;

    cout << "The initial capacity is: " << v.capacity() << "\n";

    // ----------------------------------------
    // push_back()
    // ----------------------------------------
    cout << "Adding elements using push_back...\n";
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // ----------------------------------------
    // size(), capacity(), empty()
    // ----------------------------------------
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Is empty? " << (v.empty() ? "Yes" : "No") << endl;

    // ----------------------------------------
    // Accessing elements: [], at(), front(), back()
    // ----------------------------------------
    cout << "v[1]: " << v[1] << endl;          // no bounds check
    cout << "v.at(1): " << v.at(1) << endl;    // bounds-checked
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    // ----------------------------------------
    // Iterating using iterators
    // ----------------------------------------
    cout << "Elements using iterators: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // ----------------------------------------
    // Range-based for loop
    // ----------------------------------------
    cout << "Elements using range-based for: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // ----------------------------------------
    // insert()
    // ----------------------------------------
    cout << "Inserting 15 at position 1...\n";
    v.insert(v.begin() + 1, 15); // insert at index 1

    cout << "Adter inserting 15, elements are: \n";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;


    // ----------------------------------------
    // erase()
    // ----------------------------------------
    cout << "Erasing element at index 2...\n";
    v.erase(v.begin() + 2); // erase element at index 2

    cout << "Adter deleting element at index 2, elements are: \n";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // ----------------------------------------
    // pop_back()
    // ----------------------------------------
    cout << "Popping last element...\n";
    v.pop_back();

    cout << "Adter popping last element, elements are: \n";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // ----------------------------------------
    // clear()
    // ----------------------------------------
    cout << "Clearing vector...\n";
    v.clear();
    cout << "Size after clear: " << v.size() << endl;
    cout << "Capacity after clear: " << v.capacity() << endl;

    return 0;
}
