#include <iostream> 
#include "node.h"
#include "student.h"

#include <cstring>

using namespace std;

Node::Node(Student* myStudent) {
    student = myStudent;
    next = nullptr;
    cout << "creating node" << endl;
}

Node::~Node() {
    delete student;
}

void Node::setNext(Node* newnext) {
    next = newnext;
}

Node* Node::getNext() const {
    return next;
}

Student* Node::getStudent() const {
    return student;
}
