/* AP1400 HW3
 * Name: Mohammad Arabzadeh
 * ID: 9723055
 * Email: a.mohamad7824@gmail.com
 */

#include "linkedlist.h"

// Node default constructor. Runs the constructor with value=0.
LinkedList::Node::Node()
    : Node { 0 }
{
}

// Node constructor. Makes a node with desired value. 'next' and 'previous' are set to nullptr.
LinkedList::Node::Node(double val)
    : next { nullptr }
    , previous { nullptr }
    , value { val }
{
}

// Returns a copy of 'value'.
double LinkedList::Node::getValue() const
{
    return value;
}

// Returns a reference to 'value'. Will be used mainly for the bracket operator.
double& LinkedList::Node::getValue()
{
    return value;
}

// Sets 'value' to the input.
void LinkedList::Node::setValue(double val)
{
    value = val;
}

// operator<< returns the value of the Node.
std::ostream& operator<<(std::ostream& stream, const LinkedList::Node& node)
{
    stream << node.getValue();
    return stream;
}

// LinkedList default constructor. Sets 'head' and 'tail' to nullptr.
LinkedList::LinkedList()
    : head { nullptr }
    , tail { nullptr }
{
}

// LinkedList initializer list constructor. Fills the LinkedList object with the given list of doubles.
LinkedList::LinkedList(std::initializer_list<double> list)
    : LinkedList()
{
    for (auto item : list)
        this->push_back(item);
}

// LinkedList copy constructor. Fills the empty 'this' object by extending the input LinkedList object to itself.
LinkedList::LinkedList(const LinkedList& linked_list)
    : LinkedList()
{
    this->extend(linked_list);
}

// LinkedList destructor. Runs the 'clear' method, which pops back all Nodes of the LinkedList object.
LinkedList::~LinkedList()
{
    this->clear();
}

// Adds a Node with the given input double to the tail of the LinkedList object.
// If the LinkedList is empty, a new Node object gets created and both head and tail point to this object.
// if the LinkedList is not empty, a new Node object gets created and connected to the tail; then the tail points to this new object.
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

// Adds a Node with the given input double to the head of the LinkedList object.
// If the LinkedList is empty, a new Node object gets created and both head and tail point to this object.
// if the LinkedList is not empty, a new Node object gets created and connected to the head; then the head points to this new object.
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

// deletes the tail and then the tail points to the previous Node. Also returns the deleted Node value.
// If the LinkedList is empty, throws a std::logic_error.
double LinkedList::pop_back()
{
    double popped { this->back() };
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

// deletes the head and then the head points to the next Node. Also returns the deleted Node value.
// If the LinkedList is empty, throws a std::logic_error.
double LinkedList::pop_front()
{
    double popped { this->front() };
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

// Returns the last item in the LinkedList object. Throws a std::logic_error if the object is empty.
double LinkedList::back() const
{
    if (N == 0)
        throw std::logic_error { "Couldn't call LinkedList::back on an empty LinkedList." };
    return tail->getValue();
}

// Returns the first item in the LinkedList object. Throws a std::logic_error if the object is empty.
double LinkedList::front() const
{
    if (N == 0)
        throw std::logic_error { "Couldn't call LinkedList::front on an empty LinkedList." };
    return head->getValue();
}

// Returns 'true' if the LinkedList is empty, and 'false' if it is not empty.
bool LinkedList::empty()
{
    if (N == 0)
        return true;
    else
        return false;
}

// Deletes all Node objects in the LinkedList, by calling pop_back method while the list is not empty.
void LinkedList::clear()
{
    while (!empty()) {
        this->pop_back();
    }
}

// Shows all Node values in the LinkedList.
void LinkedList::show() const
{
    for (Node* item { head }; item; item = item->next)
        std::cout << *item << " ";
    std::cout << std::endl;
}

// Returns the size of the LinkedList.
int LinkedList::getSize() const
{
    return N;
}

// Extends a LinkedList object by the items in the input LinkedList object.
void LinkedList::extend(const LinkedList& linked_list)
{
    for (Node* item { linked_list.head }; item; item = item->next)
        this->push_back(item->getValue());
}

// Returns a reference to the value in the desired position.
double& LinkedList::operator[](int idx)
{
    if (empty() || idx >= N || idx < 0)
        throw std::logic_error { "Index is out of range!" };
    else {
        Node* node = head;
        for (int i {}; i < idx; i++, node = node->next)
            ;

        return node->getValue();
    }
}
