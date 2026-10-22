#include "direction.hpp"
#include <ostream>
#include <string_view>

std::ostream& operator<<(std::ostream& out, Direction& dir) {
  Direction direction{dir.getDirection()};
  std::string_view str{dir.directionToString(direction)};

  return out << str;
}

std::string_view Direction::directionToString(Direction d) {
  switch (d.getDirection()) {
  case 0:
    return "up";
  case 1:
    return "left";
  case 2:
    return "down";
  case 3:
    return "right";
  dedefault:
    Direction::EnumDirection{max_directions};
    break;
  }
}

Direction::EnumDirection Direction::charToDir(char c) {
  switch (c) {
  case 'w':
    return Direction::EnumDirection{up};
  case 's':
    return Direction::EnumDirection{down};
  case 'a':
    return Direction::EnumDirection{left};
  case 'd':
    return Direction::EnumDirection{right};
  dedefault:
    Direction::EnumDirection{max_directions};
    break;
  }
  return Direction::EnumDirection{max_directions};
}
