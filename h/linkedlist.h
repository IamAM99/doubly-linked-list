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
        double& getValue();
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
    double back() const;
    double front() const;
    bool empty();
    void clear();
    void show() const;
    int getSize() const;
    void extend(const LinkedList&);
    // double operator[](size_t) const;
    double& operator[](size_t);

private:
    size_t N {};

public:
    Node* head;
    Node* tail;
};

#endif