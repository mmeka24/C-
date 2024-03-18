#include <iostream>
#include <fstream>
#include <cmath>  
#include "node.h"

using namespace std;


//for the exam:
//check if the numbers are even if they are not return false
//check how many nodes are in a linked list and add the node to the end 


//add, remove, and print

//

void insert (Node*&root, int * value){
/*
Check the value to be inserted (say X) with the value of the current node (say val) we are in:
If X is less than val move to the left subtree.
Otherwise, move to the right subtree.
Once the leaf node is reached, insert X to its right or left based on the relation between X and the leaf node’s value.

*/

/*


*/

if(root = NULL){
    root = value; 
}

else if (value > root->getValue()){
    insert(root->right, value); 

}
else if (value < root->getValue()){
     insert(root->left, value); 
}



return root; 

}


void search (Node* root, int *value){
//gonna have to do the search
//check the half point
//if smaller go to the left 
//if greater go to the right
    if(root == NULL){
        cout << "not applicable root is null" << endl; 
    }

    else if (value > root->getValue()){
        search(root->right, value); 

    }
    else if (value < root->getValue()){
        search(root->left, value); 
    }

    else if(root->getValue() == value){
        cout << "the value has been found " << endl; 

    }

    else{
        cout << "the value ur trying to find doesn't exist. sorry!" << endl; 

    }
}



void print (Node* root, int *value){
    //get print from hash 

}


void remove(Node* root, int *value){


}





int main(){
  Node *root = NULL; 
  char inp[50];
  cout << "what do wanna do: add, remove, or print" << endl;
  cin.getline(inp, 50);


  if(strcmp(inp, "add") == 0){
    char inp1[50];
    cout << "manual or file? " << endl;
    cin.getline(inp1, 50);
    int count = 0;     
    
        if (strcmp(inp1, "file") == 0){
        int input; 
        ifstream numbers;
        numbers.open("numbers.txt");

        if (!numbers.is_open()) {
            cout << "Error opening the file." << endl;
        } else {
            while (numbers >> input) {
                if (count > 100) {
                    cout << "Heap is Full! Cannot add more elements from the file." << endl;
                    break;  // Terminate the loop
                }
                
                count++; 
            }
            //call add or heapsort after reading from the file
        }

        numbers.close(); //close file
    }
    

        if (strcmp(inp1, "addmanual") == 0) {
            int numbers;
            bool done = false;
            while (!done) {
                cout << "Enter a number between 1 and 1000. Type 0 when you are done adding." << endl;
                cin >> numbers;
                if (count > 100) {
                    cout << "The heap is full." << endl;
                } else if (numbers > 1 && numbers < 1000) {
                    //add(heaps, count, number);
                    count++;
                } else if (numbers == 0) {
                    done = true;
                    // You may call heapsort or any other operations when done
                } else {
                    cout << "Invalid input. Please enter a number between 1 and 1000." << endl;
                }
            }
        } 
  }
  
    else if(strcmp(inp, "remove") == 0){

  }

    else if(strcmp(inp, "print") == 0){

  }

  
  return 0; 
}

