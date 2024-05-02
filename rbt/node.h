// node.h
#ifndef NODE_H
#define NODE_H

class Node {
public:
    // Constructor
    Node(int newData, int newColor);
    // Destructor
    ~Node();

    // Getters
    Node* getNext();
    Node* getLeft();
    Node* getRight();
    Node* getParent();
    int getValue();
    int getColor();

    // Setters
    void setNext(Node* newNext);
    void setLeft(Node* newLeft);
    void setParent(Node* newParent);
    void setValue(int newData);
    void setRight(Node* newRight);
    void setColor(int newColor);
    // Pointers
    Node* next;
    Node* left;
    Node* right;
    Node* parent;
    int data; // Variable to hold integer data
    int color; // 1 is red, 0 is black
};

#endif // NODE_H
