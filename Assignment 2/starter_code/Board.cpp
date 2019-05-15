
#include "Board.h"
#include "Node.h"
#include <iostream>

Board::Board() {
  for (int row = 0; row < 5; row++) {
    for (int column = 0; column < 5; column++) {
      array[row][column] = newNode;
    }
  }
  turn = 0;
}

bool Board::move(int row, int column, Tile& piece, Player& player) {
  if (array[row][column] == '  ') {
    array[row][column] = piece;


  }
}
