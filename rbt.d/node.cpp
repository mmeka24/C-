// node.cpp
#include "node.h"

// Construct node given data and color
Node::Node(int newData, int newColor) {
    data = newData;
    color = newColor;
    next = nullptr;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

// Destructor for node
Node::~Node(){

    
}

// Get next node
Node* Node::getNext() {
    return next;
}

// Get left child
Node* Node::getLeft() {
    return left;
}

// Get right child
Node* Node::getRight() {
    return right;
}

// Get parent node
Node* Node::getParent() {
    return parent;
}

// Get node value
int Node::getValue() {
    return data;
}

// Get node color
int Node::getColor() {
    return color;
}

// Set next node
void Node::setNext(Node* newNext) {
    next = newNext;
}

// Set left child
void Node::setLeft(Node* newLeft) {
    left = newLeft;
}

// Set parent node
void Node::setParent(Node* newParent) {
    parent = newParent;
}

// Set node value
void Node::setValue(int newData) {
    data = newData;
}

// Set right child
void Node::setRight(Node* newRight) {
    right = newRight;
}

// Set node color
void Node::setColor(int newColor) {
    color = newColor;
}
