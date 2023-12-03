
#ifdef NODE_H
#define NODE_H

#include <iostream>

//creating node class
class Node{

 public:
  Node(*Student);
  ~Node(); 
  Student* getStudent();
  void setNext(Node*);
  //void setStudent(Student*)
  Node* getNext();
   

  
  private: 
  Node* next;
  Student* student; 

}









#endif
