#pragma once

#include <iostream>
#include <cstring>

class media {
protected:
    char title[20], year[4], field_one[20], field_two[20], field_three[20];

public:
    static char response[150];
    static int type;

    virtual char* get_year();
    virtual char* get_title();
    virtual void print();
    virtual ~media();
};
