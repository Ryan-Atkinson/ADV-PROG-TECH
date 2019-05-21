#include <iostream>
#include <string>
#include "Player.h"
#include "Bag.h"
#include "LinkedList.h"


Player::Player(std::string name) {
  this->name = name;
  score = 0;

}

//returns the player's score
int Player::getScore() {
  return score;
}

std::string Player::getName(){
  return name;
}

void Player::setScore(int i) {
  score=i;
}

//adds points to the player's score
void Player::addPoints(int i) {
  score+=i;
}

//subtracts points from the player's score
void Player::subtractPoints(int i) {
  score-=i;
}

LinkedList* Player::getHand() {
  return hand;
}

int Player::getHandSize() {
  return hand->size();
}

void Player::removeTile(Tile i) {
  if(hand->size()!=0) {
    if(hand->contains( i)){
      hand->deleteData(i);
    }
    else {
      std::cout << "Error: Hand does not contain tile" << std::endl;
    }
  }
  else {
    std::cout << "Error: Hand is empty" << std::endl;
  }
}

void Player::drawTile(Bag* bag) {
  while (hand->size()<5 && bag->size()>0) {
    hand->addBack(bag->takeTile());
  }
}

bool Player::hasTile(Tile t) {
  return hand->contains(t);
}

void Player::setHand(LinkedList* list){
  this->hand=list;
}
