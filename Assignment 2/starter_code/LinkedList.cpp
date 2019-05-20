
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
}

int LinkedList::size()
{
  //assign counter to 0
  int counter =0;
  //create node and point to the head which points to nullptr
  Node* node = head;
  //a while loop to check if note is not equal to nullptr
  while(node!=nullptr)
  {
    //iterating through the nodes with a counter from 0
    ++counter;
    //assign node to the next node
    node = node->next;
  }
  //returns counter which is the number of elements in the LinkedList
  return counter;
}

void LinkedList::clear()
{
  //creating the node and pointing it to the head
  Node* node = head;

  //a while loop to test if node is not pointing to nullptr
  while(node!=nullptr)
  {
    //save the node pointing to the next
    Node* saveNode = node->next;
    //delete the node
    delete node;
    //node is equal to saveNode
    node = saveNode;
  }
  //after deleting the node the head will need to point to nullptr
  head = nullptr;
}

int LinkedList::get(int i)
{
  //create a node pointing to the head
  Node* node = this->head;
  //a for loop to iterate through the elements of linkedlist
  for (int count=1; count <=i; ++count)
  {
  //assigns node to the next node
     node =node->next;
   }
   //returns the node pointing to the data of the linkedlist in a position i
   return node->tile;
  return i;
}

bool LinkedList::contains(Node* head, Tile* t) {
  Node* current = head;
  while(current !=NULL) {
    if(current->tile==t) {
      return true;
      current = current->next
    }
  }

void LinkedList::addFront(Tile* tile){
  Node* newNode = new Node(tile, this->head);
  this->head = newNode;
}

void LinkedList::addBack(Tile* tile){
  Node* newNode = new Node(tile, this->head);
  newNode->tile = tile;
  newNode->next = nullptr;

  //if statement to check if head points to nullptr
  if(this->head==nullptr)
  {
    this->head = newNode;
  }
  else
  {
    //list not Empty
    //create temporary node to point to the head
    Node* tempNode = this->head;

    while(tempNode->next!=nullptr)
    {
      //iterate through linkedlist until next is nullptr
      tempNode=tempNode->next;
    }
    //assign the temporary node to the next node called newNode
    tempNode->next=newNode;
  }
}

void LinkedList::deleteFront()
{
  //create node pointing to head
  Node* toDelete = head;
  //point head to next element
  head = head->next;
  //deletes the node at the front
  delete toDelete;
}

void LinkedList::deleteBack()
{
  Node* newNode = head;
  Node* prevNode = nullptr;
  if(head==nullptr){
    cout<<"list empty";
  }
  else if(head->next==nullptr)
    {
      newNode=head;
      delete(newNode);
    }
    else
    {
      newNode=head;
      while(newNode->newNode->next!=nullptr)
      {
        prevNode = newNode;
        prevNode = newNode->next;
      }
      prevNode->next=nullptr;
      delete(newNode);
  }
}
