#include <iostream>
#include "Student.h"

using namespace std;
//getters for student
//return functions from Student.h

Student :: Student(char* first, char* last, int newId, float newgpa){

  strcpy(firstName, first);
  strcpy(lastName, last);

  studentID = newId;
  GPA = newgpa; 

}

Student::~Student(){
  //deconstructor which delete the array objects
  delete[] &firstName;
  delete[] &lastName; 
} 

char* Student::getFirstName() {
  return firstName;

}

char* Student::getLastName() {
  return lastName;
  
}

int Student::getStudentID() {
  return studentID;
}

float Student:: getGPA() {
  return GPA;

}
