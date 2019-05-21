#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include "Tile.h"


class Board {
  public:
    Board(int row, int col);
    ~Board();
    bool add(int row, int col, Tile* piece);
    void printBoard();

    //for loading the board
    void setBoard(Tile*** board);




  private:

    const int row;
    const int col;
    Tile*** board;
    // Tile& piece;
    // Player& player;

};



#endif // ASSIGN2_BOARD_H
