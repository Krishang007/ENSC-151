#include "menu.h"
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include <iostream>

void menu() {
  int choice;
  do {
    std::cout << "\n====================\n";
    std::cout << "--- MAIN MENU ---\n";
    std::cout << "====================\n";
    std::cout << "1. Triangle patterns\n";
    std::cout << "2. Square patterns\n";
    std::cout << "3. Rectangle patterns\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      triangle();
      break;
    case 2:
      square();
      break;
    case 3:
      rectanglePattern();
      break;
    case 4:
      std::cout << "Exiting program...\n";
      break;
    default:
      std::cout << "Invalid choice. Please enter 1 to 4.\n";
    }
  } while (choice != 4);
}
