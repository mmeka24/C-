//Levi Lao
//Last Edit: 12/11/23
//Project: Create LinkedList using nodes. Prove functions work before sending code to partner.

#include "Student.h"
#include "Node.h"

#include<iostream>
#include<cstring>

using namespace std;

int main() {

  //Create and assign students

  //Student constructor
  //  Student* firstStudent = new Student();
  //Student* secondStudent = new Student();

  while(running == 0)
  char input[10];
  cout << "what would you like to do: add, remove, print, avg, or quit" << endl;
  cin >> inp;
  if (strcmp(inp, "quit") == 0){
    running = 1; //stops the while loops 
  }

  else if (strcmp(input, "print") ==0) {
      //cout << "printing" << endl;
      print(head);
    }
    else if (strcmp(input, "DELETE") ==0) {
      //cout << "deleting" << endl;
      print(head);
    }
    else if (strcmp(input, "AVERAGE")==0) {
      print(head);
    }
    else if (strcmp(input, "add") == 0){
      cout << "enter first name " << endl;
      cin.get(firstName,20);
      cin.clear();
      cin.ignore();
      cout << "enter the id: " << endl;
      cin >> studentID;
      cin.clear();
      cin.ignore();
      cout << "enter the gpa: " << endl;
      cin >> GPA;
      cin.clear();
      cin.ignore();
      Node* current = head;
                add(current,first,last,id,gpa);
   
      
      
      
    }

  
  void add {


  }

  void remove{



  }

  void print{


  }



  
  


