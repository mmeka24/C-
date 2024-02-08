#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"


using namespace std;


Node* head = NULL; 


void add(Node* newNode, Node* &head, Node* prev, Node* current);
void rehash(int &bucketSize, Node **&hashTable);

    int ibucketSize = 10; 
    int bucketSize = ibucketSize; 


int main() {
    char inp[20];
    char first[81];
    char last[81];
    int count = 0;
    int id = 1; 


    srand(time(NULL));
    Node** hashTable = new Node*[bucketSize];


    for (int i = 0; i < bucketSize; i++) {
        hashTable[i] = nullptr; // setting hash to null 
    }


    bool running = true;


    while (running) {
        cout << "What would you like to do: add, print, delete or generate? " << endl;
        cin >> inp;


        if (strcmp(inp, "add") == 0) {
            cout << "Please add a space before you enter the name." << endl;


            //id
            cout << "ID: ";
            int studentID;
            cin >> studentID;
            cin.ignore();


            //first name
            cout << "First Name: ";
            cin.ignore();
            cin.getline(first, 81);


            //last name
            cout << "Last Name: ";
            cin.getline(last, 81);


            //gpa
            cout << "GPA: ";
            float GPA;
            cin >> GPA;


            Student* student = new Student(first, last, studentID, GPA);
            //calling the add function 
            add(new Node(student), head, nullptr, head);


            int hashIndex = studentID % bucketSize;


            if (hashTable[hashIndex] == NULL) {
                //if location is empty create the new student node 
                hashTable[hashIndex] = new Node(student);
            } else {
                //if location is not empty traverse and assign the next as the new student node 

                Node* temp = hashTable[hashIndex];


                while (temp->getNext() != nullptr) {
                    temp = temp->getNext(); //traversing the list 
                }


                temp->setNext(new Node(student));
            }
        } else if (strcmp(inp, "print") == 0) {
            for (int i = 0; i < bucketSize; i++) {
                Node* temp = hashTable[i];
                while (temp != nullptr) {
                    cout << temp->getStudent()->getFirstName() << " "
                         << temp->getStudent()->getLastName() << " "
                         << temp->getStudent()->getStudentID() << " "
                         << temp->getStudent()->getGPA() << endl;

                    //print everything from the llist of each hash 
                    temp = temp->getNext();
                
                }
                cout << endl; 
            }
        } 
        
        
        
else if (strcmp(inp, "generate") == 0) {
    int inputgen = 0;
    int studentCount = 0;
    cout << "how many students would you like to generate: " << endl;
    cin >> inputgen;

    // Storing first name in an array of arrays
      char* firstcpy = new char[20];
      char* lastcpy = new char[20];

// Opens first name file and stores in array
ifstream firstNames;
firstNames.open("fnames.txt");

//double pointer cuz storing the address of each thing from the txt file 
char ** fName = new char*[50]; 
for (int i = 0; i < 50; i++) {
          fName[i] = new char[20];
          firstNames >> firstcpy;
          strcpy(fName[i], firstcpy); //putting the string to double pointer array 
          studentCount++;
        //cout << fname[i]; 
      }

      
//fName[studentCount] = NULL; 
firstNames.close();

// Storing last name in an array of arrays

// Opens last name file and stores in array
ifstream lastNames;
lastNames.open("lnames.txt");


//from class 
char** lName = new char*[studentCount];

for (int i = 0; i < 50; i++) {
       
       
          lName[i] = new char[20];
          lastNames >> lastcpy;
          strcpy(lName[i], lastcpy);
        
      }
//lName[studentCount] = NULL; 
lastNames.close();




    // Solely generating the random students
      char firstName[20];
      char lastName[20];
      int studentID = 0;
      float gpa = 0.0;

      
      Student* newSt = new Student(firstName, lastName, studentID, gpa);


    for (int i = 0; i < inputgen; i++) { // generates random students
        char ftemp[20];
        char ltemp[20];
        int randFirst = rand() % studentCount;
        int randLast = rand() % studentCount;
        //index of the randfirst is gonna be the student copy that to temporary char array
        strncpy(ftemp, fName[randFirst], 20);
        strncpy(ltemp, lName[randLast], 20);


        // Creating a new student
        newSt = new Student(ftemp, ltemp, id++ , (rand() % 500) / 100.0);


        // Adds the students to the hash table
        int hashIndex = newSt->getStudentID() % bucketSize;
        if (hashTable[hashIndex] == nullptr) {
            hashTable[hashIndex] = new Node(newSt);
        } else {
            Node* temp = hashTable[hashIndex];


            while (temp->getNext() != nullptr) {
                temp = temp->getNext(); //traverse the node 
            }

            //once you get to the end the next node is the new student 
            temp->setNext(new Node(newSt));
        }


        // Rehash if there are more than three nodes in a chain
        for (int i = 0; i < bucketSize; i++) {
                
            if (hashTable[i] != NULL){
                  Node* temp = hashTable[i];
                   //counts how many nodes are linked 
                  int count = 1;
                  while (temp!= NULL){
                    count++; 
                    temp = temp->getNext(); 
                  }
                    //IF YOU GET MORE THAN 3 COLLISIONS THEN REHASH 
                  if (count>3){
                    rehash(bucketSize, hashTable); 
                  }

            }
        }
    }


    // Cleanup memory for fName and lName
    for (int i = 0; i < 50; i++) {
        delete[] fName[i];
        delete[] lName[i];
    }
    delete[] fName;
    delete[] lName;
}


         else if (strcmp(inp, "delete") == 0) {
            cout << "Enter the id of the student you would like to delete: ";
            int studentID;
            cin >> studentID;


            int hashIndex = studentID % bucketSize;


            if (hashTable[hashIndex] != nullptr) {
                Node* temp = hashTable[hashIndex];
                Node* prev = nullptr;


                while (temp != nullptr) {
                    if (temp->getStudent()->getStudentID() == studentID) {
                        if (prev == nullptr) {
                            hashTable[hashIndex] = temp->getNext();
                            delete temp;
                        } else {
                            prev->setNext(temp->getNext());
                            delete temp;
                        }
                        break;
                    }


                    prev = temp;
                    temp = temp->getNext();
                }
            }
        } else if (strcmp(inp, "QUIT") == 0) {
            running = false;
        }
    }


    // Clean up memory
    for (int i = 0; i < bucketSize; i++) {
        Node* temp = hashTable[i];
        while (temp != nullptr) {
            Node* next = temp->getNext();
            delete temp;
            temp = next;
        }
    }


    delete[] hashTable;


    return 0;
}


void add(Node* newNode, Node* &head, Node* prev, Node* current) {
    if (head == nullptr) {
        head = newNode;
        return;
    }


    if (current == nullptr) {
        prev->setNext(newNode);
        newNode->setNext(head);
        return;
    }


    if (newNode->getStudent()->getStudentID() < current->getStudent()->getStudentID()) {
        if (prev == NULL) {
            newNode->setNext(head);
            head = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(current);
        }
    } else {
        add(newNode, head, current, current->getNext());
    }
}

//passing hashtable by reference because the change needs to be reflected in the original
void rehash(int &bucketSize, Node**&hashTable) {
    // Double the bucket size
    bucketSize = ibucketSize * 2;


    // Creating a new hash table
    Node** newHashTable = new Node*[bucketSize];


    for (int i = 0; i < bucketSize; i++) {
        newHashTable[i] = NULL;
    }


    // Iterating through each element and assigning it to the new hash table
    for (int i = 0; i < bucketSize/2; i++) {
        Node * temp = hashTable[i]; // Temp is the index of ACC HASH TABLE


        while (temp != NULL) {
            int studentID = temp->getStudent()->getStudentID();
            int newHashIndex = studentID % bucketSize; // Getting the NEW hash index


            // Inserting the node into the hash table
            if (newHashTable[newHashIndex] == NULL) {
                newHashTable[newHashIndex] = new Node(temp->getStudent());
                
            } else {
                //chain when needed
                Node *temp1 = newHashTable[newHashIndex];
                //new hash index next should be equivalent to NULLL



                while (temp1->getNext() != NULL) {
                    // Traversing the node
                    temp1 = temp1->getNext();
                }


                temp1->setNext(new Node(temp->getStudent()));
            }


            temp = temp->getNext();
        }
    }
    
    hashTable = newHashTable; // ERROR: MUST PASS THE HASH TABLE DUH 

}



