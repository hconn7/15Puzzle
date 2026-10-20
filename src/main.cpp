#include "board.hpp"
#include "input.hpp"
#include "point.hpp"
#include <iostream>
int main() {
  // Your code goes here

  // Note: save your main() from the prior step, as you'll need it again in the
  // next step

  // Note: save your main() from the prior step, as you'll need it
  // again in the next step
  std::cout << std::boolalpha;
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::up) == Point{1, 0})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::down) == Point{1, 2})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::left) == Point{0, 1})
            << '\n';
  std::cout << (Point{1, 1}.getAdjacentPoint(Direction::right) == Point{2, 1})
            << '\n';
  std::cout << (Point{1, 1} != Point{2, 1}) << '\n';
  std::cout << (Point{1, 1} != Point{1, 2}) << '\n';
  std::cout << !(Point{1, 1} != Point{1, 1}) << '\n';

  UserInput::handleInput();
  return 0;
}
