#pragma once

#include <cassert>
#include <ostream>

class Board;
class Tile {

public:
  Tile(int value, bool empty = false) : m_value{value}, m_isEmpty{empty} {
    assert(value > 0 || value < 15 && "Incorrect value");
    if (value == 0) {
      m_isEmpty = true;
    }
  }
  friend class Board;
  bool isEmpty() { return m_isEmpty; }

  int getNum() const { return m_value; }

  friend std::ostream& operator<<(std::ostream& out, const Tile& tile);

private:
  int m_value;
  bool m_isEmpty;
};
