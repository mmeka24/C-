#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;

Student::Student() {
    cout << "csst" << endl;
}

int Student::getID()  {
    return id;
}

void Student::setID(int ids) {
    id = ids;
}

void Student::setFirstname( char* firstName) {
    strcpy(fname, firstName);
    
}

 char* Student::getFirstname()  {
    return fname;
}

void Student::setLastname( char* lastName) {
    strcpy(lname, lastName);
    
}

 char* Student::getLastname()  {
    return lname;
}

void Student::setGPA(double GPA) {
    gpa = static_cast<float>(GPA);
}

float Student::getGPA()  {
    return gpa;
}
