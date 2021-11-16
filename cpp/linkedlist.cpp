#include "linkedlist.h"

LinkedList::Node::Node()
    : value {}
{
    next = nullptr;
    previous = nullptr;
}

LinkedList::Node::Node(double val)
    : value { val }
{
    next = nullptr;
    previous = nullptr;
}

LinkedList::Node::~Node()
{
    delete next;
    delete previous;
}

double LinkedList::Node::getValue() const
{
    return value;
}

void LinkedList::Node::setValue(double val)
{
    value = val;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList::Node& node)
{
    stream << node.getValue();
    return stream;
}
