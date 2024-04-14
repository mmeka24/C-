#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath> 
#include <cstring>   
#include "node.h"

using namespace std; 


void insert (Node *& root, int value){

//binary search tree part 
if (root == NULL){
    insert(root = value); 
}
else if (value > root->data){
    insert(root->right = value); 
}

else{
    insert(root->left = value); 
}

//making the root black 
//https://www.geeksforgeeks.org/insertion-in-red-black-tree/

root.getColor(black); 

}



 

int main(){
    Node *root = NULL; 

    bool quit = false; 

    while (!quit){
        char inp [50]; 
        cout << "what would you like to do" << endl; 
        input.getline(inp, 50); 

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
        }

    }
}









