#include <iostream>
#include "Player.h"

Player::Player(std::string playerName) {
  this->playerName = playerName;
  this->points = 0;
  this->hand= new LinkedList();
}


Player::~Player(){
  delete this->hand;

}


int Player::getPoints(){
  return this->points;

}

//sets the total points
void Player::setPoints(int points){
  this->points =points;
}

// adds to the current points and then returns the total points
int Player::addPoints(int points){
  this->points+=points;
  return this->points;
}

//gets current size of hand
int Player::getHandSize(){
    return hand->size();
}

//gets a linked list of the current hand
LinkedList* Player::getHand(){
  return hand;
}

//prints a list of the current hand
void Player::listHand(){
  int index=0;
  while(index<this->hand->size()){
    Tile* tile = this->hand->get(index);
    std::cout <<tile->colour<< ", "<< tile->shape<< " ";
    index++;
  }
  std::cout<<std::endl;
}

//adds a tile to hand
void Player::addTile(Tile* tile){
  this->hand->addBack(tile);
}

// removes a tile for the hand
void Player::removeTile(int index){
  this->hand->deleteAt(index);

}
