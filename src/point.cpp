#include "point.hpp"
#include "board.hpp"
#include "direction.hpp"

std::ostream& operator<<(std::ostream& out, Point& point) {
  return out << point.m_x << point.m_y;
}
