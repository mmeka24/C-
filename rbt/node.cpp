#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

// Construct node given data
Node::Node(int newData) {
    data = newData;
    next = nullptr;
    left = nullptr;
    right = nullptr;
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

// Get node value (assuming data is an integer)
int Node::getValue() {
    return data;
}

Node* Node::getParent(Node *node) {
    return node->parent; 
}

Node* Node::getGrandparent(Node *node){
    return getParent(node->parent); 
}

void Node::getSibiling(Node *node){
    node* nn = node->parent; 
    
}


int Node::getColor() {
    return color; //0 is red, 1 is 
}


// Set next node
void Node::setNext(Node* newNext) {
    next = newNext;
}

// Set left node
void Node::setLeft(Node* newLeft) {
    left = newLeft;
}

void Node::setParent(Node* newParent){
     parent = newParent; 
}

void Node::

// Set right node
void Node::setRight(Node* newRight) {
    right = newRight;
}



// Destructor for node
Node::~Node() {
    // No need to delete data
}