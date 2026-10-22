#pragma once

#include "direction.hpp"
#include <ostream>
#include <random>
class Point {
public:
  Point(int x, int y) : m_x{x}, m_y{y} {}

  Point getAdjacentPoint(Direction d) {
    Point adjacent{*this};
    switch (d.getDirection()) {
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
    return adjacent;
  };

  int getPointX() { return m_x; }
  int getPointY() { return m_y; }
  bool operator==(Point p2) const { return m_x == p2.m_x && m_y == p2.m_y; }

  friend std::ostream& operator<<(std::ostream& out, Point& point);

private:
  int m_x;
  int m_y;
};
