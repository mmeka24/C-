//Manasvi Meka
//Linked List program that adds, deletes, print, and averages student info

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
#include "Node.h"

using namespace std;

void add(Node* cur, Node* prev, Node* &head);
void print(Node* next);
float getAvg(Node* current, int total);
void remove(Node* &head, Node* current, Node* prev,  int studentID, int &total);



void add(Node* newNode, Node* cur, Node* prev, Node* &head) {
  if (cur == NULL) {
    //checking if the current node is null 
    if (prev == NULL) {
      //checking if the previous node is null so llist is empty
      //if empty then the newNode will be HEAD
      head = newNode;
    } else{
      //if current node is null than prev updated to point to new node  
      prev->setNext(newNode);
    }
    return;
  }
  //organizes the ids
  if(newNode->getStudent()->getStudentID() < cur->getStudent()->getStudentID()) {
    // if the new node has a smaller student ID, insert it before the current node
    newNode->setNext(cur);
    if (prev != NULL) {
      //if previous node 
      prev->setNext(newNode);
    } else {
      //no previous nodes at all newNode is head again 
      head = newNode;
    }
  } else {
    add(newNode, cur->getNext(), cur, head);
  }
}


float getAvg(Node* current, int total){
  if (current == NULL) {
    return 0;
  }
  //incremented total in the main 
  return current->getStudent()->getGPA()/total + getAvg(current->getNext(), total);

}


void print(Node* next){
  if (next == NULL) {
    return;
    //if next node has nothing then don't print 
  }
  Student* cur = next->getStudent(); //short hand version to deference addresses
  cout << "student id: " << cur->getStudentID() << endl;
  cout << "first name: "<< cur->getFirstName() << endl; 
  cout << "last name: " << cur->getLastName() << endl; 
  cout << "gpa: "<< fixed << setprecision(2) << cur->getGPA() << endl;
  print(next->getNext());
}


void remove(Node* &head, Node* current, Node* prev, int studentID, int &total) {
  if (current == NULL) {
    return; //nothing in. skip. 
  }
  if (current->getStudent()->getStudentID() == studentID) {
    if (prev != NULL) {
      //prev->getNext()->setNext(current->getNext());
      prev->setNext(current->getNext()); //changed this LINE
    } 
    else {
      head = head->getNext();
    }
    total--;

    delete current;
  } else {
    remove(head, current->getNext(), current, studentID, total);
  }
}



int main() {
  int total = 0;
  char inp[20];
  char first[20];
  char last[20];
  char input[10]; 
  int id; 
  Node* head = NULL; 
  bool running = true; 
  while(running){
    cout << "what would you like to do: add, print, delete, or avg? " << endl; 
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
      total += 1;

    }
    //print
    else if(strcmp(inp,"print") == 0) {
                print(head);
    }
    //avg 
    else if(strcmp(inp,"avg") == 0) {
		cout << "The average gpa is: " << getAvg(head, total) << endl;
		}

//deleting
else if(strcmp(inp,"delete") == 0) { 
			cout << "Enter the id of the student you would like to delete" << endl;
			int studentID; 
      cin >> studentID;
			Node* current = head;
			remove(head, current, NULL , studentID, total);
      

		} 

  //quit
    else if (strcmp(input, "QUIT") == 0) {
      running = false;
    }
  }

  


}