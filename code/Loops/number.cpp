#include "number.h"
#include <iostream>

void numRow() {
  int i, j, n;
  std::cout << "Enter number of sides for a square (row-wise): ";
  std::cin >> n;
  std::cout << "\nHere is your number square (row-wise):\n\n";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      std::cout << j;
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void numCol() {
  int i, j, n;
  std::cout << "Enter number of sides for a square (column-wise): ";
  std::cin >> n;
  std::cout << "\nHere is your number square (column-wise):\n\n";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      std::cout << i;
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void num() {
  char again;
  do {
    int choice;
    std::cout << "\n--- Number Pattern Options ---\n";
    std::cout << "1. Number square (row-wise)\n";
    std::cout << "2. Number square (column-wise)\n";
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      numRow();
      break;
    case 2:
      numCol();
      break;
    default:
      std::cout << "Invalid choice.\n";
    }
    std::cout << "Do you want to repeat this pattern (y/n)? ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');
}
