#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include "Tile.h"
#include "LinkedList.h"


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


  bool replaceTile(std::string tile);
  bool addTileToBoard(std::string tile);
  bool hasGameEnded();
  std::string getCurrentPlayer();
  

};



#endif // ASSIGN2_GAME_H
