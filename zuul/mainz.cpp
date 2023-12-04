/*
manasvi meka 
zuul project 
description: there are 16 rooms created as a vector each coordinated is correlated to a room number. 
If all items are sent to room 33 or cordinate (3,3) then you have won. 
*/
#include <iostream>
#include <vector>
#include "room.h"

using namespace std;

int main() {
    Room* room;
    vector<vector<Room>> room_grid(4, vector<Room>(4));  // Vector of vectors of Room objects making a grid 

    // Adding items to coordinate 0,0 to pick items up 
    room_grid[0][0].item_list.push_back(new Item("comp"));
    room_grid[0][0].item_list.push_back(new Item("flower"));
    room_grid[0][0].item_list.push_back(new Item("phone"));
    room_grid[0][0].item_list.push_back(new Item("shoe"));
    room_grid[0][0].item_list.push_back(new Item("book"));

    // Connecting adjacent rooms in grid by looping through and assingning directons  
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i > 0) {
                room_grid[i][j].exits.insert(pair<char, Room*>('N', &room_grid[i - 1][j]));
            }
            if (i < 3) {
                room_grid[i][j].exits.insert(pair<char, Room*>('S', &room_grid[i + 1][j]));
            }
            if (j > 0) {
                room_grid[i][j].exits.insert(pair<char, Room*>('W', &room_grid[i][j - 1]));
            }
            if (j < 3) {
                room_grid[i][j].exits.insert(pair<char, Room*>('E', &room_grid[i][j + 1]));
            }
            room_grid[i][j].i = i;
            room_grid[i][j].j = j; // setting the coordinates
        }
    }

    // Setting initial room
    room = &room_grid[0][0];

    
    while (room) {
        room = room->nextRoom();  // Move to the next room

        // Check for win condition that is all items go to last grid vaue 3,3
        if (room && room->i == 3 && room->j == 3 && room->item_list.empty()) {
            cout << "Congratulations you won! You delivered all items to room 33!" << endl;
            room = nullptr;  // End game
        }
    }

    return 0;
}
