#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;





Student::~Student() {

}

char* Student::getFirst() {
    return firstName;
}

char* Student::getLast() {
    return lastName;
}

int Student::getId() {
    return Id;
}

float Student::getGpa() {
    return gpa;
}
