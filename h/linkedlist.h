#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <initializer_list>
#include <iostream>
#include <ostream>

class LinkedList {
public:
    class Node {
    public:
        Node();
        Node(double);
        ~Node();
        Node* next;
        Node* previous;
        double getValue() const;
        void setValue(double);
        friend std::ostream& operator<<(std::ostream& stream, const Node& node);

    private:
        double value;
    };
    LinkedList();
    LinkedList(std::initializer_list<double>);
    LinkedList(const LinkedList&);
    ~LinkedList();
    void push_back(double);
    void push_front(double);
    double pop_back();
    double pop_front();
    double back();
    double front();
    bool empty();
    void clear();
    void show() const;
    int getSize() const;
    void extend(const LinkedList&);

private:
    int N { 0 };

public:
    Node* head;
    Node* tail;
};

#endif