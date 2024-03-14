// NODE.H
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node {
public:
    // Constructor
    Node(char* newData);
    ~Node();

    void setNext(Node*);
    Node* getNext();
    void setRight(Node*);
    void setLeft(Node*);
    Node* getLeft();
    Node* getRight();
    char* getValue(); // 

private:
    // Pointers
    Node* next;
    Node* left;
    Node* right;
    char* value; // the data of the llist 
};

#endif
