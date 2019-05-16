#include "Bag.h"
#include <iostream>

Bag::Bag() {

  createBag();

}

Bag::takeTile(){
  this->size--;

  //get the tile at the start of the linked list
  Tile tile = this->tiles->get(0);

  //then removes the tile at the start of the list
  this->tiles->deleteFront();


  return tile;
}

Bag::size() {
  return this->size;
}

Bag::shuffle(){

  int min =0;
  int max = this->size;
  std::random_device engine;
  std::uniform_int_distribution<int> uniform_dist(min, max);


  for(int i =0; i<this->size*2; i++) {
    int index=uniform_dist(engine);
    Tile tile = this->tiles->get(index);
    this->tiles->deleteAt(index);
    this->tiles->addBack(tile);
  }


}

Bag::createBag(){

  this->size=0;

  Colour colours [6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
  Shape shapes [6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER };

  for(Colour colour: colours){
    for(Shape shape: shapes){

      //each tile exists twice in the Bag
      this->tiles->addBack(new Tile(colour, shape));
      this->tiles->addBack(new Tile(colour, shape));
      this->size+=2;
    }
  }

}
