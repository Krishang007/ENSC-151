#include "triangle.h"
#include <iostream>

void isoscelesTriangle() {
  char again;
  int i, j, n;
  do {
    do {
      std::cout << "Enter number of rows: ";
      std::cin >> n;
      if (n <= 0) {
        std::cout << "Re-enter\n";
      }
    } while (n <= 0);

    for (i = 1; i <= n; i++) {
      for (j = 1; j <= 2 * n - 1; j++) {
        if (j >= n - (i - 1) && j <= n + (i - 1)) {
          std::cout << "*";
        } else {
          std::cout << " ";
        }
      }
      std::cout << "\n";
    }
    std::cout << "\nDo you want to create another triangle (y/n): ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');
  if (again == 'n' || again == 'N') {
    std::cout << "\n";
  }
}

void rightStarTriangle() {
  int i, j, n;
  std::cout << "Enter number of rows: ";
  std::cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}

void rightNumberTriangle() {
  int choice, i, j, n;
  std::cout << "\n--- Number Right Triangle Options ---\n";
  std::cout << "1. Row-wise numbers\n";
  std::cout << "2. Column-wise numbers\n";
  std::cout << "Enter your choice (1-2): ";
  std::cin >> choice;
  std::cout << "Enter number of rows: ";
  std::cin >> n;
  if (choice == 1) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= i; j++) {
        std::cout << j;
      }
      std::cout << "\n";
    }
  } else if (choice == 2) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= i; j++) {
        std::cout << i;
      }
      std::cout << "\n";
    }
  } else {
    std::cout << "Invalid number triangle choice.\n";
  }
}

void rightAlphabetTriangle() {
  int i, j, n;
  std::cout << "Enter number of rows: ";
  std::cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      std::cout << static_cast<char>(j + 64);
    }
    std::cout << "\n";
  }
}

void righttriangle() {
  char again;
  do {
    int choice;
    std::cout << "\n--- Right Triangle Pattern Options ---\n";
    std::cout << "1. Star right triangle\n";
    std::cout << "2. Number right triangle\n";
    std::cout << "3. Alphabet right triangle\n";
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      rightStarTriangle();
      break;
    case 2:
      rightNumberTriangle();
      break;
    case 3:
      rightAlphabetTriangle();
      break;
    default:
      std::cout << "Invalid choice.\n";
    }
    std::cout << "Do you want to repeat this pattern (y/n)? ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');
}

void triangle() {
  char again;
  do {
    int choice;
    std::cout << "\n--- Triangle Pattern Options ---\n";
    std::cout << "1. Isosceles triangle (centered star)\n";
    std::cout << "2. Right triangle (number/alphabet)\n";
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      isoscelesTriangle();
      break;
    case 2:
      righttriangle();
      break;
    default:
      std::cout << "Invalid choice.\n";
    }
    std::cout << "Do you want to repeat this pattern (y/n)? ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');
}
