
#pragma once

#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <string_view>

namespace ASCiiVal {
constexpr int w = 119;
constexpr int a = 97;
constexpr int s = 115;
constexpr int d = 100;
constexpr int q = 113;

} // namespace ASCiiVal

class Direction {
public:
  enum EnumDirection { up, left, down, right, quit, max_directions };

  explicit Direction(EnumDirection intDirection) : m_direction{intDirection} {}

  // Function n stuff
  friend std::ostream& operator<<(std::ostream& out, Direction& dir);

  Direction operator-() {
    switch (m_direction) {
    case up:
      return Direction{down};
    case left:
      return Direction{right};
    case down:
      return Direction{up};
    case right:
      return Direction{left};

    default:
      break;
    }
    return Direction{max_directions};
  }

  static EnumDirection charToDir(char c);

  EnumDirection getDirection() const { return m_direction; }

  int getAsciiIdx(int c);

  std::string_view directionToString(Direction d);

private:
  EnumDirection m_direction;
};
