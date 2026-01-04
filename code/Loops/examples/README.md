# Pattern Examples - Individual Files

This directory contains standalone C++ files for each pattern type with detailed explanations and trace tables.

## How to Use These Examples

Each file can be compiled and run independently:

```bash
g++ -o example 01_rectangle.cpp
./example
```

## Files

| File | Pattern | Difficulty | Key Concept |
|------|---------|------------|-------------|
| [01_rectangle.cpp](file:///Users/krishangsarkar/.gemini/antigravity/scratch/pattern_cpp/examples/01_rectangle.cpp) | Rectangle | ⭐ Easy | Fixed rows & columns |
| [02_right_triangle.cpp](file:///Users/krishangsarkar/.gemini/antigravity/scratch/pattern_cpp/examples/02_right_triangle.cpp) | Right Triangle (stars) | ⭐ Easy | `j <= i` (increasing) |
| [03_rowwise_vs_colwise.cpp](file:///Users/krishangsarkar/.gemini/antigravity/scratch/pattern_cpp/examples/03_rowwise_vs_colwise.cpp) | Numbers (both ways) | ⭐⭐ Medium | Print `j` vs `i` |
| [04_triangle_rowwise.cpp](file:///Users/krishangsarkar/.gemini/antigravity/scratch/pattern_cpp/examples/04_triangle_rowwise.cpp) | Triangle + row numbers | ⭐⭐ Medium | Triangle + print `j` |
| [05_triangle_colwise.cpp](file:///Users/krishangsarkar/.gemini/antigravity/scratch/pattern_cpp/examples/05_triangle_colwise.cpp) | Triangle + col numbers | ⭐⭐ Medium | Triangle + print `i` |
| [06_triangle_alphabet.cpp](file:///Users/krishangsarkar/.gemini/antigravity/scratch/pattern_cpp/examples/06_triangle_alphabet.cpp) | Triangle alphabets | ⭐⭐ Medium | ASCII conversion |
| [07_isosceles_triangle.cpp](file:///Users/krishangsarkar/.gemini/antigravity/scratch/pattern_cpp/examples/07_isosceles_triangle.cpp) | Centered triangle | ⭐⭐⭐ Hard | Conditional printing |

## Study Approach

### For Beginners
1. Start with `01_rectangle.cpp` - understand basic nested loops
2. Move to `02_right_triangle.cpp` - learn variable loop limits
3. Study `03_rowwise_vs_colwise.cpp` - master the i vs j concept

### For Exam Prep
1. Try to write each pattern from memory
2. Compare with the solution
3. Trace through with different n values
4. Understand the mathematical relationship

## Key Takeaways

Each file includes:
- **Visual output example**
- **Code with comments**
- **Trace table** showing how variables change
- **Key concepts** highlighted

## Quick Compilation

Compile all examples at once:
```bash
g++ -o rect 01_rectangle.cpp
g++ -o tri 02_right_triangle.cpp
g++ -o nums 03_rowwise_vs_colwise.cpp
g++ -o tri_row 04_triangle_rowwise.cpp
g++ -o tri_col 05_triangle_colwise.cpp
g++ -o tri_alpha 06_triangle_alphabet.cpp
g++ -o iso 07_isosceles_triangle.cpp
```

Then run each one to see the output!

## Understanding Strategy

For each pattern, ask yourself:
1. **How many rows?** → Outer loop
2. **How many items per row?** → Inner loop limit
3. **What to print?** → Expression in cout
4. **Any spaces needed?** → Additional logic
