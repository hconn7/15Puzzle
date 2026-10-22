#include "board.hpp"
#include "input.hpp"
#include "point.hpp"
#include <iostream>
int main() {

  Board b{};
  Board w{};
  char input{};
  b.randomize();
  std::cout << b;
  while (true) {

    std::cin >> input;
    std::cin.clear();
    if (!std::cin) {
      std::cin.ignore();
      std::cin.clear();
    }
    if (input == 'w' || input == 'a' || input == 's' || input == 'd') {

      Direction direction{Direction::charToDir(input)};

      b.moveTile(direction);
      std::cout << "\n\n\n";
      std::cout << b;

      if (b == w) {
        "You win!";
      }
    } else if (input == 'q') {
      std::cout << '\n' << "Bye!" << '\n';
      break;
    }
    continue;
  }
  return 0;
}
