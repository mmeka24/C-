#ifndef STUDENT
#define STUDENT

#include <iostream>
#include <cstring> 

using namespace std;

class Student {

 public:
  //Functions for Student class
   Student(char* first, char* last, int newid, float gpa);

  char* getFirstName();
  char* getLastName();
  int getStudentID();
  float getGPA();
  ~Student(); //constructor for student class
  
private: 
  char firstName[81];
  char lastName[81];
  int studentID = 0;
  float GPA = 0;
};

#endif
