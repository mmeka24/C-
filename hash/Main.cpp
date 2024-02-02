#include <iostream>
#include <ifstream> 
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

Node* head = nullptr; // Assuming you have a head pointer for your linked list

void add(Node* newNode, Node* &head, Node* prev, Node* current);
void rehash(int *bucketSize, Node **hashTable)

int main() {
    char inp[20];
    char first[81];
    char last[81];
    int count = 0; 

    srand(time(NULL));

    int initialBucket = 100;
    int bucketSize = initialBucket;
    Node** hashTable = new Node*[bucketSize];

    for (int i = 0; i < bucketSize; i++) {
        hashTable[i] = nullptr;
    }

    bool running = true;
    while (running) {
        cout << "What would you like to do: add, print, delete or generate? " << endl;
        cin >> inp;

        if (strcmp(inp, "add") == 0) {
            cout << "Please enter the information below and press enter. Avoid adding spaces at the end." << endl;
            
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
            add(new Node(student), head, nullptr, head);
            
            int hashIndex = studentID % bucketSize;

            if (hashTable[hashIndex] == nullptr) {
                hashTable[hashIndex] = new Node(student);
            } else {
                Node* temp = hashTable[hashIndex];

                while (temp->getNext() != nullptr) {
                    temp = temp->getNext();
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

                    temp = temp->getNext();
                }
            }
        } 
        
        else if (strcmp(inp, "generate") == 0) {
        
          /*
          
          randomly generate new students by grabbing a random student first and last name from the 
          corresponding files, incrementing the id number, adding a random GPA (much like real life), and adding it in.  
          Make sure you have a command that allows you to specify how many students to generate and add. 
          
               

          */

          int generate = 0; 
          cout << "how many students would you like to generate: " << endl; 
          cin >> generate; 
          ifstream fnames;
          fnames.open ("fnames.txt");  

          ifstream lnames; 
          lnames.open("lnames.txt")

        //storing first name in an array of arrays 

          char*input = new char[20]; 
          
          while(fnames >> input){
            char *temp = new char [20]; 
            strcpy(temp, input);
            v.pushback(input);  
          }


        //storing lnames in an array of array 

         char*ln = new char[20]; 
         
         while(lnames >> ln){
            char *temp = new char[20]; 
            strcpy(temp, ln); 
            v.pushback(ln); 
            generate++; 
         }







             


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
        if (prev == nullptr) {
            newNode->setNext(head);
            head = newNode;
        } else {
            prev->setNext(newNode);
            newNode->setNext(current);
        }
    } 
    
    else {
        add(newNode, head, current, current->getNext());
    }
}

void rehash(int *bucketSize, Node **hashTable){
    //doouble the bucketsize 

    bucketsize = bucketsize * 2; 

    Node** temp1 = new Node*[bucketSize];

    for(int i = 0; i < bucketSize; i++){
        temp1[i] = NULL; 

    }

     for(int i = 0; i < bucketSize; i++){

        
     }







}
