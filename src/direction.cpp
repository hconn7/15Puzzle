#include "direction.hpp"
#include <ostream>
#include <string_view>

std::ostream& operator<<(std::ostream& out, Direction& dir) {
  Direction::EnumDirection direction{dir.getDirection()};
  std::string_view str{dir.directionToString(direction)};

  return out << str;
}

std::string_view Direction::directionToString(int c) {
  if (c < 0) {
    c = (c * -1);
  }
  static constexpr std::array<std::string_view, Direction::max_directions>
      dirStr{"up", "left", "down", "right", "quit"};
  int idx{getAsciiIdx(c)};

  if (idx == 6 || idx >= Direction::max_directions) {
    return "Unknown";
  }

  return dirStr[idx];
}
Direction::EnumDirection Direction::charToEnumDir(char c) {
  for (int i{0}; i < Direction::max_directions; ++i) {
    if (Direction::asciiVal[i] == c) {
      return static_cast<Direction::EnumDirection>(i);
    }
  }
  return static_cast<Direction::EnumDirection>(6);
}

int Direction::getAsciiIdx(int c) {
  for (int i{0}; i < Direction::max_directions; ++i) {
    if (Direction::enumVal[i] == c) {
      return static_cast<int>(i);
    }
  }
  return -1;
}
