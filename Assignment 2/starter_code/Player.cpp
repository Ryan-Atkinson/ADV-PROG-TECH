#include <iostream>
#include <string>
#include "Player.h"
#include "Bag.h"
#include "LinkedList.h"

//constructor
Player::Player(string name) {
  name = name;
  score = 0;

}

//returns the player's score
int Player::getScore() {
  return score;
}

//sets the player's score to a specified number
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

//returns the player's hand
LinkedList<Tile> Player::getHand() {
  return hand;
}

//returns the size of the player's hand
int Player::getHandSize() {
  return hand->size();
}

//removes a specified tile from the player's hand
void Player::removeTile(Tile i) {
  if(hand->size()!=0) {
    if(hand->contains(Tile i)){
      hand->deleteAt(Tile i);
    }
    else {
      std::cout << "Error: Hand does not contain tile" << std::endl;
    }
  }
  else {
    std::cout << "Error: Hand is empty" << std::endl;
  }
}

//draws tiles from the bag until the player's hand is full
void Player::drawTiles(Bag& bag) {
  while (hand->size()<5 && bag->size()>0) {
    hand->addBack(bag->takeTile());
  }
}

//boolean to check if the player has a specified tile in their hand
bool Player::hasTile(Tile t) {
  if (hand->contains(t)) {
    return true;
  }
  else {
    return false;
  }
}
