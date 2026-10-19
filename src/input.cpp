
#include "input.hpp"
#include "direction.hpp"
#include <cstdlib>
#include <iostream>

namespace UserInput {

char input{};

void handleInput() {

  char input{};
  while (true) {
    std::cin >> input;
    std::cin.clear();
    if (!std::cin) {
      std::cin.ignore();
      std::cin.clear();
    }
    if (input == 'w' || input == 'a' || input == 's' || input == 'd') {

      std::cout << "Valid command: " << input << std::endl;

      int direction{Direction::charToEnumDir(input)};

      Direction dir{input};
      std::cout << "You moved: " << dir.directionToString(direction)
                << std::endl;
      std::cout << dir << "should be switched now: " << -dir;

    } else if (input == 'q') {
      std::cout << '\n' << "Bye!" << '\n';
      break;
    }
    continue;
  }
}
}; // namespace UserInput
