#pragma once

#include "direction.hpp"
#include "point.hpp"
#include "random.hpp"
#include "tile.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>
#include <utility>
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
  static Direction getRandomDirection() {
    Direction::EnumDirection random{static_cast<Direction::EnumDirection>(
        Random::get(0, Direction::EnumDirection::max_directions - 1))};
    return Direction{random};
  }
  void initBoard(Board& board) {
    for (int y{0}; y < rows; ++y) {
      for (int x{0}; x < cols; ++x) {
        board[y][x] = Tile(x);
      }
    }
  }

  Point locateEmptyTile() {
    for (int y{0}; y < rows; ++y) {
      for (int x{0}; x < cols; ++x) {
        if (m_board[y][x].isEmpty()) {
          return Point{x, y};
        }
      }
    }

    std::cout << "Empty tile not found";
    return Point(-1, -1);
  }

  bool isValid(Direction::EnumDirection d) {
    if (d + 1 >= 5 || d - 1 <= 0) {
      return false;
    }
    return true;
  }
  void swapTile(Point p1, Point p2) {

    std::swap(m_board[p1.getPointY()][p1.getPointX()],
              m_board[p2.getPointY()][p2.getPointX()]);
  }

  bool moveTile(Direction d) {

    Point empty{locateEmptyTile()};
    Point adj{empty.getAdjacentPoint(-d)};

    if (adj.getPointX() >= 4 || adj.getPointX() < 0 || adj.getPointY() >= 4 ||
        adj.getPointY() < 0) {
      return false;
    }

    swapTile(empty, adj);
    return true;
  }

  friend std::ostream& operator<<(std::ostream& out, Board& board);

  const std::vector<Tile>& operator[](int val) const { return m_board[val]; }
  std::vector<Tile>& operator[](int val) { return m_board[val]; }

  Board& operator=(Board& board);

  void randomize() {
    for (int i{0}; i < 1000;) {
      if (moveTile(getRandomDirection())) {
        ++i;
      }
    }
  }

  bool operator==(Board b2) {
    for (int y{0}; y < cols; ++y) {
      for (int x{0}; x < rows; ++x) {
        if (m_board[y][x].m_value == b2.m_board[y][x].m_value)
          return true;
      }
    }
    return false;
  }

private:
  std::vector<std::vector<Tile>> m_board;
};
