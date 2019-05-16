
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
}

LinkedList::deleteFront(){
  if(head !=nullptr){
    Node* newHead= head.next;
    delete head;
    head = newHead;

  }
}

LinkedList::deleteAt(int i){
  Node* current=head;
  int index=0;
  while(current!=nullptr && index<i){
    index++;
    current=current.next;
  }
  Node* deletedNode =current.next;
  current.next=deletedNode.next;
  delete deletedNode;



}




LinkedList::addFront(Tile data){

  if(head==nullptr){
    head =new Node(data, nullptr)
  } else{
    Node* newNode = new Node(data, head);
    head=newNode;
  }
}

LinkedList::addBack(Tile data){

  if(head==nullptr){
    head = new Node(i, nullptr);
  } else{
    Node* current = head;

    while(current!=nullptr){
      current=current.next;
    }
    current.next= new Node(i, nullptr);
  }
}

//gets data at an index
LinkedList::get(int i){
  Node* current=head;
  int index=0;
  while(current!=nullptr && index<i){
    index++;
    current=current.next;
  }

  return current.data;
}

//add a node at an index
LinkedList::addAt(int i, Tile data){
  Node* current=head;
  int index=0;
  while(current!=null && index+1<i){
    current= current.next;
    index++;
  }

  Node* newNode = new Node(data, current.next)
  current.next= newNode;

}

LinkedList::size(){

  Node* current=head;
  int index=0;
  while(current!=nullptr){
    index++;
    current=current.next;
  }

  return index;

}

LinkedList::clear(){

}
