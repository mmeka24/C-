/*
  Manasvi Meka
  Studentlist: program will save details to the memory and user can add, delete, and print students from the database.
  last updated: oct 16 2023

 */


#include<iostream>
#include<cstring>
#include<cmath> 
#include<vector> 
#include<iomanip>
#include<cstdlib>
#include<iomanip>


using namespace std;


//creating a struct for student
struct Student {
    char firstname[50];
    char lastname[50];
    int id;
    float gpa;
};

//function adds students
void addStudent(vector<Student*>& students) {
  Student* newStudent = new Student; // needs to be accessed from all func
    cout << "Enter the first name: " << endl;
    cin >> newStudent->firstname;
    cout << "Enter last name: " << endl;
    cin >> newStudent->lastname;
    cout << "enter student id: " << endl;
    cin >> newStudent -> id; 
    cout << "Enter GPA: " << endl;
    cin >> newStudent->gpa;
    students.push_back(newStudent);
}

//function print students 
void printStudents(vector<Student*>& students) {
    for (vector<Student*>::const_iterator i = students.begin(); i != students.end(); i++) {
      cout << (*i)->firstname << " " << (*i)->lastname << ", " << (*i)-> id << ", " ;
      cout << fixed << setprecision(2) << (*i) -> gpa << endl;
        
    }
}
//function deletes students
void deleteStudents(vector<Student*>&students){
  int deleteid;
  cout << "enter the student id number to delete" << endl;
  cin >> deleteid;
  for (vector<Student*>::const_iterator i = students.begin(); i != students.end(); i++){
    if ((*i) -> id == deleteid) {
      students.erase(i); 
      break; 

    } 

  } 

}



int main() {
    vector<Student*> students;
    bool running = true;
    char input[10];
    char add[10] = "ADD";
    char print[10] = "PRINT";
    char deletes[10] = "DELETE"; 
    char quit[10] = "QUIT";

    cout << "Welcome to Student List! You can add, delete, and print from the memory\n";
    cout << "To add, type 'ADD'; to Print, type 'PRINT'; and to quit the program, type 'QUIT'.\n\n";

    while (running) {
        cout << "Enter what you would like to do: ";
        cin >> input;

        if (strcmp(input, quit) == 0) {
	    cout << "Quitting\n";
            running = false;
        }
	else if (strcmp(input,deletes) == 0){
	  deleteStudents(students);
	  cout << "deleting the student \n";
	}
	else if (strcmp(input, add) == 0) {
            addStudent(students);
            cout << "Adding\n\n";
        } else if (strcmp(input, print) == 0) {
            printStudents(students);
        } else {
            cout << "Enter a valid option\n\n";
        }
    }


    return 0;
}
