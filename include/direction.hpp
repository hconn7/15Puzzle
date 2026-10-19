
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

  static constexpr std::array<int, Direction::max_directions> asciiVal{
      ASCiiVal::w, ASCiiVal::a, ASCiiVal::s, ASCiiVal::d, ASCiiVal::q};
  static constexpr std::array<int, Direction::max_directions> enumVal{0, 1, 2,
                                                                      3, 4};
  static_assert(asciiVal.size() == Direction::max_directions);
  static_assert(enumVal.size() == Direction::max_directions);

  explicit Direction(char intDirection)
      : m_direction{charToEnumDir(intDirection)} {}

  // Function n stuff
  friend std::ostream& operator<<(std::ostream& out, Direction& dir);

  EnumDirection& operator-() {
    switch (m_direction) {
    case up:
      return m_direction = down;
    case left:
      return m_direction = right;
    case down:
      return m_direction = up;
    case right:
      return m_direction = left;

    default:
      std::cout << "failed to switch via - op";
    }
    return m_direction = static_cast<EnumDirection>(6);
  }

  static EnumDirection charToEnumDir(char c);

  EnumDirection getDirection() const { return m_direction; }

  int getAsciiIdx(int c);

  std::string_view directionToString(int c);

private:
  EnumDirection m_direction;
};
