#include "Bag.h"
#include <iostream>

Bag::Bag() {
  this->size=0;

  Colour colours = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
  Shape shapes = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER };

  for(Colour colour: colours){
    for(Shape shape: shapes){

      //each tile exists twice in the Bag
      this->tiles->addBack(new Tile(colour, shape));
      this->tiles->addBack(new Tile(colour, shape));
      this->size+=2;
    }
  }



}

Bag::takeTile(){
  this->size--;

  //get the tile at the start of the linked list
  Tile tile = this->tiles->get(0);

  //then removes the tile at the start of the list
  this->tiles->removeFront();


  return tile;
}

Bag::size() {
  return this->size;
}

Bag::shuffle(){

}
