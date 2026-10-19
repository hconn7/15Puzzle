#pragma once

#include "tile.hpp"
#include <iostream>
#include <ostream>
#include <vector>

static const int rows{4};
static const int cols{4};

class Board {
public:
  explicit Board()
      : m_board{rows, std::vector<Tile>(cols)}

  {
    int count{1};
    for (int i{0}; i < rows; ++i) {
      for (int j{0}; j < cols; ++j) {
        if (count == 16) {
          count = 0;
        }
        m_board[i][j] = Tile{count};
        ++count;
      }
    }
  }

  void initBoard(Board& board) {
    for (int i{0}; i < rows; ++i) {
      for (int j{0}; j < cols; ++j) {
        board[i][j] = Tile(j);
      }
    }
  }

  friend std::ostream& operator<<(std::ostream& out, Board& board);

  const std::vector<Tile>& operator[](int val) const { return m_board[val]; }
  std::vector<Tile>& operator[](int val) { return m_board[val]; }

  Board& operator=(Board& board);

private:
  std::vector<std::vector<Tile>> m_board;
};
