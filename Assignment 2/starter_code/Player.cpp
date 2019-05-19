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

int Player::getHandSize() {
  return hand.size();
}

void Player::drawTile(Bag& Bag) {
    Tile i = this->Bag.takeTile();
    this->hand.addBack(i);
}

void Player::removeTile() {
  if(this->hand.!empty) {

  }

}

void Player::fullHand() {

}

bool Player::hasTile(Tile t) {
}
