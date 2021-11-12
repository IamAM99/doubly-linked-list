class LinkedList {
public:
    class Node {
    public:
        Node();
        Node(double );
        Node *next;
        Node *previous;
        double getValue();
        void setValue(double);
    private:
        double value;
    };
    LinkedList();
    LinkedList(const LinkedList &);
    ~LinkedList();
    void push_back(double);
    void push_front(double);
    double pop_back();
    double pop_front();
    double back();
    double front();
    bool empty();
    void clear();
    void show();
    int getSize();
    void extend(const LinkedList &);
private:
    int N{0};
public:
    Node *head;
    Node *tail;
};