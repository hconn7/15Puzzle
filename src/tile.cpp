#include "tile.hpp"

std::ostream& operator<<(std::ostream& out, const Tile& tile) {
  if (tile.getNum() == 0) {
    out << "    ";
  } else if (tile.getNum() >= 10) {
    out << " " << tile.m_value << " ";
    return out;
  } else if (tile.getNum() < 10 && tile.getNum() > 0) {
    out << "  " << tile.m_value << " ";
    return out;
  }
  return out;
}
