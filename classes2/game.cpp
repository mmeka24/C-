#include <iostream>
#include <cstring>
#include "game.h"
#include "movie.h"
using namespace std;
game::game() : movie::movie(){
		cout << "Enter the fields in the following format with commas: title,year,publisher,rating. Without spaces!"<<endl;
		//using strtok to split the responses and store them as fields 
		cin.getline(response,150);
		strcpy(title,strtok(response,","));
		strcpy(year, strtok(NULL,","));
		strcpy(field_two, strtok(NULL,","));
		strcpy(field_three, strtok(NULL,","));
}
//getting the publisher 
char * game::get_pub(){
	return field_two;
}
