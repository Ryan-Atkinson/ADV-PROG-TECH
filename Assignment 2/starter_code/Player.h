#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include "LinkedList.h"
#include <string>


class Player {
  private:
    std::string playerName;
    int points;
    LinkedList* hand;
  public:
    Player(std::string playerName);
    ~Player();


    int getPoints();

    //sets the total points
    void setPoints(int points);

    // adds to the current points and then returns the total points
    int addPoints(int points);

    //gets current size of hand
    int getHandSize();

    //gets a linked list of the current hand
    LinkedList* getHand();

    //prints a list of the current hand
    void listHand();

    //adds a tile to hand
    void addTile(Tile* tile);

    // removes a tile for the hand by index of the tile in the linked list
    void removeTile(int index);

};




#endif // ASSIGN2_PLAYER_H
