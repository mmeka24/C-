#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Student {
public:
    
   Student(char* first, char* last, int newid, float gpa);
  
    char* getFirst();
    char* getLast();
    int getId();
    float getGpa();
    ~Student();
private:
    char firstName[20]; 
    char lastName[20];
    float gpa;
    int Id;
};

#endif
