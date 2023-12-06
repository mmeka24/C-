#ifndef STUDENT_H
#define STUDENT_H



#include <iostream>
#include <cstring>



using namespace std;

class Student {
public:
    Student();
    void setID(int ids);
    int getID();
    void setFirstname(char* firstName);
     char* getFirstname();
    void setLastname(char* lastName);
    char* getLastname();
    void setGPA(double GPA);
    float getGPA();

private:
    char fname[20];
    char lname[20];
    float gpa;
    int id;
};

#endif
