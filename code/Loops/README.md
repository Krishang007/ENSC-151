# Pattern Generator - C++ Modular Implementation

A modular C++ implementation of a pattern generator program with triangle, square, and rectangle patterns.

## Project Structure

```
pattern_cpp/
├── main.cpp              # Entry point
├── menu.h / menu.cpp     # Main menu system
├── rectangle.h / rectangle.cpp   # Rectangle patterns
├── square.h / square.cpp         # Square patterns
├── number.h / number.cpp         # Number patterns
├── alphabet.h / alphabet.cpp     # Alphabet patterns
└── triangle.h / triangle.cpp     # Triangle patterns
```

## How to Compile

```bash
g++ -o pattern main.cpp menu.cpp rectangle.cpp square.cpp number.cpp alphabet.cpp triangle.cpp
```

## How to Run

```bash
./pattern
```

## Features

### Triangle Patterns
- Isosceles triangle (centered star)
- Right triangle (star, number, alphabet variations)

### Square Patterns
- Star square
- Number square (row-wise and column-wise)
- Alphabet square (row-wise and column-wise)

### Rectangle Patterns
- Custom width and height star rectangle

## File Breakdown

| File | Contains |
|------|----------|
| `rectangle.cpp` | `rectanglePattern()` - Creates custom rectangles |
| `square.cpp` | `square()`, `starSquare()` - Square pattern menu and star squares |
| `number.cpp` | `num()`, `numRow()`, `numCol()` - Number patterns |
| `alphabet.cpp` | `alpha()`, `alphar()`, `alphac()` - Alphabet patterns |
| `triangle.cpp` | All triangle functions including isosceles and right triangles |
| `menu.cpp` | `menu()` - Main menu interface |
| `main.cpp` | Program entry point |

## Conversion Notes

This project was converted from C to C++ with the following changes:
- Replaced `printf()` with `std::cout`
- Replaced `scanf()` with `std::cin`
- Replaced `#include<stdio.h>` with `#include<iostream>`
- Used `static_cast<char>()` for character conversions
- Organized into modular files with proper header guards
