# Assignment 7: Array Patterns & Algorithms
## Exam-Focused Notes (Code & Math Only)

---

## 🎯 Core Problem Pattern

**Input:** Array of doubles, size 1-100  
**Process:** Compute statistics  
**Output:** Count, max, positions

---

## 📊 Essential Algorithms

### 1. Input Validation with Do-While
```cpp
int getInputCount() {
    int n;
    do {
        cout << "Please state the number of inputs: ";
        cin >> n;
        if (n < 1 || n > 100) {
            cout << "Invalid input: number must be between 1 and 100." << endl;
        }
    } while (n < 1 || n > 100);
    return n;
}
```

**Key Points:**
- Loop executes **at least once**
- Keeps looping **while condition is TRUE**
- Exits when input is **valid**

---

### 2. Reading Array Values
```cpp
void getValues(double arr[], int n) {
    cout << "Please input all " << n << " values separated by whitespace: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}
```

**Key Points:**
- `arr[]` parameter = array passed by reference (automatic)
- `i < n` → processes exactly n elements
- Index range: `0` to `n-1`

---

### 3. Computing Average
```cpp
double computeAverage(double arr[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}
```

**Math:** 
$$\text{average} = \frac{\sum_{i=0}^{n-1} arr[i]}{n}$$

**Key Points:**
- Initialize sum to `0`
- Loop through all elements
- Divide by **total count** `n`, not `n-1`

---

### 4. Count Above Average
```cpp
int countAboveAverage(double arr[], int n, double avg) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > avg) {
            count++;
        }
    }
    return count;
}
```

**Algorithm:**
1. Initialize counter to `0`
2. Loop through array
3. If element **greater than** average → increment
4. Return count

---

### 5. Find Maximum
```cpp
double findMaximum(double arr[], int n) {
    double maxVal = arr[0];  // Assume first is max
    for (int i = 1; i < n; i++) {  // Start from index 1
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
```

**Key Points:**
- **Start:** `maxVal = arr[0]` (first element)
- **Loop:** `i = 1` to `n-1` (skip first)
- **Update:** Only if `arr[i] > maxVal`

---

### 6. Find All Positions of Maximum
```cpp
void printMaxPositions(double arr[], int n, double maxValue) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == maxValue) {
            cout << i << " ";
        }
    }
}
```

**Key Points:**
- Loop through **entire array**
- Check **equality** with `==`
- Print **index** `i`, not value
- Space-separated output

---

## 🔢 Array Parameter Syntax

### Declaration
```cpp
void processArray(double arr[], int n);
```

### Definition
```cpp
void processArray(double arr[], int n) {
    // arr[] is automatically passed by reference
    // n is the size (pass by value)
}
```

### Call
```cpp
double myArray[100];
int count = 10;
processArray(myArray, count);  // No & needed for arrays!
```

---

## 📝 Main Function Structure

```cpp
int main() {
    int num = getInputCount();           // Get validated count
    double values[100];                  // Declare array
    getValues(values, num);              // Fill array
    
    double avg = computeAverage(values, num);
    int numAbove = countAboveAverage(values, num, avg);
    double maxVal = findMaximum(values, num);
    
    // Output
    cout << fixed << setprecision(2);
    cout << "The number of values above the average is " << numAbove << "." << endl;
    cout << "The maxim value was " << maxVal << "." << endl;
    cout << "The maximum occurred at the following positions: ";
    printMaxPositions(values, num, maxVal);
    cout << endl;
    
    return 0;
}
```

---

## ⚠️ Common Mistakes

### 1. Wrong Loop Range
```cpp
// ❌ WRONG - off by one error
for (int i = 0; i <= n; i++)  // Out of bounds!

// ✅ CORRECT
for (int i = 0; i < n; i++)   // 0 to n-1
```

### 2. Finding Max Starting from Wrong Index
```cpp
// ❌ WRONG - checks first element twice
double maxVal = arr[0];
for (int i = 0; i < n; i++)

// ✅ CORRECT
double maxVal = arr[0];
for (int i = 1; i < n; i++)  // Start from index 1
```

### 3. Not Initializing Accumulator
```cpp
// ❌ WRONG - sum has garbage value
double sum;
for (int i = 0; i < n; i++)
    sum += arr[i];

// ✅ CORRECT
double sum = 0;  // Initialize!
for (int i = 0; i < n; i++)
    sum += arr[i];
```

### 4. Dividing by Wrong Value
```cpp
// ❌ WRONG - dividing by n-1
return sum / (n - 1);

// ✅ CORRECT - divide by total count
return sum / n;
```

### 5. Printing Value Instead of Index
```cpp
// ❌ WRONG - prints the value
if (arr[i] == maxValue) {
    cout << arr[i] << " ";
}

// ✅ CORRECT - prints the index (position)
if (arr[i] == maxValue) {
    cout << i << " ";
}
```

---

## 🎯 Exam Quick Reference

### Array Declaration
```cpp
double arr[100];        // Fixed size
int values[50];
```

### Array Access
```cpp
arr[0]       // First element
arr[i]       // Element at index i
arr[n-1]     // Last element
```

### Common Patterns

**Sum:**
```cpp
sum = 0;
for (i = 0; i < n; i++) sum += arr[i];
```

**Average:**
```cpp
avg = sum / n;
```

**Max:**
```cpp
max = arr[0];
for (i = 1; i < n; i++)
    if (arr[i] > max) max = arr[i];
```

**Min:**
```cpp
min = arr[0];
for (i = 1; i < n; i++)
    if (arr[i] < min) min = arr[i];
```

**Count with Condition:**
```cpp
count = 0;
for (i = 0; i < n; i++)
    if (arr[i] > threshold) count++;
```

---

## 💡 Output Formatting

```cpp
#include <iomanip>

cout << fixed << setprecision(2);  // 2 decimal places
cout << value << endl;             // Prints with 2 decimals
```

---

## ✅ Exam Checklist

Before submitting array code:

- [ ] Array size declared as `[100]` or constant
- [ ] Loop range is `i < n`, not `i <= n`
- [ ] Accumulators initialized to `0`
- [ ] Finding max/min starts from index `1` (after setting `arr[0]`)
- [ ] Array parameters use `arr[]` syntax
- [ ] Passing array: use name only, no `&` needed
- [ ] Print **index** for positions, not values
- [ ] Input validation uses do-while loop
- [ ] Average divides by `n`, not `n-1`

---

**Good luck! 🚀**
