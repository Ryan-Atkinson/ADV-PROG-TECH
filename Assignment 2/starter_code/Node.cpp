#include "Node.h"

Node::Node(Tile* tile, Node* next):
    tile(tile),
    next(next)
{
}

Node::Node(Node& other):
   data(other.data),
   next(other.next)
{
}
