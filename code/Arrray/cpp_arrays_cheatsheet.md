# C++ Arrays Cheat Sheet

## 📋 Table of Contents
1. [Declaration & Initialization](#declaration--initialization)
2. [Accessing Elements](#accessing-elements)
3. [Common Operations](#common-operations)
4. [Passing Arrays to Functions](#passing-arrays-to-functions)
5. [Multi-Dimensional Arrays](#multi-dimensional-arrays)
6. [Common Algorit](#common-algorithms)
7. [Tips & Common Pitfalls](#tips--common-pitfalls)

---

## Declaration & Initialization

### Basic Declaration
```cpp
// Declare an array of 5 integers
int numbers[5];

// Declare and initialize with specific values
int scores[5] = {85, 90, 78, 92, 88};

// Size is inferred from initializer list
int values[] = {10, 20, 30, 40};  // Size is 4

// Partial initialization (rest are 0)
int data[10] = {1, 2, 3};  // Rest are initialized to 0

// Initialize all elements to 0
int zeros[100] = {0};
```

### Character Arrays (C-strings)
```cpp
// String literal (null-terminated automatically)
char name[] = "John";  // Size is 5 (4 chars + '\0')

// Manual character array
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

// Declare with size
char buffer[100];
```

---

## Accessing Elements

### Indexing
```cpp
int arr[5] = {10, 20, 30, 40, 50};

// Access elements (0-indexed)
int first = arr[0];   // 10
int last = arr[4];    // 50

// Modify elements
arr[2] = 99;          // arr is now {10, 20, 99, 40, 50}
```

### Using Loops
```cpp
int numbers[5] = {1, 2, 3, 4, 5};

// For loop
for (int i = 0; i < 5; i++) {
    cout << numbers[i] << " ";
}

// Range-based for loop (C++11)
for (int num : numbers) {
    cout << num << " ";
}

// Reverse iteration
for (int i = 4; i >= 0; i--) {
    cout << numbers[i] << " ";
}
```

---

## Common Operations

### Finding Size
```cpp
int arr[10];

// Get size of array
int size = sizeof(arr) / sizeof(arr[0]);  // 10

// For char arrays
char str[] = "Hello";
int length = strlen(str);  // 5 (not including '\0')
```

### Input/Output
```cpp
int scores[5];

// Reading input
cout << "Enter 5 scores: ";
for (int i = 0; i < 5; i++) {
    cin >> scores[i];
}

// Displaying output
for (int i = 0; i < 5; i++) {
    cout << "Score " << i+1 << ": " << scores[i] << endl;
}
```

### Finding Min/Max
```cpp
int arr[5] = {12, 45, 7, 23, 56};
int size = 5;

// Find minimum
int min = arr[0];
for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
        min = arr[i];
    }
}

// Find maximum
int max = arr[0];
for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
        max = arr[i];
    }
}
```

### Sum and Average
```cpp
int numbers[5] = {10, 20, 30, 40, 50};
int sum = 0;

// Calculate sum
for (int i = 0; i < 5; i++) {
    sum += numbers[i];
}

// Calculate average
double average = sum / 5.0;
```

### Copying Arrays
```cpp
int source[5] = {1, 2, 3, 4, 5};
int destination[5];

// Manual copy
for (int i = 0; i < 5; i++) {
    destination[i] = source[i];
}
```

### Reversing an Array
```cpp
int arr[5] = {1, 2, 3, 4, 5};
int size = 5;

// In-place reversal
for (int i = 0; i < size / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
}
// Result: {5, 4, 3, 2, 1}
```

---

## Passing Arrays to Functions

### Passing by Reference
```cpp
// Method 1: Array notation
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// Method 2: Pointer notation (equivalent)
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// Calling the function
int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    printArray(numbers, 5);
}
```

### Modifying Array Elements
```cpp
void doubleValues(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifies original array
    }
}

int main() {
    int data[3] = {5, 10, 15};
    doubleValues(data, 3);
    // data is now {10, 20, 30}
}
```

---

## Multi-Dimensional Arrays

### 2D Arrays (Matrices)
```cpp
// Declaration and initialization
int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};

// Accessing elements
int element = matrix[1][2];  // 7 (row 1, column 2)

// Looping through 2D array
for (int i = 0; i < 3; i++) {          // rows
    for (int j = 0; j < 4; j++) {      // columns
        cout << matrix[i][j] << " ";
    }
    cout << endl;
}
```

### Common 2D Operations
```cpp
// 3x3 matrix
int grid[3][3];

// Read input
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        cin >> grid[i][j];
    }
}

// Sum of all elements
int sum = 0;
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        sum += grid[i][j];
    }
}
```

### Passing 2D Arrays to Functions
```cpp
// Must specify column size
void printMatrix(int arr[][4], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    printMatrix(mat, 3);
}
```

---

## Common Algorithms

### Linear Search
```cpp
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Not found
}
```

### Binary Search (requires sorted array)
```cpp
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Not found
}
```

### Bubble Sort
```cpp
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

### Selection Sort
```cpp
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        
        // Find minimum element
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
```

### Insertion Sort
```cpp
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

---

## Tips & Common Pitfalls

### ✅ DO's

1. **Always initialize arrays before using them**
   ```cpp
   int arr[5] = {0};  // Good
   ```

2. **Use meaningful variable names**
   ```cpp
   int studentScores[30];  // Better than arr[30]
   ```

3. **Pass size as a parameter to functions**
   ```cpp
   void process(int arr[], int size);
   ```

4. **Check array bounds**
   ```cpp
   if (index >= 0 && index < size) {
       // Safe to access arr[index]
   }
   ```

### ❌ DON'Ts

1. **Don't access out-of-bounds indices**
   ```cpp
   int arr[5];
   arr[5] = 10;  // BAD! Valid indices are 0-4
   ```

2. **Don't forget the null terminator for C-strings**
   ```cpp
   char name[5] = {'J', 'o', 'h', 'n', '\0'};  // Good
   ```

3. **Don't use = to copy arrays**
   ```cpp
   int a[5] = {1, 2, 3, 4, 5};
   int b[5];
   b = a;  // ERROR! Won't compile
   ```

4. **Don't return local arrays from functions**
   ```cpp
   int* createArray() {
       int arr[5];  // Local array
       return arr;  // BAD! Undefined behavior
   }
   ```

### 🔍 Common Patterns

**Swap two elements:**
```cpp
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
```

**Check if sorted:**
```cpp
bool isSorted = true;
for (int i = 0; i < size - 1; i++) {
    if (arr[i] > arr[i + 1]) {
        isSorted = false;
        break;
    }
}
```

**Count occurrences:**
```cpp
int count = 0;
for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
        count++;
    }
}
```

---

## 📚 Quick Reference

| Operation | Time Complexity | Code Pattern |
|-----------|----------------|--------------|
| Access element | O(1) | `arr[i]` |
| Linear search | O(n) | Loop through all |
| Binary search | O(log n) | Divide and conquer |
| Bubble sort | O(n²) | Nested loops, swap |
| Selection sort | O(n²) | Find min, swap |
| Insertion sort | O(n²) | Insert in place |

---

## 💡 Remember

- Arrays are **0-indexed** (first element is at index 0)
- Array size is **fixed** at compile time
- Arrays are passed by **reference** to functions
- No bounds checking in C++ (programmer's responsibility)
- Use `sizeof(arr)/sizeof(arr[0])` to get array size (only in same scope where array is declared)

---

**Good luck with your ENSC 151 exam! 🚀**
