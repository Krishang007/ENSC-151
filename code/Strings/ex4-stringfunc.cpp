#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Engineering";
    string str2 = "Science";

    // 1. Length and size
    cout << "Length of str1: " << str1.length() << endl;
    cout << "Size of str2: " << str2.size() << endl;

    // 2. Concatenation
    string combined = str1 + " " + str2;
    cout << "Concatenated string: " << combined << endl;

    // 3. Append
    combined.append("!!!");
    cout << "After append: " << combined << endl;

    // 4. Access character
    cout << "First character of str1: " << str1[0] << endl;
    cout << "Last character of str2: " << str2.at(str2.size() - 1) << endl;

    // 5. Compare strings
    if (str1.compare(str2) == 0)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;

    // 6. Substring
    cout << "Substring of combined (0,11): " << combined.substr(0, 11) << endl;

    // 7. Insert
    str1.insert(11, " School");
    cout << "After insert: " << str1 << endl;

    // 8. Erase
    str1.erase(11, 7);
    cout << "After erase: " << str1 << endl;

    // 9. Replace
    combined.replace(12, 7, "University");
    cout << "After replace: " << combined << endl;

    // 10. Find
    size_t pos = combined.find("University");
    if (pos != string::npos)
        cout << "\"University\" found at position: " << pos << endl;

    // 11. Reverse iteration
    cout << "Reversed combined: ";
    for (int i = combined.length() - 1; i >= 0; i--) {
        cout << combined[i];
    }
    cout << endl;

    // 12. Clear
    str2.clear();
    cout << "After clear, str2 is empty: " << boolalpha << str2.empty() << endl;

    return 0;
}
