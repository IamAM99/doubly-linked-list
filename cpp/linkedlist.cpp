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

LinkedList::LinkedList(std::initializer_list<double> list)
    : LinkedList()
{
    std::cout << "LinkedList initializer const" << std::endl;
    for (auto item : list)
        this->push_back(item);
}

LinkedList::LinkedList(const LinkedList& linked_list)
    : LinkedList()
{
    Node* item { linked_list.head };

    for (int i {}; i < linked_list.getSize(); i++) {
        this->push_back(item->getValue());
        item = item->next;
    }
}

int LinkedList::getSize() const
{
    return N;
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

void LinkedList::show() const
{
    Node* item { head };
    for (int i {}; i < N; i++) {
        std::cout << *item << " ";
        item = item->next;
    }
    std::cout << std::endl;
}

void LinkedList::push_back(double item)
{
    if (!head) {
        head = new Node { item };
        tail = head;
    } else {
        tail->next = new Node { item };
        tail->next->previous = tail;
        tail = tail->next;
    }
    N++;
}

void LinkedList::push_front(double item)
{
    if (!head) {
        head = new Node { item };
        tail = head;
    } else {
        head->previous = new Node { item };
        head->previous->next = head;
        head = head->previous;
    }
    N++;
}

double LinkedList::pop_back()
{
    if (!tail)
        throw std::logic_error { "Couldn't call LinkedList::pop_back on an empty LinkedList." };

    double popped {};
    popped = tail->getValue();
    tail = tail->previous;
    delete tail->next;
    tail->next = nullptr;
    N--;
    return popped;
}

double LinkedList::pop_front()
{
    if (!head)
        throw std::logic_error { "Couldn't call LinkedList::pop_front on an empty LinkedList." };

    double popped {};
    popped = head->getValue();
    head = head->next;
    delete head->previous;
    head->previous = nullptr;
    N--;
    return popped;
}

double LinkedList::back() const
{
    if (!tail)
        throw std::logic_error { "Couldn't call LinkedList::back on an empty LinkedList." };
    return tail->getValue();
}

double LinkedList::front() const
{
    if (!head)
        throw std::logic_error { "Couldn't call LinkedList::pop_front on an empty LinkedList." };
    return head->getValue();
}
