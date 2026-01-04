#include "square.h"
#include "alphabet.h"
#include "number.h"
#include <iostream>

void starSquare() {
  char again;
  do {
    int i, j, n;
    std::cout << "Enter the number of rows and columns for the square: ";
    std::cin >> n;
    std::cout << "\nHere is your star square:\n\n";
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        std::cout << "*";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "Do you want to repeat this pattern (y/n)? ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');
}

void square() {
  char again;
  do {
    int choice;
    std::cout << "\n--- Square Pattern Options ---\n";
    std::cout << "1. Star square\n";
    std::cout << "2. Number square\n";
    std::cout << "3. Alphabet square\n";
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      starSquare();
      break;
    case 2:
      num();
      break;
    case 3:
      alpha();
      break;
    default:
      std::cout << "Invalid choice.\n";
    }

    std::cout << "Do you want to repeat this pattern category (y/n)? ";
    std::cin >> again;
  } while (again == 'y' || again == 'Y');
}
