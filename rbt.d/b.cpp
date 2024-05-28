/*
manasvi meka 
may 23rd 2024 
project: red black tree deletion. added 4 functions: search, transplant, deletion, and delete fix!
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "node.h"

using namespace std;

// FUNCTION PROTOTYPES FOR ROTATE LEFT AND ROTATE RIGHT

void rotateLeft(Node *& root, Node *& node);
void rotateRight(Node *& root, Node *& node);
void del2(Node *& root, Node *& node);
void del(Node *& root, Node *& node);
void insert(Node *& root, Node *& node);
void insert2(Node *& root, Node *& node);

// Get grandparent node
Node* getGrandparent(Node *& b) {
    Node* parent = b->getParent();
    if (parent != nullptr && parent->getParent() != nullptr) {
        return parent->getParent();
    } else {
        return nullptr;
    }
}

// Get sibling node
Node* getSibling(Node *& b) {
    Node* parent = b->getParent();
    if (parent != nullptr) {
        if (b == parent->getLeft()) {
            return parent->getRight();
        } else {
            return parent->getLeft();
        }
    } else {
        return nullptr;
    }
}

// Get uncle node
Node* getUncle(Node *& b) {
    Node* grandparent = getGrandparent(b);
    if (grandparent != nullptr) {
        Node* parent = b->getParent();
        if (parent == grandparent->getLeft()) {
            return grandparent->getRight();
        } else {
            return grandparent->getLeft();
        }
    } else {
        return nullptr;
    }
}

// Find the minimum node in a subtree
Node* minimum(Node *x) {
    while (x->getLeft() != NULL) {
        x = x->getLeft();
    }
    return x;
}


void insert (Node *& root, Node *& node){
    //node is the new node called from main 

//binary search tree basic part 

//CASE 1: Z IS ROOT AKA BINARY SEARCH TREE 
if (root == NULL){
    root = node; 
    root->setColor(0); //COLOR IS BLACK  
}
else{
     if (node->data < root->data){
        if (root->left == NULL) { // if left child is null
                    root->left = node;
                    node->parent = root;
            }
        else { // if left child is not null
                    insert(root->left, node);
                }
    }

    else{
        //if the new node data is greater than the roots 
       if (root->right == NULL) { // if right child is null
                root->right = node;
                node->parent = root;
            }
            else { // if right child is not null
                insert(root->right, node);
            }
    }

}

//making the root black 
//https://www.geeksforgeeks.org/insertion-in-red-black-tree/


}

void insert2(Node *& root, Node *& node){
    //CASE 2: Z'S UNCLE IS RED
    //0 is black 
    //1 is red
     /*if (node == nullptr || node->parent == nullptr) {
        return; // Ensure node and its parent are not null
    }*/



    if ((node->parent) == NULL){

        //if newnode is the root make it black 
        root->setColor(0); 

    }
    
    else if (((node->getParent())->getColor()) == 0) { 
        // if parent is black
        return;
    }
    else if ((getUncle(node)!= NULL && getUncle(node)->getColor()) == 1) { 
        // if uncle is red
        
      /*  1) z's parents and uncle are black 
        2) z's grandparent is red*/
        
       ((node->getParent())->setColor(0));  // the parent becomes black 
        (getUncle(node))->setColor(0); //the uncle becomes black 
        (getGrandparent(node))->setColor(1); //the grandparent become red
        Node * temp = getGrandparent(node); 
        insert2(root, temp);
        
    }

    else{
    //if uncle is black 
    //https://www.codesdope.com/course/data-structures-red-black-trees-insertion/
    Node *parent = node->getParent(); 
    Node *grandparent = getGrandparent(node); 
        if (node == parent->right && parent == grandparent->left) { // if node is right child and parent is left child
            rotateLeft(root, parent);
            node = node->getLeft();
        }
        else if (node == parent->getLeft() && parent == grandparent->getRight()) { // if node is left child and parent is right child
            rotateRight(root, parent);
            node = node->getRight();
        }

        parent = node->getParent();
        grandparent = getGrandparent(node);

        if (node == parent->left) { // if node is left child
            rotateRight(root, grandparent);
        }
        else { // if node is right child
            rotateLeft(root, grandparent);
        }
        parent->setColor(0);
        grandparent->setColor(1);



    }


}

// Function to replace one subtree as a child of its parent with another subtree
//gonna be used in the del funciton 
void transplant(Node *& root, Node *& u, Node *& v) {
    if (u->getParent() == NULL) {
        root = v;
    } else if (u == u->getParent()->getLeft()) {
        u->getParent()->setLeft(v);
    } else {
        u->getParent()->setRight(v);
    }
    if (v != NULL) {
        v->setParent(u->getParent());
    }
}

// Function to delete a node from the Red-Black Tree
//code scape deletion 
void del(Node *& root, Node *& node) {
    Node *y = node;
    Node *x;
    int original_color = y->getColor();

    if (node->getLeft() == NULL) {
        //CASE 1 LEFT IS NULL
        x = node->getRight();
        transplant(root, node, node->right);
    } else if (node->getRight() == NULL) {
        //CASE 2 RIGHT IS NULL 
        x = node->getLeft();
        transplant(root, node, node->left);
    } else {
        //CASE 3 - 2 CHILDREN BEGIN BY FINDING MIN 
        y = minimum(node->getRight());
        original_color = y->getColor();
        x = y->getRight();
        if (y->getParent() == node && x != NULL) {
            x->setParent(y);
        } else {
            transplant(root, y, y->right);
            y->setRight(node->getRight());
            if (y->getRight() != NULL) {
                y->getRight()->setParent(y);
            }
        }
        transplant(root, node, y);
        y->setLeft(node->getLeft());
        //CHECKING IF GETFLEFT IS NULL BEFORE SETTING THE PARENT
        //FIXED!!!!!!!!
        if (y->getLeft() != NULL) {
            y->getLeft()->setParent(y);
        }
        y->setColor(node->getColor());
    }

    if (original_color == 0 && x != NULL) {
        del2(root, x);
    } else if (original_color == 0) {
        del2(root, y->parent);
    }
}


// Function to fix the Red-Black Tree properties after deletion
//programizz pseudo code 
void del2(Node *& root, Node *& node) {
    while (node != root && node->getColor() == 0) {
        if (node == node->getParent()->getLeft()) {
            Node *w = getSibling(node);
            if (w->getColor() == 1) {
                w->setColor(0);
                node->getParent()->setColor(1);
                rotateLeft(root, node->parent);
                w = getSibling(node);
            }
            if (w->getLeft()->getColor() == 0 && w->getRight()->getColor() == 0) {
                w->setColor(1);
                node = node->getParent();
            } else {
                if (w->getRight()->getColor() == 0) {
                    w->getLeft()->setColor(0);
                    w->setColor(1);
                    rotateRight(root, w);
                    w = getSibling(node);
                }
                w->setColor(node->getParent()->getColor());
                node->getParent()->setColor(0);
                w->getRight()->setColor(0);
                rotateLeft(root, node->parent);
                node = root;
            }
        } else {
            Node *w = getSibling(node);
            if (w->getColor() == 1) {
                w->setColor(0);
                node->getParent()->setColor(1);
                rotateRight(root, node->parent);
                w = getSibling(node);
            }
            if (w->getLeft()->getColor() == 0 && w->getRight()->getColor() == 0) {
                w->setColor(1);
                node = node->getParent();
            } else {
                if (w->getLeft()->getColor() == 0) {
                    w->getRight()->setColor(0);
                    w->setColor(1);
                    rotateLeft(root, w);
                    w = getSibling(node);
                }
                w->setColor(node->getParent()->getColor());
                node->getParent()->setColor(0);
                w->getLeft()->setColor(0);
                rotateRight(root, node->parent);
                node = root;
            }
        }
    }
    node->setColor(0);
}

// Function to perform left rotation
void rotateLeft(Node *& root, Node *& node) {
    Node *y = node->getRight();
    node->setRight(y->getLeft());
    if (y->getLeft() != NULL) {
        y->getLeft()->setParent(node);
    }
    y->setParent(node->getParent());
    if (node->getParent() == NULL) {
        root = y;
    } else if (node == node->getParent()->getLeft()) {
        node->getParent()->setLeft(y);
    } else {
        node->getParent()->setRight(y);
    }
    y->setLeft(node);
    node->setParent(y);
}

// Function to perform right rotation
void rotateRight(Node *& root, Node *& node) {
    Node *y = node->getLeft();
    node->setLeft(y->getRight());
    if (y->getRight() != NULL) {
        y->getRight()->setParent(node);
    }
    y->setParent(node->getParent());
    if (node->getParent() == NULL) {
        root = y;
    } else if (node == node->getParent()->getRight()) {
        node->getParent()->setRight(y);
    } else {
        node->getParent()->setLeft(y);
    }
    y->setRight(node);
    node->setParent(y);
}

// Function to print the tree
void print(Node *& root, int indent) {
    if (root == NULL) {
        return;
    }
    indent += 10;
    print(root->right, indent);
    for (int i = 10; i < indent; i++) {
        cout << " ";
    }
    cout << root->data;
    if (root->getColor() == 1) {
        cout << " (R)" << endl;
    } else {
        cout << " (B)" << endl;
    }
    print(root->left, indent);
}

// Function to search a node
Node* search(Node *& root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (root->data < value) {
        return search(root->right, value);
    }
    return search(root->left, value);
}

// Main function
int main() {
    Node *root = NULL;
    bool quit = false;

    while (!quit) {
        char inp[50];
        cout << "What would you like to do: addmanual, addfile, delete, search, print, or quit?" << endl;
        cin.getline(inp, 50);

        if (strcmp(inp, "addmanual") == 0) {
            int inputn;
            cout << "Please enter a number from 1 - 999. " << endl;
            cin >> inputn;
            cin.ignore();

            if (inputn > 1 && inputn < 999) {
                Node *node = new Node(inputn, 1);
                insert(root, node);
                insert2(root, node);
            } else {
                cout << "Invalid input." << endl;
            }
        } else if (strcmp(inp, "addfile") == 0) {
            ifstream file;
            file.open("numbers.txt");
            if (!file.is_open()) {
                cout << "Error opening the file." << endl;
            } else {
                int number;
                while (file >> number) {
                    Node *node = new Node(number, 1);
                    insert(root, node);
                    insert2(root, node);
                }
                file.close();
            }
        } else if (strcmp(inp, "print") == 0) {
            cout << "Printing the tree:" << endl;
            print(root, 0);
            cout << endl;
        } else if (strcmp(inp, "delete") == 0) {
            int value;
            cout << "Enter the value to delete: ";
            cin >> value;
            cin.ignore();
            Node* node = search(root, value);
            if (node != NULL) {
                del(root, node);
                cout << "Node with value " << value << " deleted." << endl;
            } else {
                cout << "Value not found in the tree." << endl;
            }
        } else if (strcmp(inp, "search") == 0) {
            int value;
            cout << "What value are you searching for: ";
            cin >> value;
            cin.ignore();
            Node* node = search(root, value);
            if (node != NULL) {
                cout << "Node with value " << value << " has been found." << endl;
            } else {
                cout << "Value not found in the tree." << endl;
            }
        } else if (strcmp(inp, "quit") == 0) {
            quit = true;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
