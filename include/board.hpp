#pragma once

#include "tile.hpp"
#include <iostream>
#include <ostream>
#include <vector>

static const int rows{4};
static const int cols{4};

class Board {
public:
  Board()
      : m_board{rows, std::vector<int>(cols)}

  {
    for (int i{0}; i < rows; ++i) {
      for (int j{0}; j < cols; ++j) {
        m_board[i][j] = j;
      }
    }
  }

  void initBoard(Board& board) {
    for (int i{0}; i < rows; ++i) {
      for (int j{0}; j < cols; ++j) {
        board[i][j] = j;
      }
    }
  }

  friend std::ostream& operator<<(std::ostream& out, Board& board);
  const std::vector<int>& operator[](int val) const { return m_board[val]; }

  std::vector<int>& operator[](int val) { return m_board[val]; }
  Board& operator=(Board& board);

private:
  std::vector<std::vector<int>> m_board;
};
