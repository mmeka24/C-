#include <iostream>
#include <cstring>

using namespace std; 

vector<Item*> Room::inventory;


void Room::printItem(){//prints items in room and picks up
        cout << "Items in room:"<<endl;
        for(auto i = item_list.begin(); i!=item_list.end(); ++i){
                cout << (*i)->name<<endl;
        }
        cout << "Type in the items you would like to pickup with commas separ\
ating. If you don't want to pick anything click enter."<<endl;
        cin.getline(input,150);
        item_ptr = strtok(input, ",");
        while(item_ptr){
                pickItem(item_ptr);
                item_ptr = strtok(NULL,",");
        }
}

Room* Room::nextRoom() {
    // Implementation here
}

void Room::pickItem(char* item_name) {
    // Implementation here
}

void Room::printInv() {
    // Implementation here
}

void Room::dropItem(char* item_name) {
    // Implementation here
}
