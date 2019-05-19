
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include <string>
#include "Bag.h"

class Player {
  private:
    string name;
    int score;
    LinkedList<Tile> hand;
  public:
    Player();
    int getScore();
    void setScore(int);
    void addPoints(int);
    void subtractPoints(int);
    LinkedList<Tile> getHand();
    int getHandSize();
    void drawTiles();


}




#endif // ASSIGN2_PLAYER_H
