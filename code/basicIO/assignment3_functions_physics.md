# Assignment 3: Functions & Physics Calculations
## Exam-Focused Notes (Code & Math Only)

---

## 🎯 Core Problem Pattern

**Input:** Initial speed, speed after time  
**Process:** Calculate deceleration, coasting time, distance  
**Output:** Statistics with proper units

---

## 📊 Essential Algorithms

### 1. Unit Conversion: km/h → m/s
```cpp
double kmhToMs(double speedKmh) {
    return speedKmh * (1000.0 / 3600.0);
}
```

**Math:** 
$$\text{m/s} = \frac{\text{km/h} \times 1000}{3600}$$

**⚠️ CRITICAL:** Use `1000.0` and `3600.0`, NOT `1000` and `3600`!
- `1000 / 3600 = 0` (integer division)
- `1000.0 / 3600.0 = 0.277778` (correct)

---

### 2. Calculate Deceleration
```cpp
double calculateDeceleration(double vFinal, double vInitial, double time) {
    return fabs(vFinal - vInitial) / time;
}
```

**Math:**
$$a = \frac{|v_f - v_i|}{t}$$

**Key Points:**
- Use `fabs()` for absolute value (double)
- Time in **seconds**
- Result in m/s²

---

### 3. Calculate Coasting Time
```cpp
double calculateCoastingTime(double vInitial, double deceleration) {
    return vInitial / deceleration;
}
```

**Math:**
$$t = \frac{v_i}{a}$$

**Assumes:** Final velocity = 0 (stopped)

---

### 4. Calculate Distance
```cpp
double calculateDistance(double vInitial, double deceleration) {
    return pow(vInitial, 2) / (2 * deceleration);
}
```

**Math:**
$$d = \frac{v_i^2}{2a}$$

**From:** $v_f^2 = v_i^2 - 2ad$ where $v_f = 0$

---

### 5. Convert Time to Minutes:Seconds
```cpp
int getMinutes(int totalSeconds) {
    return totalSeconds / 60;
}

int getSeconds(int totalSeconds) {
    return totalSeconds % 60;
}
```

**Algorithm:**
```cpp
int totalTime = int(round(timeInSeconds));
int min = totalTime / 60;   // Quotient
int sec = totalTime % 60;   // Remainder
```

**Example:** 125 seconds → 2 minutes, 5 seconds

---

### 6. Void Function (Non-Value-Returning)
```cpp
void displayProgramDescription() {
    cout << "==============================" << endl;
    cout << "  Bicycle Deceleration Analysis" << endl;
    cout << "==============================" << endl;
}
```

**Key Points:**
- Returns **nothing** (`void`)
- Used for **actions** (printing, etc.)
- No `return` statement needed

---

## 🔧 Function Structure

### Prototypes (Before main)
```cpp
double kmhToMs(double speedKmh);
double calculateDeceleration(double vFinal, double vInitial, double time);
double calculateCoastingTime(double vInitial, double deceleration);
double calculateDistance(double vInitial, double deceleration);
void displayProgramDescription();
```

### Main Function
```cpp
int main() {
    displayProgramDescription();
    
    double initialSpeed, speedAfterOneMinute;
    cout << "initial speed = ";
    cin >> initialSpeed;
    cout << " km/h" << endl;
    
    cout << "one minute speed = ";
    cin >> speedAfterOneMinute;
    cout << " km/h" << endl;
    
    // Convert to m/s
    double vin = kmhToMs(initialSpeed);
    double vfin = kmhToMs(speedAfterOneMinute);
    
    // Calculate using functions
    double deceleration = calculateDeceleration(vfin, vin, 60.0);
    double coastingTime = calculateCoastingTime(vin, deceleration);
    double distance = calculateDistance(vin, deceleration);
    
    // Convert time
    int totalTime = int(round(coastingTime));
    int min = totalTime / 60;
    int sec = totalTime % 60;
    int distanceRounded = int(round(distance));
    
    // Output
    cout << "\nResults:" << endl;
    cout << "deceleration = " << deceleration << " m/s^2" << endl;
    cout << "minutes = " << min << endl;
    cout << "seconds = " << sec << endl;
    cout << "distance = " << distanceRounded << " m" << endl;
    
    return 0;
}
```

### Definitions (After main)
```cpp
double kmhToMs(double speedKmh) {
    return speedKmh * (1000.0 / 3600.0);
}

double calculateDeceleration(double vFinal, double vInitial, double time) {
    return fabs(vFinal - vInitial) / time;
}

// ... other functions
```

---

## ⚠️ Common Mistakes

### 1. Integer Division Bug
```cpp
// ❌ WRONG - gives 0!
double vin = initialSpeed * (1000 / 3600);

// ✅ CORRECT
double vin = initialSpeed * (1000.0 / 3600.0);
```

### 2. Prototype Mismatch
```cpp
// ❌ WRONG - doesn't match definition
double calcDeceleration(double v1, double v2);  // 2 params
double calcDeceleration(double v1, double v2, double t) { ... }  // 3 params

// ✅ CORRECT
double calcDeceleration(double v1, double v2, double t);  // 3 params
double calcDeceleration(double v1, double v2, double t) { ... }  // 3 params
```

### 3. Not Calling Functions
```cpp
// ❌ WRONG - why create functions if you don't use them?
double deceleration = fabs(vfin - vin) / 60.0;

// ✅ CORRECT - use the function you created
double deceleration = calculateDeceleration(vfin, vin, 60.0);
```

### 4. Wrong Formula for Distance
```cpp
// ❌ WRONG - using final velocity (usually 0)
double distance = pow(vfin, 2) / (2 * deceleration);

// ✅ CORRECT - use initial velocity
double distance = pow(vin, 2) / (2 * deceleration);
```

### 5. Incomplete Function Call
```cpp
// ❌ WRONG - missing arguments
double result = calcDeceleration()
fabs(vfin - vin) / 60.0;

// ✅ CORRECT
double result = calcDeceleration(vfin, vin, 60.0);
```

---

## 📐 Math Functions

```cpp
#include <cmath>

fabs(x)         // Absolute value (double)
abs(x)          // Absolute value (int)
pow(base, exp)  // Power: base^exp
sqrt(x)         // Square root
round(x)        // Round to nearest integer
```

---

## 🎯 Exam Quick Reference

### Value-Returning Function
```cpp
double functionName(double param) {
    double result = /* calculation */;
    return result;  // MUST return something
}
```

### Non-Value-Returning (void)
```cpp
void functionName() {
    cout << "text";  // Just does something
    // No return statement
}
```

### Type Casting
```cpp
int(value)           // Convert to int (truncates)
int(round(value))    // Round THEN convert
double(intValue)     // Convert int to double
```

### Integer Operations
```cpp
totalSeconds / 60    // Quotient (minutes)
totalSeconds % 60    // Remainder (seconds)
```

---

## ✅ Exam Checklist

- [ ] All division with decimals uses `.0` (1000.0 / 3600.0)
- [ ] Prototype matches definition exactly (same # params, types)
- [ ] All functions are actually called in main()
- [ ] Value-returning functions have `return` statement
- [ ] Void functions don't return values
- [ ] Using correct formula for each calculation
- [ ] Include `<cmath>` for math functions
- [ ] Proper unit conversions (km/h → m/s)
- [ ] Round before converting to int: `int(round(x))`

---

**Good luck! 🚀**
