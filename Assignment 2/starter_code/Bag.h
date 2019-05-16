#ifndef ASSIGN2_BAG_H
#define ASSIGN2_BAH_H

class Bag {
  private:
    LinkedList* tiles;
    int size;



  public:
    Bag();
    void shuffle();
    int size();
    Tile takeTile();
    void createBag();


}



#endif // ASSIGN2_BAG_H
