#ifndef STUDENT_H
#define STUDENT_H



#include <iostream>
#include <cstring>



using namespace std;

class Student {
public:
    Student();
    void setID(int ids);
    int getID() const;
    void setFirstname(const char* firstName);
    const char* getFirstname() const;
    void setLastname(const char* lastName);
    const char* getLastname() const;
    void setGPA(double GPA);
    float getGPA() const;

private:
    char fname[20];
    char lname[20];
    float gpa;
    int id;
};

#endif
