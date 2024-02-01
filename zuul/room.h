
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <cstring>
#include <vector>





using namespace std;

struct Item{
  char name[10];
 Item(const char * item_name){
		strcpy(name, item_name);
        }
}; 

class Room{
 public:
                map<char, Room*> exits;//inputs info about inventory 
		vector<Item*> item_list;
                static char input[150]; 
		static vector <Item*> inventory;
		void printItem();
		Room* nextRoom();
		void pickItem(char * item_name);
		void printInv();
		static char * item_ptr;
		void dropItem(char * item_name);
		int i =0;
		int j=0;


}; 


#endif
