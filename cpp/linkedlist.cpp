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

double LinkedList::Node::getValue() const
{
    return value;
}

double& LinkedList::Node::getValue()
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
}

LinkedList::LinkedList(std::initializer_list<double> list)
    : LinkedList()
{
    for (auto item : list)
        this->push_back(item);
}

LinkedList::LinkedList(const LinkedList& linked_list)
    : LinkedList()
{
    this->extend(linked_list);
}

LinkedList::~LinkedList()
{
    this->clear();
}

void LinkedList::push_back(double item)
{
    if (empty()) {
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
    if (empty()) {
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
    if (empty())
        throw std::logic_error { "Couldn't call LinkedList::pop_back on an empty LinkedList." };

    double popped {};
    popped = tail->getValue();
    if (tail->previous) {
        tail = tail->previous;
        delete tail->next;
        tail->next = nullptr;
    } else { // this is the last tail
        delete tail;
        head = tail = nullptr;
    }
    N--;
    return popped;
}

double LinkedList::pop_front()
{
    if (empty())
        throw std::logic_error { "Couldn't call LinkedList::pop_front on an empty LinkedList." };

    double popped {};
    popped = head->getValue();
    if (head->next) {
        head = head->next;
        delete head->previous;
        head->previous = nullptr;
    } else { // this is the last head
        delete head;
        head = tail = nullptr;
    }
    N--;
    return popped;
}

double LinkedList::back() const
{
    if (N == 0)
        throw std::logic_error { "Couldn't call LinkedList::back on an empty LinkedList." };
    return tail->getValue();
}

double LinkedList::front() const
{
    if (N == 0)
        throw std::logic_error { "Couldn't call LinkedList::front on an empty LinkedList." };
    return head->getValue();
}

bool LinkedList::empty()
{
    if (N == 0)
        return true;
    else
        return false;
}

void LinkedList::clear()
{
    while (!empty()) {
        this->pop_back();
    }
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

int LinkedList::getSize() const
{
    return N;
}

void LinkedList::extend(const LinkedList& linked_list)
{
    Node* item { linked_list.head };

    for (int i {}; i < linked_list.getSize(); i++) {
        this->push_back(item->getValue());
        item = item->next;
    }
}

double& LinkedList::operator[](int idx)
{
    if (N == 0 || idx >= N || idx < 0)
        throw std::logic_error { "Index is out of range!" };
    else {
        Node* node = head;
        for (int i {}; i < idx; i++)
            node = node->next;

        return node->getValue();
    }
}
