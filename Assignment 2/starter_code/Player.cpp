#include <iostream>
#include <string>
#include "Player.h"
#include "LinkedList.h"

Player::Player(string name) {
  name = name;
  score = 0;

}

int Player::getScore() {
  return score;
}

void Player::setScore(int i) {
  score=i;
}

void Player::addPoints(int i) {
  score+=i;
}

void Player::subtractPoints(int i) {
  score-=i;
}

LinkedList<Tile> Player::getHand() {
  return hand;
}

int Player::getHandSize() {
  return hand->size();
}

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

void Player::drawTiles(Bag& bag) {
  while (hand.size()<5 && bag.size()>0) {
    hand.addBack(bag.takeTile());
  }
}

bool Player::hasTile(Tile t) {
  if (hand.getTile)
}
