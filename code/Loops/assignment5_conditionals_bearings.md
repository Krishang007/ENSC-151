# Assignment 5: Conditionals & Compass Bearings
## Exam-Focused Notes (Code & Math Only)

---

## 🎯 Core Problem Pattern

**Input:** Compass heading (0-360 degrees)  
**Process:** Convert to bearing format (dir1 angle dir2)  
**Output:** Direction, angle, direction

---

## 🧭 Bearing Conversion Logic

### Compass Quadrants
```
        North (0°/360°)
             |
   NW    315°|45°    NE
        \   |   /
         \  |  /
    270°————+————90° East
         /  |  \
        /   |   \
   SW    225°|135°   SE
             |
        South (180°)
```

### Conversion Rules

| Heading Range | Direction 1 | Angle Calculation | Direction 2 |
|---------------|-------------|-------------------|-------------|
| 0° to 90° | North | heading | East |
| 90° to 180° | South | 180 - heading | East |
| 180° to 270° | South | heading - 180 | West |
| 270° to 360° | North | 360 - heading | West |

---

## 📊 Complete Algorithm

```cpp
#include <iostream>
using namespace std;

void bearingCalculator(double heading_angle);

int main() {
    double heading_angle;
    
    for (int i = 0; i < 5; i++) {  // 5 iterations
        cout << "Please enter heading [0, 360): ";
        cin >> heading_angle;
        bearingCalculator(heading_angle);
    }
    
    return 0;
}

void bearingCalculator(double heading_angle) {
    string dir1, dir2;
    double bearingAngle;
    
    // 1. Validate input FIRST
    if (heading_angle < 0 || heading_angle >= 360) {
        cout << heading_angle << " is an invalid input." << endl;
        return;  // Exit function
    }

    // 2. Handle edge cases (0, 90, 180, 270)
    if (heading_angle == 0) {
        dir1 = "North";
        bearingAngle = 0;
        dir2 = "East";
    }
    else if (heading_angle == 90) {
        dir1 = "North";  // Favor North
        bearingAngle = 90;
        dir2 = "East";
    }
    else if (heading_angle == 180) {
        dir1 = "South";
        bearingAngle = 0;
        dir2 = "East";  // Favor East
    }
    else if (heading_angle == 270) {
        dir1 = "North";  // Favor North
        bearingAngle = 90;
        dir2 = "West";
    }
    // 3. Quadrant 1: 0° < angle < 90°
    else if (heading_angle > 0 && heading_angle < 90) {
        dir1 = "North";
        bearingAngle = heading_angle;
        dir2 = "East";
    }
    // 4. Quadrant 2: 90° < angle < 180°
    else if (heading_angle > 90 && heading_angle < 180) {
        dir1 = "South";
        bearingAngle = 180 - heading_angle;
        dir2 = "East";
    }
    // 5. Quadrant 3: 180° < angle < 270°
    else if (heading_angle > 180 && heading_angle < 270) {
        dir1 = "South";
        bearingAngle = heading_angle - 180;
        dir2 = "West";
    }
    // 6. Quadrant 4: 270° < angle < 360°
    else {
        dir1 = "North";
        bearingAngle = 360 - heading_angle;
        dir2 = "West";
    }
    
    // Output
    cout << "Heading of : " << heading_angle << " degrees is "
         << dir1 << " " << bearingAngle << " " << dir2 << endl;
}
```

---

## 🔄 For Loop Pattern

```cpp
for (int i = 0; i < 5; i++) {
    // Loop body executes 5 times
    // i goes: 0, 1, 2, 3, 4
}
```

**Structure:**
```cpp
for (initialization; condition; increment) {
    // code
}
```

---

## ⚠️ Common Mistakes

### 1. Missing Input Validation
```cpp
// ❌ WRONG - doesn't check if input is valid
void bearingCalculator(double heading_angle) {
    // Directly processes without validation
}

// ✅ CORRECT - validate first
void bearingCalculator(double heading_angle) {
    if (heading_angle < 0 || heading_angle >= 360) {
        cout << heading_angle << " is an invalid input." << endl;
        return;  // Stop execution
    }
    // Now process valid input
}
```

### 2. Wrong Boundary Condition
```cpp
// ❌ WRONG - allows 360 (invalid for [0, 360))
if (heading_angle < 0 || heading_angle > 360)

// ✅ CORRECT - use >= for exclusive upper bound
if (heading_angle < 0 || heading_angle >= 360)
```

**Remember:**
- `[0, 360)` means: 0 ≤ x < 360
- Use `>= 360` to reject

### 3. Wrong Cardinal Direction
```cpp
// ❌ WRONG - Quadrant 1 should be NORTH
if (heading_angle > 0 && heading_angle < 90) {
    dir1 = "South";  // WRONG!
}

// ✅ CORRECT
if (heading_angle > 0 && heading_angle < 90) {
    dir1 = "North";  // 0-90° is North-East quadrant
}
```

### 4. No Return After Invalid Input
```cpp
// ❌ WRONG - continues execution after error
if (heading_angle < 0 || heading_angle >= 360) {
    cout << "invalid" << endl;
}
// Code keeps running with invalid input!

// ✅ CORRECT - exit function
if (heading_angle < 0 || heading_angle >= 360) {
    cout << "invalid" << endl;
    return;  // Stop here!
}
```

---

## 📐 Test Cases

| Input | Expected Output |
|-------|----------------|
| -1 | -1 is an invalid input. |
| 0 | Heading of : 0 degrees is North 0 East |
| 45 | Heading of : 45 degrees is North 45 East |
| 90 | Heading of : 90 degrees is North 90 East |
| 110 | Heading of : 110 degrees is South 70 East |
| 180 | Heading of : 180 degrees is South 0 East |
| 225 | Heading of : 225 degrees is South 45 West |
| 270 | Heading of : 270 degrees is North 90 West |
| 320 | Heading of : 320 degrees is North 40 West |
| 360 | 360 is an invalid input. |

---

## 🎯 Conditional Logic Reference

### Comparison Operators
```cpp
<    // Less than
>    // Greater than
<=   // Less than or equal
>=   // Greater than or equal
==   // Equal to
!=   // Not equal to
```

### Logical Operators
```cpp
&&   // AND - both conditions must be true
||   // OR - at least one condition must be true
!    // NOT - negates condition

// Examples
if (x >= 0 && x < 90)       // x in range [0, 90)
if (x < 0 || x >= 360)      // x outside [0, 360)
if (!(x == 90))             // x is not 90
```

### If-Else Chain
```cpp
if (condition1) {
    // Execute if condition1 is true
}
else if (condition2) {
    // Execute if condition1 false, condition2 true
}
else if (condition3) {
    // Execute if both above false, condition3 true
}
else {
    // Execute if all above false
}
```

---

## 💡 Edge Case Handling

**Cardinal Directions (Exactly 0, 90, 180, 270):**

```cpp
// Ambiguity rules from assignment:
// - 90° and 270°: Favor North
// - 0° and 180°: Favor East

if (heading_angle == 0) {
    // Could be "North 0 East" or "North 0 West"
    // Choose East (assignment rule)
}
else if (heading_angle == 90) {
    // Could be "North 90 East" or "South 90 East"
    // Choose North (assignment rule)
}
```

---

## ✅ Exam Checklist

- [ ] Input validation at START of function
- [ ] Use `>= 360` for range [0, 360)
- [ ] Use `return;` after invalid input message
- [ ] Handle edge cases (0, 90, 180, 270) separately
- [ ] Correct quadrant logic:
  - Q1 (0-90): North X East
  - Q2 (90-180): South X East
  - Q3 (180-270): South X West
  - Q4 (270-360): North X West
- [ ] Correct angle calculations:
  - Q1: angle
  - Q2: 180 - angle
  - Q3: angle - 180
  - Q4: 360 - angle
- [ ] Test with provided examples
- [ ] Use for loop for multiple iterations

---

**Good luck! 🚀**
