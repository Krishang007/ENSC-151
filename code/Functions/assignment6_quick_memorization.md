# Assignment 6: Quick Memorization Guide
## Thermal Conduction Menu Program

---

## 🧠 **What to Memorize: The 3-Part Pattern**

You don't need to memorize exact code. Just remember these 3 patterns:

---

### **PART 1: Menu Loop (DMW-S)**

**Mnemonic: "DMW-S" = Do-Menu-While-Switch**

```cpp
do {
    choice = displayMenu();
    
    switch (choice) {
        case 1: /* solve 1 */ break;
        case 2: /* solve 2 */ break;
        case 3: /* solve 3 */ break;
        case 0: /* exit */   break;
    }
} while (choice != 0);
```

**Memory Trick:** Menu programs always follow **DMW-S**!

---

### **PART 2: Pass by Reference Function**

**Mnemonic: "All parameters get &"**

```cpp
void solveForK(double &H, double &k, double &A,
               double &T1, double &T2, double &X) {
    // 1. Get inputs (all except k)
    cin >> H >> A >> T1 >> T2 >> X;
    
    // 2. Calculate k using formula
    k = (H * X) / (A * (T2 - T1));
}
```

**Pattern:**
- Input: Get ALL variables EXCEPT the one you're solving for
- Calculate: Use rearranged formula

---

### **PART 3: Formula Rearrangement**

**Original:** $H = \frac{kA(T_2 - T_1)}{X}$

**Memory Trick: "Cross-multiply pyramid"**

```
        H
       ---  =  numerator = kA(T2-T1)
        X       denominator = X
```

**To find any variable:**
1. **Top ✕ Bottom** = **Numerator**
2. Solve for what you need

**Solve for k:**
```
H × X = k × A × (T2-T1)
k = (H × X) / (A × (T2-T1))
```

**Solve for T2:**
```
H × X = k × A × (T2-T1)
(H × X) / (k × A) = T2 - T1
T2 = T1 + (H × X) / (k × A)
```

**Solve for X:**
```
H × X = k × A × (T2-T1)
X = (k × A × (T2-T1)) / H
```

---

## 📝 **4-Minute Memorization Drill**

### Step 1: Write DMW-S Pattern (1 min)
```cpp
do {
    ____________
    switch (____) {
        ____________
    }
} while (________);
```

### Step 2: Write Function Signature (1 min)
```cpp
void solveFor???(double &__, double &__, ...) {
    cin >> ____________;
    ___ = formula;
}
```

### Step 3: Write 3 Formulas (2 min)
```
k  = ______________
T2 = ______________
X  = ______________
```

**Answers:**
1. `do { choice = menu(); switch... } while (choice != 0);`
2. `void solveForK(double &H, ...) { cin >> H >> A >> T1 >> T2 >> X; k = ...; }`
3. `k = HX/(A(T2-T1))`, `T2 = T1 + HX/(kA)`, `X = kA(T2-T1)/H`

---

## 🎯 **Exam Strategy**

### Don't worry about:
- Exact menu text
- Variable order in function
- Comment wording

### DO remember:
1. **DMW-S** structure
2. **All params need &** in pass-by-reference
3. **3 formula rearrangements**
4. **Input everything EXCEPT what you're solving for**

---

## ✅ **5-Minute Practice**

**Without looking, write:**

1. The do-while switch menu structure
2. One solve function (pick any variable)
3. The formula for that variable

**If you can do this, you know Assignment 6!** 🎉

---

## 💡 **Formula Memory Shortcuts**

### Visual: Fraction Balance

```
Original:  H/X = kA(T2-T1)

Find k:    Move X up    → k = HX / [A(T2-T1)]
Find T2:   Move kA down → T2 = T1 + HX/(kA)
Find X:    Move H down  → X = kA(T2-T1)/H
```

**Think:** What's on top? What's on bottom? Where does it go?

---

## 🔑 **The Only 3 Lines That Matter**

```cpp
k  = (H * X) / (A * (T2 - T1));
T2 = T1 + (H * X) / (k * A);
X  = (k * A * (T2 - T1)) / H;
```

**Memorize these 3 calculations, and you're golden!** ⭐

---

**Good luck! 🚀**
