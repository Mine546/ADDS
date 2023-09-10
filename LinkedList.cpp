#include "LinkedList.h"
#include <iostream>
#include <limits>

class LinkedList::Node {
public:
    Node(int data) : data(data), next(nullptr) {}

    int data;
    Node* next;
};

LinkedList::LinkedList() : head(nullptr), length(0) {}

LinkedList::LinkedList(int* array, int len) : head(nullptr), length(0) {
    for (int i = 0; i < len; i++) {
        insertPosition(i + 1, array[i]);
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 0) {
        pos = 1;
    }

    if (pos > length + 1) {
        pos = length + 1;
    }

    Node* newNode = new Node(newNum);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* prevNode = getNodeAtPosition(pos - 1);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    length++;
}

bool LinkedList::deletePosition(int pos) {
    if (pos <= 0 || pos > length) {
        return false;
    }

    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* prevNode = getNodeAtPosition(pos - 1);
        Node* temp = prevNode->next;
        prevNode->next = temp->next;
        delete temp;
    }

    length--;
    return true;
}

int LinkedList::get(int pos) const {
    if (pos <= 0 || pos > length) {
        return std::numeric_limits<int>::max();
    }

    Node* node = getNodeAtPosition(pos);
    return node->data;
}

int LinkedList::search(int target) const {
    int pos = 1;
    Node* current = head;

    while (current != nullptr) {
        if (current->data == target) {
            return pos;
        }
        current = current->next;
        pos++;
    }

    return -1;
}

void LinkedList::printList() const {
    std::cout << "[";
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " ";
        }
        current = current->next;
    }

    std::cout << "]" << std::endl;
}

LinkedList::Node* LinkedList::getNodeAtPosition(int pos) const {
    Node* current = head;
    int currentPos = 1;

    while (currentPos < pos) {
        current = current->next;
        currentPos++;
    }

    return current;
}
