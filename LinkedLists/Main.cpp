//Manasvi Meka
//Linked List program that adds, deletes, print, and averages student info

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;


void rehash(int &bucketSize, Node** &hashTable);


int main() {
  char inp[20];
  char first[20];
  char last[20];
  char input[10]; 
  int id; 
  

    srand(time(NULL));
  int initialBucket = 100;
  int bucketSize = initialBucket;
  Node** hashTable = new Node*[bucketSize];

  for (int i = 0; i < bucketSize; i++) {
    hashTable[i] = NULL;
  }


  bool running = true; 
  while(running){
    cout << "what would you like to do: add, print, delete? " << endl; 
    cin >> inp; 
    if(strcmp(inp, "add") == 0){
      
      cout << "please enter the infromation below and click enter don't add spaces at the end" << endl; 
        //id
      cout << "ID: " ;
      int studentID;
      cin >> studentID;
      cin.ignore(); 


      //first name
      cout << "First Name:" ;
       // cin.ignore(); 
         cin.getline(first, 81);
         

      //last name
      cout << "Last Name: " ;
     // cin.ignore(); 
         cin.getline(last, 81);

      //gpa
      cout << "GPA: " << endl ;
      float GPA; 
      cin >> GPA;
      Student* student = new Student(first, last, studentID, GPA);
      add(new Node(student), head, NULL, head);
      int hashIndex = newStudent->get_id() % bucketSize;

       if(hashTable[hashIndex] == NULL){
          hashTable[hashIndex] = new Node; 
      }

      //if there is already something in the hash table then create a new node
      if(hashTable[hashIndex] != NULL){
        Node* temp = hashTable[hashIndex];  
      if(temp->getNext() != NULL){
            temp = temp->getNext(); 
        }
        temp->getNext(new Node);  

      else{
        cout << "something is wrong"; 
      }

      }

    }
    //print
    else if(strcmp(inp,"print") == 0) {
       hashTable.print();
    for (int i = 0; i < bucketSize; i++){
      if(hashTable[i] != NULL){
        Node *temp = hashTable[i]; 

        while (temp != NULL){
        cout << temp->getStudent->get_first_name << temp->getStudent->get_last_name << temp->getStudent->get_id << temp->getStudent->get_gpa; 
        temp = temp->getNext(); 
      }

      }
    }
    }
    

//deleting
else if(strcmp(inp,"delete") == 0) { 
			cout << "Enter the id of the student you would like to delete" << endl;
			int studentID; 
      cin >> studentID;
		  hashTable.remove(studentID);

 int hashIndex = studentID % bucketSize;

 for (int i = 0; i < bucketSize; i++){
  int hashIndex = studentID % bucketSize; 

      if(hashTable[hashIndex] != NULL){
        Node *temp = hashTable[i]; 
        Node *prev = NULL; //using prev to update after deletion 

        while(temp!=NULL){
          if(temp->getStudent->get_id == studentID){
            if(prev = NULL){
              //if prev is NULL then move the temp next pointer to now be the head
              hashTable[hashIndex] = temp->getNext(); 
              delete temp; 
            }
            else{
              prev->getNext() = temp->getNext(); 
              delete temp; 
              temp = prev; 
            }

          }
        
          prev = temp; //prev = temp is same as prev = prev->getNext(); 
          temp = temp->getNext(); 

        }

      }

      }
    }



		} 

  //quit
    else if (strcmp(input, "QUIT") == 0) {
      running = false;
    }

    return 0; 
  }



void rehash(int &bucketSize, Node** &hashTable){
  bucketSize = bucketSize * 2; 


}
