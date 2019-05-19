

#include "Bag.h"
#include "TileCodes.h"

#include <iostream>
#include <string>
#include <random>

Bag::Bag() {

  createBag();

}

Tile* Bag::takeTile(){
  this->bagSize--;

  //get the tile at the start of the linked list
  Tile* tile = this->tiles->get(0);

  //then removes the tile at the start of the list
  this->tiles->deleteFront();


  return tile;
}

int Bag::size() {
  return this->bagSize;
}

void Bag::shuffle(){

  int min =0;
  int max = this->bagSize;
  std::random_device engine;
  std::uniform_int_distribution<int> uniform_dist(min, max);

  //shuffles the bag for the size of bag times 2, to ensure that the bag is completely shuffled
  for(int i =0; i<this->bagSize*2; i++) {
    int index=uniform_dist(engine);

    //gets a random tile from the bag
    Tile* tile = this->tiles->get(index);

    //deletes the tile from the bag
    this->tiles->deleteAt(index);

    //then adds the tile at the add of the bag
    this->tiles->addBack(tile);
  }


}


void Bag::createBag(){

  this->bagSize=0;

  // defines all the possible colours and shapes, that a tile can have
  Colour colours [6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
  Shape shapes [6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER };

  // a nested foor loop pairs up each shape and colour combination
  for(Colour colour: colours){
    for(Shape shape: shapes){

      //each tile exists twice in the Bag
      this->tiles->addBack(new Tile(colour, shape));
      this->tiles->addBack(new Tile(colour, shape));
      this->bagSize+=2;
    }
  }

}
