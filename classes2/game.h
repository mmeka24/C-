#pragma once
#include <iostream>
#include "movie.h"
#include <cstring>
using namespace std;
class game:public movie{//inherit from game 
	public:
		game();
		char *get_pub();
};
