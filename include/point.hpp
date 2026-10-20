#pragma once

#include "board.hpp"
#include "direction.hpp"
#include <ostream>
#include <random>
class Point {
public:
  Point(int x, int y) : m_x{x}, m_y{y} {}

  Point getAdjacentPoint(Direction::EnumDirection d) {
    Point adjacent{*this};
    switch (d) {
    case Direction::up:
      adjacent.m_y -= 1;
      break;
    case Direction::down:
      adjacent.m_y += 1;
      break;
    case Direction::left:
      adjacent.m_x -= 1;
      break;
    case Direction::right:
      adjacent.m_x += 1;
      break;
    default:
      break;
    }
    std::cout << adjacent << ": adjacent!";
    return adjacent;
  };
  bool operator==(Point p2) const { return m_x == p2.m_x && m_y == p2.m_y; }

  friend std::ostream& operator<<(std::ostream& out, Point& point);

private:
  int m_x;
  int m_y;
};
