
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList{

public:

  int size();
  void clear();
  int get(int i);

  void addFront(Tile data);
  void addBack(Tile data);

  void deleteFront();
  void deleteBack();

  void addAt(int i, Tile data);
  void deleteAt(int i);
  LinkedList();
  ~LinkedList();



private:
  Node* head;
  int size;

}

#endif // ASSIGN2_LINKEDLIST_H
