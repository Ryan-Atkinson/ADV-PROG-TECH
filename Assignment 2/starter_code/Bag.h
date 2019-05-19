#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAH_H

#include "Tile.h"
#include "LinkedList.h"

class Bag {
  private:
    LinkedList* tiles;
    int bagSize;



  public:
    Bag();
    void shuffle();
    int size();
    Tile* takeTile();
    void createBag();


};



#endif // ASSIGN2_BAG_H
