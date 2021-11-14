#include "linkedlist.h"

LinkedList::Node::Node()
    : value {}
{
}

LinkedList::Node::Node(double val)
    : value { val }
{
}

double LinkedList::Node::getValue()
{
    return value;
}

void LinkedList::Node::setValue(double val)
{
    value = val;
}