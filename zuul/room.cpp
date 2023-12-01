#include <iostream>
#include "room.h"
using namespace std;
char Room::input[150];
char *Room::item_ptr;
vector<Item*> Room::inventory;
void Room::printItem(){//prints items within room and prompts to pick up
	cout << "Items in room:"<<endl;
	for(auto i = item_list.begin(); i!=item_list.end(); ++i){
		cout << (*i)->name<<endl;
	}
	cout << "Type in the items you would like to pickup with commas separating(e.g. shirt,shovel,shoe). Don't want to pick anything? press enter."<<endl;
	cin.getline(input,150);
       	item_ptr = strtok(input, ",");
	while(item_ptr){
		pickItem(item_ptr);
		item_ptr = strtok(NULL,",");
	}
}
void Room::dropItem(char * item_name){//drop items by iterating through the inventory 
	for(auto i = inventory.begin(); i != inventory.end(); ++i){
		if(!strcmp(item_name, (*i)->name)){
			item_list.push_back(*i);
			inventory.erase(i); //dropping item means erasing from inventory adding to item list 
			i--;
		}
	}
}
void Room::pickItem(char * item_name){//pick up items with static inventory vector
	for(auto i = item_list.begin(); i != item_list.end();++i){
		if(!strcmp(item_name, (*i)->name)){
			inventory.push_back(*i);
			item_list.erase(i); //pick item is erasing from item list adding to inventory 
			i--;
		}
	}
}
void Room::printInv(){//print inventory and calls upons the drop inventory function 
  cout << "Items in Inventory: "<<endl; // Not = print item! 
	for(auto i = this->inventory.begin(); i!=inventory.end();++i){
		cout << (*i)->name<<endl;
	}
	cout << "Type in items you would like to drop with commas separating(e.g. shirt,shovel,shoe). If you would not like to drop anyhting then just press enter."<<endl;
	cin.getline(input,150);
	item_ptr = strtok(input, ",");
	while(item_ptr){
		dropItem(item_ptr);
		item_ptr = strtok(NULL, ",");
	}
}


Room* Room::nextRoom(){//goes to next room pick up drop and move between rooms
	cout << "You are in "<<i<<j<<endl;
	if(!inventory.empty()){
	  printInv();
	}
	if(j==i and j ==3 and item_list.size()==5){                                                                                                                                                                                cout << "You have succesfully delivered all the item to room 33!"<<endl;
		return NULL;
	}
	if(!item_list.empty()){
	  printItem();
	}
	for(map<char, Room*>::iterator itr = exits.begin(); itr!=exits.end();++itr){
	  cout << "Direction "<<itr->first << " Next Room "<<itr->second->i<<itr->second->j<<endl; 
	  //cout << itr->first << itr->second << itr->second << endl;

	}
	cout << "Type in the first letter for the direction of the room you want to go in(e.g N for North). If you would like to quit type Q."<<endl;
	cin >> input;
	cin.ignore(100, '\n');
	cin.clear();
	map<char, Room*>::iterator response = exits.find(input[0]);
     
	if(response!=exits.end()){
	  
	  return response->second;
	  
	}
	else if(input[0]=='Q'){
		return NULL;		
	}
	else{
		cout << "Invalid Option"<<endl;
		return nextRoom();
	}


}
