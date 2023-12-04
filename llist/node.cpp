#include <iostream>
#include <cstring>
#include "node.h"


Node::Node(Student* newStudent) {
    student = newStudent;
    next = nullptr;
}

Node::~Node() {
    delete student;
 
}

// Gets student pointer
Student* Node::getStudent() {
    return student;
}

// Sets next pointer
void Node::setNext(Node* newNode) {
    next = newNode;
}

// Gett nxt pointer
Node* Node::getNext() {
    return next;
}
