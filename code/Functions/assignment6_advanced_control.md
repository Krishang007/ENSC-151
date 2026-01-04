# Assignment 6: Advanced Control Flow
## Exam-Focused Notes (Code & Math Only)

---

## 🎯 Core Concepts

1. **Do-While Loops** - Execute at least once
2. **Switch Statements** - Multi-way branching
3. **Pass by Reference** - Modify original variables
4. **Menu-Driven Programs** - User interaction loops

---

## � Thermal Conduction Problem (Assignment 6)

### Formula
$$H = \frac{kA(T_2 - T_1)}{X}$$

**Variables:**
- H = rate of heat transfer (W)
- k = coefficient of thermal conductivity (W/m-K)
- A = cross-sectional area (m²)
- T1, T2 = temperatures (K)
- X = thickness (m)

### Solving for Different Variables

**Solve for k:**
$$k = \frac{HX}{A(T_2 - T_1)}$$

**Solve for T2:**
$$T_2 = T_1 + \frac{HX}{kA}$$

**Solve for X:**
$$X = \frac{kA(T_2 - T_1)}{H}$$

---

## 📋 Complete Program Structure

```cpp
#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
int displayMenu();
void solveForK(double &H, double &k, double &A, double &T1, double &T2, double &X);
void solveForT2(double &H, double &k, double &A, double &T1, double &T2, double &X);
void solveForX(double &H, double &k, double &A, double &T1, double &T2, double &X);
void displayResults(double H, double k, double A, double T1, double T2, double X);

int main() {
    int choice;
    double H, k, A, T1, T2, X;
    
    do {
        choice = displayMenu();
        
        switch (choice) {
            case 1:
                solveForK(H, k, A, T1, T2, X);
                displayResults(H, k, A, T1, T2, X);
                break;
            case 2:
                solveForT2(H, k, A, T1, T2, X);
                displayResults(H, k, A, T1, T2, X);
                break;
            case 3:
                solveForX(H, k, A, T1, T2, X);
                displayResults(H, k, A, T1, T2, X);
                break;
            case 0:
                cout << "\nProgram exiting." << endl;
                break;
            default:
                cout << "Invalid selection!" << endl;
                break;
        }
    } while (choice != 0);
    
    return 0;
}

int displayMenu() {
    int choice;
    cout << "\nPlease select one of the following options:" << endl;
    cout << "  1) k" << endl;
    cout << "  2) T2" << endl;
    cout << "  3) X" << endl;
    cout << "  0) Exit" << endl;
    cout << "Selection: ";
    cin >> choice;
    return choice;
}

void solveForK(double &H, double &k, double &A, double &T1, double &T2, double &X) {
    cout << "Enter H (rate of heat transfer, W): ";
    cin >> H;
    cout << "Enter A (cross-sectional area, m^2): ";
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K): ";
    cin >> T1;
    cout << "Enter T2 (temp. at side 2, K): ";
    cin >> T2;
    cout << "Enter X (thickness, m): ";
    cin >> X;
    
    // Calculate k: k = (H * X) / (A * (T2 - T1))
    k = (H * X) / (A * (T2 - T1));
}

void solveForT2(double &H, double &k, double &A, double &T1, double &T2, double &X) {
    cout << "Enter H (rate of heat transfer, W): ";
    cin >> H;
    cout << "Enter k (coefficient of thermal conductivity, W/m-K): ";
    cin >> k;
    cout << "Enter A (cross-sectional area, m^2): ";
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K): ";
    cin >> T1;
    cout << "Enter X (thickness, m): ";
    cin >> X;
    
    // Calculate T2: T2 = T1 + (H * X) / (k * A)
    T2 = T1 + (H * X) / (k * A);
}

void solveForX(double &H, double &k, double &A, double &T1, double &T2, double &X) {
    cout << "Enter H (rate of heat transfer, W): ";
    cin >> H;
    cout << "Enter k (coefficient of thermal conductivity, W/m-K): ";
    cin >> k;
    cout << "Enter A (cross-sectional area, m^2): ";
    cin >> A;
    cout << "Enter T1 (temp. at side 1, K): ";
    cin >> T1;
    cout << "Enter T2 (temp. at side 2, K): ";
    cin >> T2;
    
    // Calculate X: X = (k * A * (T2 - T1)) / H
    X = (k * A * (T2 - T1)) / H;
}

void displayResults(double H, double k, double A, double T1, double T2, double X) {
    cout << fixed << setprecision(6);
    cout << "\n------------------------------------------------" << endl;
    cout << "H = " << H << " W" << endl;
    cout << "k = " << k << " W/m-K" << endl;
    cout << "A = " << A << " m^2" << endl;
    cout << "T1 = " << T1 << " K" << endl;
    cout << "T2 = " << T2 << " K" << endl;
    cout << "X = " << X << " m" << endl;
}
```

---

## 🎯 Key Patterns to Memorize

### 1. Menu Loop Structure
```cpp
do {
    choice = displayMenu();
    switch (choice) {
        case 1: /* ... */ break;
        case 2: /* ... */ break;
        case 0: /* exit */ break;
    }
} while (choice != 0);
```

### 2. Pass by Reference Parameters
```cpp
void solveForK(double &H, double &k, double &A, 
               double &T1, double &T2, double &X) {
    // All parameters use & to modify originals
    cin >> H >> A >> T1 >> T2 >> X;
    k = (H * X) / (A * (T2 - T1));  // Calculate unknown
}
```

### 3. Formula Rearrangement Pattern
**Given:** $H = \frac{kA(T_2 - T_1)}{X}$

**To solve for k:**
1. Multiply both sides by X: $HX = kA(T_2 - T_1)$
2. Divide by $A(T_2 - T_1)$: $k = \frac{HX}{A(T_2 - T_1)}$

**To solve for T2:**
1. Multiply by X: $HX = kA(T_2 - T_1)$
2. Divide by kA: $\frac{HX}{kA} = T_2 - T_1$
3. Add T1: $T_2 = T_1 + \frac{HX}{kA}$

**To solve for X:**
1. Multiply both sides by X: $HX = kA(T_2 - T_1)$
2. Divide by H: $X = \frac{kA(T_2 - T_1)}{H}$

---

## �🔄 Do-While Loop

### Syntax
```cpp
do {
    // Code executes AT LEAST ONCE
    // Then checks condition
} while (condition);
```

### vs While Loop
```cpp
// WHILE - may never execute
while (condition) {
    // code
}

// DO-WHILE - always executes once
do {
    // code
} while (condition);
```

### Input Validation Pattern
```cpp
int value;
do {
    cout << "Enter value (1-100): ";
    cin >> value;
    if (value < 1 || value > 100) {
        cout << "Invalid! Try again." << endl;
    }
} while (value < 1 || value > 100);
// Loop exits when value is valid
```

**Key Points:**
- Loop continues **while condition is TRUE**
- Exits when condition becomes **FALSE**
- Guarantees **at least one iteration**

---

## 🔀 Switch Statement

### Syntax
```cpp
switch (variable) {
    case value1:
        // code for value1
        break;  // CRITICAL: exits switch
    case value2:
        // code for value2
        break;
    case value3:
        // code for value3
        break;
    default:
        // code if no case matches
        break;
}
```

### Menu Example
```cpp
int choice;
switch (choice) {
    case 1:
        cout << "Option 1 selected" << endl;
        break;
    case 2:
        cout << "Option 2 selected" << endl;
        break;
    case 3:
        cout << "Option 3 selected" << endl;
        break;
    case 0:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
}
```

**⚠️ CRITICAL:** Forgetting `break` causes **fall-through**!

```cpp
// ❌ WRONG - missing break
switch (x) {
    case 1:
        cout << "One" << endl;  // No break!
    case 2:
        cout << "Two" << endl;  // Will also execute for x=1!
        break;
}

// ✅ CORRECT
switch (x) {
    case 1:
        cout << "One" << endl;
        break;  // Exits switch
    case 2:
        cout << "Two" << endl;
        break;
}
```

---

## 📌 Pass by Reference

### Syntax: Use `&` in Parameter
```cpp
// Pass by REFERENCE - modifies original
void modifyValue(double &x) {  // Note the &
    x = 10;  // Changes the original variable
}

// Pass by VALUE - does NOT modify original
void useValue(double x) {  // No &
    x = 10;  // Only changes local copy
}
```

### Example
```cpp
void solve(double a, double b, double &result) {
    result = a + b;  // Modifies original result
}

int main() {
    double num1 = 5, num2 = 3, answer;
    solve(num1, num2, answer);  // answer is passed by reference
    cout << answer;  // Prints: 8
}
```

### When to Use

| Pass by Value | Pass by Reference |
|---------------|-------------------|
| Want to READ only | Want to MODIFY |
| `double x` | `double &x` |
| Makes a copy | Works with original |
| Can't change original | Can change original |

---

## 🍽️ Menu-Driven Program Pattern

```cpp
#include <iostream>
using namespace std;

int displayMenu();
void option1();
void option2();
void option3();

int main() {
    int choice;
    
    do {
        choice = displayMenu();  // Get user choice
        
        switch (choice) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 0);  // Loop until user chooses exit
    
    return 0;
}

int displayMenu() {
    int choice;
    cout << "\n===== MENU =====" << endl;
    cout << "1. Option 1" << endl;
    cout << "2. Option 2" << endl;
    cout << "3. Option 3" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}
```

---

## ⚠️ Common Mistakes

### 1. Forgetting `break` in Switch
```cpp
// ❌ WRONG - fall-through error
switch (choice) {
    case 1:
        doSomething();  // Missing break!
    case 2:
        doSomethingElse();  // Also executes for choice=1!
}

// ✅ CORRECT
switch (choice) {
    case 1:
        doSomething();
        break;  // Exits switch
    case 2:
        doSomethingElse();
        break;
}
```

### 2. Forgetting `&` for Pass by Reference
```cpp
// ❌ WRONG - won't modify original
void calculate(double result) {  // Missing &
    result = 42;  // Only changes local copy
}

// ✅ CORRECT
void calculate(double &result) {  // Has &
    result = 42;  // Modifies original
}
```

### 3. Wrong Do-While Semicolon
```cpp
// ❌ WRONG - missing semicolon
do {
    // code
} while (condition)  // Missing ;

// ✅ CORRECT
do {
    // code
} while (condition);  // Semicolon required!
```

### 4. Do-While Condition Logic
```cpp
// ❌ WRONG - exits on valid input (backwards logic)
do {
    cout << "Enter 1-10: ";
    cin >> x;
} while (x >= 1 && x <= 10);  // Keeps looping on VALID input!

// ✅ CORRECT - exits on valid input
do {
    cout << "Enter 1-10: ";
    cin >> x;
} while (x < 1 || x > 10);  // Keeps looping on INVALID input
```

---

## 🎯 Reference Quick Guide

### Arrays are ALWAYS Passed by Reference
```cpp
void modifyArray(double arr[], int n) {
    arr[0] = 100;  // Modifies original array
    // No & needed - arrays are always by reference
}
```

### Multiple Return Values via Reference
```cpp
void calculate(double a, double b, double &sum, double &diff) {
    sum = a + b;    // Modifies original sum
    diff = a - b;   // Modifies original diff
}

int main() {
    double x = 10, y = 3, s, d;
    calculate(x, y, s, d);  // s and d are modified
    cout << s << " " << d;  // Prints: 13 7
}
```

---

## 📋 Switch vs If-Else

### When to Use Switch
- Testing **one variable** against **multiple values**
- Values are **discrete** (integers, chars)
- Many cases (3+)

```cpp
switch (menuChoice) {  // One variable, many values
    case 1: // ...
    case 2: // ...
    case 3: // ...
}
```

### When to Use If-Else
- Complex conditions
- Range checking
- Boolean expressions
- Comparing different variables

```cpp
if (x > 0 && x < 100) {  // Range check
    // ...
}
else if (y == 5 || z == 10) {  // Complex condition
    // ...
}
```

---

## 💡 Loop Comparison Table

| Loop Type | Executes | Best For |
|-----------|----------|----------|
| **for** | Known iterations | Counting, arrays |
| **while** | 0+ times | Unknown iterations, may skip |
| **do-while** | 1+ times | Input validation, menus |

---

## ✅ Exam Checklist

- [ ] Do-while ends with `while(condition);` (semicolon!)
- [ ] Switch cases ALL have `break` statements
- [ ] Switch has `default` case
- [ ] Pass by reference uses `&` in parameter
- [ ] Do-while loops on INVALID input (exits on valid)
- [ ] Menu loops until exit choice (e.g., `choice != 0`)
- [ ] Logical operators correct (`&&` vs `||`)
- [ ] Reference parameters modify originals
- [ ] Arrays don't need `&` (always by reference)

---

## 🔧 Complete Example: Input Validation

```cpp
// Get valid integer in range [min, max]
int getValidInput(int min, int max) {
    int value;
    do {
        cout << "Enter value (" << min << "-" << max << "): ";
        cin >> value;
        
        if (value < min || value > max) {
            cout << "Invalid! Must be between " << min 
                 << " and " << max << "." << endl;
        }
    } while (value < min || value > max);
    
    return value;
}
```

---

**Good luck! 🚀**
