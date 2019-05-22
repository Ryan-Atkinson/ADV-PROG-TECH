#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

//#include "Bag.h"
#include "Tile.h"
#include "LinkedList.h"
#include <string>



class Player {
  private:
    std::string name;
    int score;
    LinkedList* hand;
  public:
    Player(std::string name);
    ~Player();

    std::string getName();

    // returns the current score
    int getScore();

    // sets the total score
    void setScore(int i);

    // adds to the current points
    void addPoints(int i);

    // subtracts from the current points
    void subtractPoints(int i);

    // gets current size of hand
    int getHandSize();

    // gets a linked list of the current hand
    LinkedList* getHand();

    // prints a list of the current hand
    void printHand();

    // adds a tile to hand
    void drawTile(Bag* bag);

    // removes a tile for the hand by index of the tile in the linked list
    void removeTile(Tile* i);

    // returns boolean
    bool hasTile(Tile* i);

    //this is used when loading a file to set the hand
    void setHand(LinkedList* list);

};




#endif // ASSIGN2_PLAYER_H
