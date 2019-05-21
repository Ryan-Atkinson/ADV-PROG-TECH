#ifndef ASSIGN2_GAMEPLAY_H
#define ASSIGN2_GAMEPLAY_H

#include "Tile.h"
#include "LinkedList.h"
//#include "Bag.h"
#include "Board.h"
#include "Player.h"


class Game{
  private:
    Bag* tileBag;
    Player* player1;
    Player* player2;
    Board* board;
    std::string currentPlayer;



public:
  Game(Player* player1, Player* player2);

  //this is for loading in the game
  Game(Player* player1, Player* player2, Bag* bag, Board* board);
  ~Game();

  Board* getBoard();
  Player* getPlayer1();
  Player* getPlayer2();
  Bag* getTileBag();
  bool replaceTile(std::string tile);
  bool addTileToBoard(std::string tile, int tileRow, int tileCol);
  bool hasGameEnded();
  void changeCurrentPlayer();
  int findScore(int numNorth, int numSouth, int numEast, int numWest);
  void hangeCurrentPlayer();
  Player* getCurrentPlayer();
  int numOfTiles(int tileRow, int tileCol, int direction);


};



#endif // ASSIGN2_GAMEPLAY_H
