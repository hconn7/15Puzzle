#include "board.hpp"
#include <ostream>

std::ostream& operator<<(std::ostream& out, Board& board) {
  for (int i{0}; i < rows; ++i) {
    for (int j{0}; j < rows; ++j) {
      out << board[i][j];
    }
    out << std::endl;
  }
  return out;
}
