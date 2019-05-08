
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <LinkedList>
#include <string>
#include "Bag.h"

class Player {
  private:
    string playerName;
    int points;
    LinkedList<char> hand;
  public:
    Player();
    int getPoints();
    int setPoints(int);
    int getHand();
    void showHand();
}




#endif // ASSIGN2_PLAYER_H
