#include "media.h"

using namespace std;

char media::response[150];
int media::type = 0; //intializing the static var

//year and title are required fields for all media 
char* media::get_year() {
    return year;
}

char* media::get_title() {
    return title;
}

void media::print() {
    cout << "Title: " << title << endl;
    cout << "Year: " << year << endl;
    //printing out the field names other than just the title and year 
    if (strlen(field_one)) {
        cout << field_one << endl;
    }
    cout << field_two << endl;
    cout << field_three << endl;
}

media::~media() {
    cout << "Are you sure you want to delete?" << endl;
    print();
    cin.getline(response, 150);
    if (response[0] == 'y') {
        cout << "Deleted" << endl;
    } else {
        print();
        cout << "Please re-add" << endl;
    }
}
