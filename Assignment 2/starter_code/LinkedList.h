
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   void clear();
   int get(int i);
   bool contains();

   void addFront(Tile* tile);
   void addBack(Tile* tile);

   void deleteFront();
   void deleteBack();

   void deleteAt(Tile* tile);


private:
   Node* head;
};

#endif // ASSIGN2_LINKEDLIST_H
