
#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "LinkedList.h"
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
    void listHand();
    int getHandSize();
    void fillHand();
    

}




#endif // ASSIGN2_PLAYER_H
