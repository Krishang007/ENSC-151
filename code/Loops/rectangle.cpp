#include "rectangle.h"
#include <iostream>

void rectanglePattern() {
  char again;
  int i, j, x, y;
  do {
    do {
      std::cout << "Enter number of rows: ";
      std::cin >> x;
      std::cout << "Enter number of columns: ";
      std::cin >> y;
      if (x <= 0 || y <= 0) {
        std::cout << "Invalid input. Please re-enter.\n";
      }
    } while (x <= 0 || y <= 0);

    std::cout << "\nHere is your rectangle:\n\n";
    // using nested for loops make quadrilateral
    for (i = 1; i <= x; i++) {
      for (j = 1; j <= y; j++) {
        std::cout << "* ";
      }
      std::cout << "\n";
    }

    std::cout << "\nDo you want to create another quadrilateral (y/n): ";
    std::cin >> again;
    std::cout << "\n";
  } while (again == 'y' || again == 'Y');

  if (again == 'n' || again == 'N') {
    std::cout << "\n";
  }
}
