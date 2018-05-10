#ifndef WIND_LOAD_H
#define WIND_LOAD_H

// Header that handles loading functions

#include "WindStream.h"

// Used for fast loading of booleans
static unsigned char WIND_BOOL_T[] = {WindType_Bool, 1};
static unsigned char WIND_BOOL_F[] = {WindType_Bool, 0};

void WindLoad_bool(WindStream* ws, BufKey bkey, int b);

#endif
