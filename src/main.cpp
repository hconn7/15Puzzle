#include "board.hpp"
#include "input.hpp"
#include <iostream>
int main() {
  Board b{};

  std::cout << b << '\n';

  UserInput::handleInput();
}
