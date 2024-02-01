#pragma once

#include "media.h"

class music : public media {
public:
    music();
    char* get_creator();
    char* get_pub();
    char* get_dur();
};
