#include <iostream>
#include"room.cpp"
using namespace std;
int main(){
	Room* room;
	Room room_matrix[4][4];//4 by 4 matrix of rooms
	room_matrix[0][0].item_list.push_back(new Item("shovel"));//add items to 00
	room_matrix[0][0].item_list.push_back(new Item("bucket"));
	room_matrix[0][0].item_list.push_back(new Item("sock"));
	room_matrix[0][0].item_list.push_back(new Item("shoe"));	
	room_matrix[0][0].item_list.push_back(new Item("book"));
	for(int i = 0; i < 4; i++){
		for(int j = 0; j <4; j++){//move adjacent rooms to map
			if(i >0){
				room_matrix[i][j].exits.insert(pair<char,Room*>('N',&room_matrix[i-1][j]));
			}
			if(i <3){
				room_matrix[i][j].exits.insert(pair<char, Room*>('S',&room_matrix[i+1][j]));
			}
			if(j>0){
				room_matrix[i][j].exits.insert(pair<char,Room*>('W', &room_matrix[i][j-1]));
			}
			if(j<3){
				room_matrix[i][j].exits.insert(pair<char,Room*>('E', &room_matrix[i][j+1]));
			}
			room_matrix[i][j].i = i;
			room_matrix[i][j].j = j;
		}
	}
	room = &room_matrix[0][0];
	while(room){//head to next room
		room = room->nextRoom();
	}
	return 0;
}
