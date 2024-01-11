#include <iostream>
#include "Student.h"

using namespace std;
//getters for student
//return functions from Student.h
Student::Student(char* first, char* last, int id, float gpa) {
  strcpy(firstName, first);
  strcpy(lastName, last);
  studentID = id;
  GPA = gpa;
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
