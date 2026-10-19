#pragma once

#include <cassert>
#include <ostream>

class Board;
class Tile {

public:
  explicit Tile() : Tile{0, false} {}
  explicit Tile(int value, bool empty = false)
      : m_value{value}, m_isEmpty{empty} {
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
