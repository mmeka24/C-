#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


// Function to add a new element to the heap and maintain the max heap property
void add(int *&heaps, int count, int num) {
    // Calculate the parent index
    int parent = floor(count / 2);

    // If there is nothing in the array the first number can be the new number 
    if (count == 0) {
        heaps[1] = num;
    }

    else if (heaps[parent] > num) {
        // Adding at the next available slot if its less than parent
        heaps[count + 1] = num;
    } 
    
    
    else {
        // Parent is less than the num
        // Add to the end of the array and check with parent
        // If it is actually bigger than the parent, then you would swap
        heaps[count + 1] = num;
        int newindex = count + 1;

        int parentindex = floor (newindex / 2);
// Inside the add function
while (parentindex > 0 && heaps[newindex] > heaps[parentindex]) {
    int temp = heaps[parentindex];
    heaps[parentindex] = heaps[newindex]; //new index is now parent index 
    heaps[newindex] = temp; //parent index is now new index so parent child are swtiching

    newindex = parentindex; // The previous parent is now the new index
    parentindex = floor(newindex / 2); // Calculate the parent index of the new index and repeat 
    //add is done. 
}

    }

}





void print(int count, int* heaps, int index, int indent) {
    if (index <= count && heaps[index] != 0) {

    print(count, heaps, 2 * index + 1, indent + 5);
        // Print current node with proper indentation
        for (int i = 0; i < indent; i++) {
            cout << " ";
        }
        cout << heaps[index] << endl;        

        // Print right subtree
        print(count, heaps, 2 * index, indent + 5);
    }
}

void remove(int *&heaps, int &count){
    //output roots value 

    if (count == 0 ){
        cout << "heap is full"; 
    }

    cout << "removing root: " << heaps[1] << endl; 
    //the first index is the root!!!!!!!

    heaps[1] = heaps[count]; 
    heaps[count] = NULL; 
    int start = 1; 

 while (true) {
        int leftc = start * 2;
        int rightc = start * 2 + 1;
        int largerChild;

        if (leftc <= count && rightc <= count) {
            // Determine the larger child
            if (heaps[leftc] > heaps[rightc]) {
            largerChild = leftc;
            } else {
            largerChild = rightc;
            }

        } else if (leftc <= count) {
            largerChild = leftc;
        } else {
            // No children
            break;
        }

        if (heaps[start] < heaps[largerChild]) {
            // Swap with the larger child
            int temp = heaps[start];
            heaps[start] = heaps[largerChild];
            heaps[largerChild] = temp;

            start = largerChild;
        } else {
            // The heap property works 
            break;
        }
}
    count--; //have to decrease count after each deletion 
}



int main() {
    char input[20];
    int* heaps = new int[101]; // Initialize heap array with 0s
    int count = 0; // initialize count to 1
    int num = 0;

    bool running = true;
    while (running) {
        cout << "addmanual, file, delete, oneremove, print, quit" << endl;
        cin >> input;

        if (strcmp(input, "addmanual") == 0) {
            int number;
            bool done = false;
            while (!done) {
                cout << "Enter a number between 1 and 1000. Type 0 when you are done adding." << endl;
                cin >> number;
                if (count > 100) {
                    cout << "The heap is full." << endl;
                } else if (number > 1 && number < 1000) {
                    add(heaps, count, number);
                    count++;
                } else if (number == 0) {
                    done = true;
                    // You may call heapsort or any other operations when done
                } else {
                    cout << "Invalid input. Please enter a number between 1 and 1000." << endl;
                }
            }
        } 
        
else if (strcmp(input, "file") == 0) {
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
            add(heaps, count, input); //adding each input value from the file in heaps
            count++; 
        }
        //call add or heapsort after reading from the file
    }

    numbers.close(); //close file
}
 else if (strcmp(input, "delete") == 0) {
            while (count > 0) { 
                //there has to be more than 1 to delete root 
                //keep deleting to remove all 
                remove(heaps, count);
            }
            if (count ==0){
                cout << "heap empty" << endl; 
            }
        } else if (strcmp(input, "oneremove") == 0) {
            remove(heaps, count);
        } else if (strcmp(input, "print") == 0) {
            print(count+1, heaps, 1, 0);
        } else if (strcmp(input, "quit") == 0) {
            running = false;
        } else {
            cout << "Invalid input. Please enter a valid command." << endl;
        }
    }

    return 0;
}
