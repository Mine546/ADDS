#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int data);
    int getData() const;
    Node* getNext() const;
    void setNext(Node* next);

private:
    int data;
    Node* next;
};

#endif
