#ifndef WIND_VAL_H
#define WIND_VAL_H

#include <stdlib.h>
#include "WindType.h"

// Header that handles transformation of binary objects for mapping,
// filtering, reducing, copying, and more.
// Uses mostly pure unsigned char* buffers


// Copies <amnt> wind values from src to destination.
// Assumes sufficient space.
int WindVal_copy(unsigned char** dest, unsigned char** src, int amnt);

// Applies not operation to binary item.
// Accepts a double bytes pointer so it can be moved.
int WindVal_apply_not(unsigned char* item);

// Advances the pointer pointer some amount of times, according to the WindType code.
int WindVal_move(unsigned char** item, int amnt);


#endif
