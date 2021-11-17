#include "linkedlist.h"

LinkedList::Node::Node()
    : Node { 0 }
{
}

LinkedList::Node::Node(double val)
    : next { nullptr }
    , previous { nullptr }
    , value { val }
{
}

LinkedList::Node::~Node()
{
    // delete next;
    // delete previous;
    // next = nullptr;
    // previous = nullptr;
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

LinkedList::LinkedList()
    : head { nullptr }
    , tail { nullptr }
{
    std::cout << "LinkedList default const" << std::endl;
}

LinkedList::~LinkedList()
{
    // if (head == tail) {
    //     delete head;
    //     tail = head = nullptr;
    // } else {
    //     delete head;
    //     delete tail;
    //     tail = head = nullptr;
    // }
}

LinkedList::LinkedList(std::initializer_list<double> list)
    : LinkedList()
{
    std::cout << "LinkedList initializer const" << std::endl;
    for (auto item : list) {
        if (!head) {
            head = new Node { item };
            tail = head;
        } else {
            tail->next = new Node { item };
            tail->next->previous = tail;
            tail = tail->next;
        }
        N++;
        // std::cout << N << "  ";
        // std::cout << *tail << std::endl;
    }
}

void LinkedList::show() const
{
    Node* item { head };
    for (size_t i {}; i < N; i++) {
        std::cout << *item << " ";
        item = item->next;
    }
    std::cout << std::endl;
}