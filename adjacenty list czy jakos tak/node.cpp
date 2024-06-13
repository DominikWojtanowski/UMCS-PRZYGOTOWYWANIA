#include "node.h"

Node::Node(char data) : data{data}
{
}
Node::~Node()
{
}
void Node::changeData(char data)
{
    this->data = data;
}