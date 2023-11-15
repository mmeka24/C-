#include "music.h"

using namespace std;

char* music::get_creator() {
    return this->field_one;
}

char* music::get_dur() {
    return this->field_two;
}

char* music::get_pub() {
    return this->field_three;
}

music::music() {
    if (type == 0) {
        cout << "Enter the fields in the following format: title,artist,year,duration,publisher" << endl;
        cin.getline(response, 150);
        strcpy(title, strtok(response, ","));
        strcpy(field_one, strtok(NULL, ","));
        strcpy(year, strtok(NULL, ","));
        strcpy(field_two, strtok(NULL, ","));
        strcpy(field_three, strtok(NULL, ","));
    }
}




/*#include <iostream>
#include "music.h"
#include "media.h"
#include <cstring>
//#include "media.cpp"
using namespace std;
char * music::get_creator(){
	return this->field_one;
}
char * music::get_dur(){
	return this->field_two;
}
char * music::get_pub(){
	return this->field_three;
}
music::music(){
	if(type == 0){//constructor only calls if type matches
		cout << "Enter the fields in the following format: title,artist,year,duration,publisher"<<endl;
		cin.getline(response, 150);
		strcpy(title,strtok(response,","));
		strcpy(field_one, strtok(NULL,","));
		strcpy(year,strtok(NULL,","));
		strcpy(field_two, strtok(NULL,","));
		strcpy(field_three, strtok(NULL,","));
	}
	}*/
