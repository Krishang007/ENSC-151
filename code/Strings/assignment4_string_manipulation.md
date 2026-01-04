# Assignment 4: String Manipulation
## Exam-Focused Notes (Code & Math Only)

---

## 🎯 Core Problem Pattern

**Input:** String with delimited words (e.g., `"word1*word2*word3*word4"`)  
**Process:** Parse, extract words, reverse order  
**Output:** Reversed string with spaces

---

## 📊 Essential String Functions

### 1. Finding Delimiter Positions
```cpp
int pos1 = s.find('*');              // Find first *
int pos2 = s.find('*', pos1 + 1);    // Find second * (after first)
int pos3 = s.find('*', pos2 + 1);    // Find third * (after second)
```

**Syntax:** `s.find(char, start_position)`
- Returns: **index** of character
- If not found: returns `string::npos`
- Start position optional (default = 0)

---

### 2. Extracting Substrings
```cpp
string word1 = s.substr(0, pos1);                    // From start to first *
string word2 = s.substr(pos1 + 1, pos2 - pos1 - 1);  // Between first and second *
string word3 = s.substr(pos2 + 1, pos3 - pos2 - 1);  // Between second and third *
string word4 = s.substr(pos3 + 1);                   // From third * to end
```

**Syntax:** `s.substr(start, length)`
- `start`: starting index
- `length`: number of characters (optional, default = to end)

**Length Calculation:**
```
"hello*world*foo*bar"
      5     11   15
      
word2 length = pos2 - pos1 - 1
             = 11 - 5 - 1
             = 5 characters ("world")
```

---

### 3. String Concatenation
```cpp
string reversed = word4 + " " + word3 + " " + word2 + " " + word1;
```

**Result:** `"bar foo world hello"`

---

### 4. Reading Full Line Input
```cpp
// ❌ WRONG - stops at first space
string s;
cin >> s;

// ✅ CORRECT - reads entire line
string s;
getline(cin, s);
```

**Key Difference:**
- `cin >>` stops at **whitespace**
- `getline()` reads until **Enter**

---

## 🔧 Complete String Reversal Program

```cpp
#include <iostream>
#include <string>
using namespace std;

void reverseString(string s);

int main() {
    string s;
    cout << "Enter four words separated by *: ";
    getline(cin, s);  // Read entire line
    reverseString(s);
    return 0;
}

void reverseString(string s) {
    // Find positions of delimiters
    int pos1 = s.find('*');
    int pos2 = s.find('*', pos1 + 1);
    int pos3 = s.find('*', pos2 + 1);

    // Extract words
    string word1 = s.substr(0, pos1);
    string word2 = s.substr(pos1 + 1, pos2 - pos1 - 1);
    string word3 = s.substr(pos2 + 1, pos3 - pos2 - 1);
    string word4 = s.substr(pos3 + 1);
    
    // Reverse order with spaces
    string reversed = word4 + " " + word3 + " " + word2 + " " + word1;

    // Output
    cout << "Original: " << s << endl;
    cout << "Reversed: " << reversed << endl;
}
```

---

## ⚠️ Common Mistakes

### 1. Using `cin >>` for Multi-Word Input
```cpp
// ❌ WRONG - only reads until space
cin >> s;  // Input: "hello*world*foo*bar"
           // s gets: "hello*world*foo*bar" (works if no spaces in input)
           // But fails if input has spaces

// ✅ CORRECT
getline(cin, s);  // Reads entire line including spaces
```

### 2. Wrong Substring Length Calculation
```cpp
// ❌ WRONG - forgets to subtract 1
string word2 = s.substr(pos1 + 1, pos2 - pos1);

// ✅ CORRECT - subtract 1 to exclude delimiter
string word2 = s.substr(pos1 + 1, pos2 - pos1 - 1);
```

**Why `-1`?** 
```
"hello*world*..."
      5     11
      
Start: pos1 + 1 = 6
Length: pos2 - pos1 - 1 = 11 - 5 - 1 = 5
Extracts: s[6] to s[10] = "world"
```

### 3. Starting Position Off by One
```cpp
// ❌ WRONG - includes the delimiter
string word2 = s.substr(pos1, ...);

// ✅ CORRECT - skip the delimiter
string word2 = s.substr(pos1 + 1, ...);
```

### 4. Extra Closing Brace
```cpp
// ❌ WRONG
void reverseString(string s) {
    // code
    cout << reversed << endl;
}
}  // Extra brace causes error!

// ✅ CORRECT - one brace per function
void reverseString(string s) {
    // code
    cout << reversed << endl;
}  // One closing brace only
```

---

## 📚 String Method Reference

```cpp
#include <string>

// Finding
int pos = s.find(char);         // Find first occurrence
int pos = s.find(char, start);  // Find from start position
int pos = s.find(string);       // Find substring

// Extracting
string sub = s.substr(start);          // From start to end
string sub = s.substr(start, length);  // Specific length

// Other useful methods
int len = s.length();           // String length
string combined = s1 + s2;      // Concatenation
char c = s[i];                  // Access character at index i
```

---

## 🎯 Parsing Pattern (4 Words with 3 Delimiters)

**Input:** `"word1*word2*word3*word4"`

**Step 1: Find Positions**
```cpp
int pos1 = s.find('*');           // Position of first *
int pos2 = s.find('*', pos1+1);   // Position of second *
int pos3 = s.find('*', pos2+1);   // Position of third *
```

**Step 2: Extract Words**
```cpp
string word1 = s.substr(0, pos1);                    // Before first *
string word2 = s.substr(pos1+1, pos2-pos1-1);        // Between 1st and 2nd *
string word3 = s.substr(pos2+1, pos3-pos2-1);        // Between 2nd and 3rd *
string word4 = s.substr(pos3+1);                     // After third *
```

**Step 3: Process**
```cpp
string reversed = word4 + " " + word3 + " " + word2 + " " + word1;
```

---

## 📐 Index Visualization

```
String: "hello*world*foo*bar"
Index:   0123456789...
         h e l l o * w o r l d * f o o * b a r
                   5         11      15

pos1 = 5
pos2 = 11
pos3 = 15

word1: s.substr(0, 5)        → "hello"   (indices 0-4)
word2: s.substr(6, 5)        → "world"   (indices 6-10)
word3: s.substr(12, 3)       → "foo"     (indices 12-14)
word4: s.substr(16)          → "bar"     (indices 16-18)
```

---

## ✅ Exam Checklist

- [ ] Use `getline(cin, s)` for full line input
- [ ] Include `<string>` header
- [ ] Find positions: `s.find(delimiter, start)`
- [ ] Extract with correct length: `pos2 - pos1 - 1`
- [ ] Start position after delimiter: `pos1 + 1`
- [ ] Count braces: each `{` needs one `}`
- [ ] Test with sample input to verify indices
- [ ] Concatenate with `+` operator
- [ ] No semicolon after function header

---

**Good luck! 🚀**
