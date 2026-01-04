#include "alphabet.h"
#include <iostream>

void alphar() {
  int i, j, n;
  std::cout << "Enter number of sides for a square (alphabet pattern): ";
  std::cin >> n;
  std::cout << "\nHere is your alphabet square (row-wise):\n\n";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      std::cout << static_cast<char>(j +
                                     64); // use static_cast to print character
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void alphac() {
  int i, j, n;
  std::cout << "Enter number of sides for a square (alphabet pattern): ";
  std::cin >> n;
  std::cout << "\nHere is your alphabet square (column-wise):\n\n";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      std::cout << static_cast<char>(i +
                                     64); // use static_cast to print character
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void alpha() {
  char again;
  do {
    int choice;
    std::cout << "\n--- Alphabet Pattern Options ---\n";
    std::cout << "1. Alphabet square (row-wise)\n";
    std::cout << "2. Alphabet square (column-wise)\n";
    std::cout << "Enter your choice (1-2): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      alphar();
      break;
    case 2:
      alphac();
      break;
    default:
      std::cout << "Invalid choice.\n";
    }
    std::cout << "Do you want to repeat this pattern (y/n)? ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');
}
