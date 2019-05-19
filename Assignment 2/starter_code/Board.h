
#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Player.h"
#include "Tile.h"
class Board {
  public:
    Board(const int row, const int col);
    bool move(int row, int col, Tile& piece, Player& player);



  private:
    const int row;
    const int col;
    Tile& piece;
    Player& player;

};


#endif // ASSIGN2_BOARD_H
