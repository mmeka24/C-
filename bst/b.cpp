/*
manasvi meka 
project: bst
update: actually added the search function in main! 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>  
#include "node.h"

using namespace std;


//for the exam:
//check if the numbers are even if they are not return false
//check how many nodes are in a linked list and add the node to the end 


//add, remove, and print

//

void insert (Node*&root, int value){
/*
Check the value to be inserted (say X) with the value of the current node (say val) we are in:
If X is less than val move to the left subtree.
Otherwise, move to the right subtree.
Once the leaf node is reached, insert X to its right or left based on the relation between X and the leaf node’s value.

*/


    if (root == NULL) {
        root = new Node(value);
    } else if (value > root->data) {
        insert(root->right, value);
    } else if (value < root->data) {
        insert(root->left, value);
    }


}


void search (Node* root, int value){
//gonna have to do the search
//check the half point
//if smaller go to the left 
//if greater go to the right
    if(root == NULL){
        cout << "the value ur trying to find doesn't exist. sorry!" << endl; 
    }

    else if (value > root->data){
        search(root->right, value); 

    }
    else if (value < root->data){
        search(root->left, value); 
    }

    else if(root->data == value){
        cout << "the value has been found " << endl; 

    }

    else{
        cout << "the value ur trying to find doesn't exist. sorry!" << endl; 
    }
}



void print (Node* root, int indent){
    //get print from hash 
    if (root == NULL ){
        return; 
    }
    indent += 5; 

    
    print(root->right, indent);


    for (int i = 0; i < indent; i++) {
        cout << " ";
    }
   
    cout << root->data << endl;

    print(root->left, indent);
    
}


void remove(Node*& root, int value) {
    if (root == NULL) {
        cout << "the num doesn't exist" << endl;
        return;
    }

    // Recursive calls for ancestors of node to be deleted
    else if (root->data > value) {
        remove(root->left, value);
    } else if (root->data < value) {
        remove(root->right, value);
    }

    // We reach here when root is the node to be deleted.
    else if (root->data == value) {
        if (root->left == NULL && root->right == NULL) {
            // No children
            cout << "deleting" << value << endl;
            delete root;
            root = NULL;
        } else if (root->left == NULL) {
            // One child (right)
            Node* temp = root->right;
            delete root;
            root = temp;
        } else if (root->right == NULL) {
            // One child (left)
            Node* temp = root->left;
            delete root;
            root = temp;
        } else {
            // Two children
            cout << "deleting: " << value << endl;
            Node* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            remove(root->right, temp->data); // Corrected: remove from the right subtree of the node to delete
}
    } else {
        cout << "uh i have no idea what's going on, your value doesn't exist" << endl;
    }
}








int main() {
    Node* root = NULL;
    bool quit = false;


    while (!quit) {
        char inp[50];
    cout << "What do you want to do: add, remove, search or print?" << endl;

        cin.getline(inp, 50);

        if (strcmp(inp, "add") == 0) {
            cout << "Do you want to add numbers manually or from a file?" << endl;
            cout << "Enter 'manual' for manual input or 'file' for file input: ";
            char input_method[50];
            cin.getline(input_method, 50);
            
            if (strcmp(input_method, "manual") == 0) {
                int numbers;
                while (true) {
                    cout << "Enter a number between 1 and 1000. Type 0 when you are done adding." << endl;
                    cin >> numbers;
                    cin.ignore(); // Ignore newline character after input
                    if (numbers == 0) {
                        break;
                    }
                    insert(root, numbers);
                }
            } else if (strcmp(input_method, "file") == 0) {
                ifstream file;
                file.open("numbers.txt");
                if (!file.is_open()) {
                    cout << "Error opening the file." << endl;
                } else {
                    int number;
                    while (file >> number) {
                        insert(root, number);
                    }
                    file.close();
                }
            } else {
                cout << "Invalid input method." << endl;
            }
        } else if (strcmp(inp, "remove") == 0) {
            int num_to_remove;
            cout << "Enter the number you want to remove: ";
            cin >> num_to_remove;
            remove(root, num_to_remove);
            cin.ignore(); // Ignore newline character after input
        } else if (strcmp(inp, "print") == 0) {

            cout << "Printing tree:" << endl;
            print(root,0);
            cout << endl;
        } 
        
        else if (strcmp(inp, "search") == 0) {
            int num = 0; 
            cout << "what num r u searching" << endl; 
            cin >> num; 
            cout << "searching tree:" << endl;
            search(root, num);
            cout << endl;
        } 
        
        
        else if (strcmp(inp, "quit") == 0){
            cout << "Ending the program." << endl;
            quit = true;
        }
    }

    return 0;
}


