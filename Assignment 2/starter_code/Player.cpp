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

void Player::getHand() {
  return hand;
}

void Player::drawTile(Bag& Bag) {
  if(getHandSize()<5) {
    Tile i = this->Bag.getTile();
    this->hand.addBack(i);
  }
  else {
    return 0;
  }
}

void Player::removeTile() {
  if(this->hand.!empty) {

  }

}

void Player::fullHand() {

}

bool Player::hasTile(Tile t) {
}
