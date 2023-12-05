#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;

Student::Student() {
    cout << "creating student" << endl;
}

int Student::getID() const {
    return id;
}

void Student::setID(int ids) {
    id = ids;
}

void Student::setFirstname(const char* firstName) {
    strcpy(fname, firstName);
    
}

const char* Student::getFirstname() const {
    return fname;
}

void Student::setLastname(const char* lastName) {
    strcpy(lname, lastName);
    
}

const char* Student::getLastname() const {
    return lname;
}

void Student::setGPA(double GPA) {
    gpa = static_cast<float>(GPA);
}

float Student::getGPA() const {
    return gpa;
}
