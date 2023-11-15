#pragma once
#include <iostream>
#include "music.h"
using namespace std;
class movie: public music{//inherit from music because fields are similar
	public:
		movie();//same constructor for all
		char * get_rating();
};
