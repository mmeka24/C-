// NODE.CPP
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

// Construct node given data
Node::Node(char* newData) {
    value = new char[strlen(newData) + 1];
    strcpy(value, newData); //copying newData to value 
    next = NULL;
    left = NULL;
    right = NULL;
}

// Get next node
Node* Node::getLeft() {
    return left;
}

// Get next node
Node* Node::getRight() {
    return right;
}

// Get next node
Node* Node::getNext() {
    return next;
}

// Get node value
char* Node::getValue() {
    return value;
}

// Set next node
void Node::setNext(Node* newNext) {
    next = newNext;
}

// Set left node
void Node::setLeft(Node* newLeft) {
    left = newLeft;
}

// Set right node
void Node::setRight(Node* newRight) {
    right = newRight;
}

// Destructor for node
Node::~Node() {
    delete[] value;
}
