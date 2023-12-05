#include <iostream>
#include "student.h"  // Include your header files as needed
#include "Node.h"
#include <cstring>



int main() {
  Student* student1 = new Student();
    student1->setID(111);
    student1->setFirstname("John");
    student1->setLastname("Doe");
    student1->setGPA(3.8);

    // Create the second student
    Student* student2 = new Student();
    student2->setID(222);
    student2->setFirstname("Jane");
    student2->setLastname("Smith");
    student2->setGPA(4.2);

    // Create the first node with the first student
    Node* myNode1 = new Node(student1);

    // Create the second node with the second student
    Node* myNode2 = new Node(student2);

    // Link the nodes
    myNode1->setNext(myNode2);

    // Access and display information about the first student through the first node
    cout << "Student 1 ID: " << myNode1->getStudent()->getID() << endl;
    cout << "Student 1 Name: " << myNode1->getStudent()->getFirstname() << " " << myNode1->getStudent()->getLastname() << endl;
    cout << "Student 1 GPA: " << myNode1->getStudent()->getGPA() << endl;

    // Access and display information about the second student through the second node
    cout << "Student 2 ID: " << myNode1->getNext()->getStudent()->getID() << endl;
    cout << "Student 2 Name: " << myNode1->getNext()->getStudent()->getFirstname() << " " << myNode1->getNext()->getStudent()->getLastname() << endl;
    cout << "Student 2 GPA: " << myNode1->getNext()->getStudent()->getGPA() << endl;

    // Cleanup
    delete myNode1;
    delete myNode2;

    return 0;
  
}

