
#include "TileCodes.h"
#include "Bag.h"


#include <iostream>
#include <string>
#include <random>

Bag::Bag() {
  this->tiles=new LinkedList();

  // createBag();

}

Tile* Bag::takeTile(){
  if(this->bagSize==0){
    createBag();
  }
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
  int max = this->bagSize-1;
  std::random_device engine;
  std::uniform_int_distribution<int> uniform_dist(min, max);
  //std::cout<< "shuffle"<<std::endl;

  //printBag();
  //shuffles the bag for the size of bag times 2, to ensure that the bag is completely shuffled
  for(int i =0; i<(this->bagSize*2); i++) {

    int index=uniform_dist(engine);
    //std::cout<< "for index "<< i<< std::endl;
  //  std::cout<<"Index to be shuffled: "<< index<< std::endl;


    //gets a random tile from the bag
    Tile* tile = this->tiles->get(index);
  //  std::cout<<"get works "<< index<< std::endl;
    //deletes the tile from the bag
    this->tiles->deleteAt(index);
    //std::cout<<"delete at works "<< index<< std::endl;
    //then adds the tile at the add of the bag
    this->tiles->addBack(tile);
  //  std::cout<<"add back works "<< index<< std::endl;

  }
  //printBag();
//  std::cout << "shuffled"<< std::endl;

}


void Bag::createBag(){

  this->bagSize=0;

  // defines all the possible colours and shapes, that a tile can have
  Colour colours [6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
  Shape shapes [6] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER };

  // a nested foor loop pairs up each shape and colour combination
  std::cout<<"Tile Bag"<<std::endl;
  for(Colour colour: colours){
    for(Shape shape: shapes){
      //std::cout<<"s"<< std::endl;

      //each tile exists twice in the Bag
      this->tiles->addBack(new Tile(colour, shape));
      this->tiles->addBack(new Tile(colour, shape));
      this->bagSize+=2;
      //std::cout << "Colour: "<< colour << "Shape: "<< shape<< std::endl;
    }
  }



  std::cout<< "Bag Size: "<< this->bagSize<<std::endl;

}



void Bag::printBag(){
  int index=0;
  while(index<this->bagSize){
    Tile* tile = this->tiles->get(index);
    std::cout <<" Index: " << index<< " Colour: "<< tile->colour<< " Shape: "<< tile->shape<<std::endl;
    index++;
  }


}
