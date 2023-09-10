#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList {
public:
    LinkedList();
    LinkedList(int* array, int len);
    ~LinkedList();

    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos) const;
    int search(int target) const;
    void printList() const;

private:
    class Node; // Forward declaration of Node

    Node* head;
    int length;

    Node* getNodeAtPosition(int pos) const;
};

#endif
