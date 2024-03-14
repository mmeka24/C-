#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <array> 
#include "node.h"

using namespace std;

// Function declarations
void enqueue(Node* &head, const char* data);
char* peek(Node* head);
void pop(Node* &head);
void push(Node* &head, char* data);
bool isEmpty(Node* head);
int precedence(char op);
void shunt(Node* &treeRoot, char array);
void infix(Node* treeRoot);
void prefix(Node* treeRoot);
void postfix(Node* treeRoot);
void binarytree(Node* &root);

// Function definitions

/*
queue = fifi = add at the end delete from the top like a line 

stack = lifo = add and delete from the top 

pop = dequeue 

*/
void enqueue(Node* &head, char* data) {
    //adding at the end of hte llist 
    Node* newNode = new Node(data);
    newNode->setNext(nullptr);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->getNext() != nullptr) {
            //traverse the node find the last and add 
            current = current->getNext();
        }
        current->setNext(newNode);
    }
}


void dequeue(Node* &head) {
    //move head and delete the prev head 
    if (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}


char* peek(Node* head) {
    //printing the root 
    if (head != nullptr) {
        return head->getValue();
    }
    return nullptr;
}

void pop(Node* &head) {
    //move head and delete the prev head 

    if (head != nullptr) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
    }
}

void push(Node* &head, char* data) {
    //ADDING TO THE TOP
    //new node has to be at the head 
    Node* newNode = new Node(data);
    newNode->setNext(head); //newnodes next = head 
    head = newNode; //setting head as the new node
}

bool isEmpty(Node* head) {
    bool empty;
    if (head == nullptr) {
        empty = true;
    } else {
        empty = false;
    }
    return empty;
}


int precedence(char op) {
    //setting precdence from the wikepedia page 
    if (op == '^'){
        return 3;
    }
   else if (op == '*' || op == '/') {
    return 2;
}
   else if (op == '+' || op == '-'){
        return 1;
    }
    else{
    return 0;
}
}

/*void shunt(Node* &treeRoot, char expression[80]) {
    int i = 0;
    while (expression[i] != '\0') {
        if (isdigit(expression[i])) {
            enqueue(head, &array[i]);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '^' || expression[i] == '/' || expression[i] == '*') {
            while (!isEmpty(stackHead) && precedence(peek(stackHead)[0]) >= precedence(expression[i])) {
                enqueue(head, peek(stackHead));
                pop(stackHead);
            }
            push(stackHead, &array[i]);
        } else if (expression[i] == '(') {
            push(stackHead, &array[i]);
        } else if (expression[i] == ')') {
            while (!isEmpty(stackHead) && peek(stackHead)[0] != '(') {
                enqueue(head, peek(stackHead));
                pop(stackHead);
            }
            pop(stackHead); // Discard the '('
        }
        i++;
    }

    while (!isEmpty(stackHead)) {
        enqueue(head, peek(stackHead));
        pop(stackHead);
    }
}*/


void infix(Node* treeRoot) {
    //infix = left root right 
    if (treeRoot != nullptr) {
        infix(treeRoot->getLeft());
        cout << treeRoot->getValue() << " ";
        infix(treeRoot->getRight());
    }
}

void prefix(Node* treeRoot) {
    if (treeRoot != nullptr) {
            //prefix =  root left right 

        cout << treeRoot->getValue() << " ";
        prefix(treeRoot->getLeft());
        prefix(treeRoot->getRight());
    }
}

void postfix(Node* treeRoot) {
        //infix =  left right root 

    if (treeRoot != nullptr) {
        postfix(treeRoot->getLeft());
        postfix(treeRoot->getRight());
        cout << treeRoot->getValue() << " ";
    }
}


void binarytree(Node*& head, Node*& root) {
    vector<Node*> stack; //creating a vector of nodes  
    Node* current = head;
    while (current != nullptr) {
        if (isdigit(current->getValue()[0])) {
            //first node digit = operand 

            stack.push_back(new Node(current->getValue()));
        } else {
            //if its an operator 
            Node* operatorNode = new Node(current->getValue());
            if (stack.size() < 2) {
                cout << "error";
                return;
            }
            Node* rightNode = stack.back(); 
            stack.pop_back();
            Node* leftNode = stack.back(); 
            stack.pop_back();
            operatorNode->setRight(rightNode);
            operatorNode->setLeft(leftNode);
            stack.push_back(operatorNode);
        }
        current = current->getNext();
    }
    if (stack.size() == 1) {
        root = stack.back();
        //the root 
    } else {
        cerr << "Error in expression.\n";
    }
}

int main() {
    Node* head = nullptr; // Queue head for postfix notation
    Node* stackHead = nullptr; // Operator stack head for handling operators and parentheses

    char expression[80];
    cout << "Enter the infix expression: ";
    cin.getline(expression, 80);
    //CODE TO SHUNT TRANSLATED IN MAIN 
    for (int i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            //if it is an opernad then enqueu 

            char operand[2] = {expression[i], '\0'};
            enqueue(head, operand);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
            //if it is an operator 
            //check precidence 
            //if precdence on top is bigger than dqueu and enque 
            while (!isEmpty(stackHead) && precedence(peek(stackHead)[0]) >= precedence(expression[i])) {
                enqueue(head, peek(stackHead));
                pop(stackHead);
            }
            char op[2] = {expression[i], '\0'};
            push(stackHead, op);
        } else if (expression[i] == '(') {
            //pushing to op stack 
            char op[2] = {expression[i], '\0'};
            push(stackHead, op);
        } else if (expression[i] == ')') {
            while (!isEmpty(stackHead) && peek(stackHead)[0] != '(') {
                enqueue(head, peek(stackHead));
                pop(stackHead);
            }
            pop(stackHead); // Remove '('
        }
    }

    while (!isEmpty(stackHead)) {
        enqueue(head, peek(stackHead));
        pop(stackHead);
    }

    Node* er = nullptr;
    binarytree(head, er);

    cout << "Prefix expression: ";
    prefix(er);
    cout << "\nInfix expression: ";
    infix(er);
    cout << "\nPostfix expression: ";
    postfix(er);
    cout << endl;

    // Clean up allocated memory, if necessary
    // This depends on your Node class and whether you have a cleanup or destructor function

    return 0;
}


