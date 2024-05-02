#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath> 
#include <cstring>   
#include "node.h"

using namespace std; 


//FUNCTION PROTOTYPES FOR ROTATE LEFT AND ROTATE RIGHT
void rotateLeft(Node *& root, Node *& node); 
void rotateRight(Node *& root, Node *& node); 



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
     if (node == nullptr || node->parent == nullptr) {
        return; // Ensure node and its parent are not null
    }



    if ((node->parent) == NULL){

        //if newnode is the root make it black 
        root->setColor(0); 

    }
    
    else if (((node->getParent())->getColor()) == 0) { 
        // if parent is black
        return;
    }
    else if ((getUncle(node)->getColor()) == 1 && getUncle(node)!= NULL) { 
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



void rotateLeft(Node *& root, Node *& node){
    cout << "rotating left function L)" << endl; 
    Node *y = node->right; 
    node->right = y->left; 

    if(y->left != NULL){
        y->left->parent = node; // Update the parent pointer of y->left
    }
    
    y->left = node;
    y->parent = node->parent;
    if(node->parent == NULL){
        //x is root
        root = y; 
        cout << "u are now root " << endl; 
    }    

    else if(node == node->parent->left){
        //putting it as a left child
        node->parent->left = y; 
        cout << "u are now the left child" << endl; 
    }

    else{
        //putting it as a right child
        node->parent->right = y; 
        cout << "u are not the right child "<< endl; 
    }

    node->parent = y; 
}

/*
void rotateLeft(Node *& root, Node *& node){
    cout << "rotating left function L)" << endl; 
    Node *y = node->getRight(); 
    node->setRight(y->getLeft()); 

    if(y->getLeft() != NULL){
        y->getLeft()->setParent(node); // Update the parent pointer of y->left
    }
    
    y->setParent(node->getParent());
    if(node->getParent() == NULL){
        //x is root
        root = y; 
        cout << "u are now root " << endl; 
    }    

    else if(node == node->getParent()->getLeft()){
        //putting it as a left child
        node->getParent()->setLeft(y); 
        cout << "u are now the left child" << endl; 
    }

    else{
        //putting it as a right child
        node->getParent()->setRight(y); 
        cout << "u are not the right child "<< endl; 
    }

    y->setLeft(node);
    node->setParent(y); 
}*/


void rotateRight(Node *& root, Node *& node){
    cout << "rotating the function to the right" << endl; 
    Node *y = node->getLeft(); 
    node->setLeft(y->getRight()); 

    if(y->getRight() != NULL){
        y->getRight()->setParent(node); // Update the parent pointer of y->right
    }

    y->setParent(node->getParent());

    if(node->getParent() == NULL){
        root = y; 
        cout << "u are now root " << endl; 
    }

    else if(node == node->getParent()->getRight()){
        node->getParent()->setRight(y); 
        cout << "u are now the right child" << endl; 
    }
    else {
        node->getParent()->setLeft(y); // Update the left child of node's parent
        cout << "u are now the left child" << endl; 
    }

    y->setRight(node);
    node->setParent(y);
}

/*void rotateRight(Node *& root, Node *& node){
    cout << "rotating the function to the right" << endl; 
    Node *y = node->left; 
    node->left = y->right; 

    if(y->right != NULL){
        y->right->parent = node; // Update the parent pointer of y->right
    }

    y->right = node;
    y->parent = node->parent;

    if(node->parent == NULL){
        root = y; 
        cout << "u are now root " << endl; 
    }

    else if(node == node->parent->right){
        node->parent->right = y; 
        cout << "u are now the right child" << endl; 
    }
    else {
        node->parent->left = y; // Update the left child of node's parent
        cout << "u are now the left child" << endl; 
    }

    node->parent = y;

   // y->right = node; // Update the right child of y
    //node->parent = y; // Update the parent of node
}*/

void print(Node *& root, int indent){
    if(root == NULL){
        return; 
    }

    indent += 10; 

    print(root->right, indent);

    for (int i = 10; i < indent; i++) { // prints the indent
          cout << " ";
    }
    cout << root->data;
    if (root->getColor() == 1) { // prints the color of the node
        cout << " (R)" << endl;
    }
    else { // prints the color of the node
        cout << " (B)" << endl;
    }
    
    print(root->left, indent);


}


int main(){
    Node *root = NULL; 

    bool quit = false; 

    while (!quit){
        char inp [50]; 
        cout << "what would you like to do" << endl; 
        cin.getline(inp, 50); 

        if (strcmp(inp, "add") == 0) {
            int inputn; 
            cout << "please enter a number from 1 - 999. " << endl; 
            cin >> inputn; 
            cin.ignore(); 

            if(inputn > 1 && inputn < 999){
                Node *node = new Node(inputn, 1); 
                insert(root, node); 
                insert2(root, node);  
        }

        else{
            cout << "invalid input " << endl; 
        }
            
            }
        

        else if (strcmp(inp, "print") == 0){
            cout << "i will be printing" << endl; 
            print(root, 0); 
            cout << endl; 
            quit = false;  

        }

        else{
            quit = true; 
        }
    }
}








