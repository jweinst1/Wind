#ifndef WIND_VAL_H
#define WIND_VAL_H

#include <stdlib.h>
#include "WindType.h"

// Header that handles transformation of binary objects for mapping,
// filtering, reducing, copying, and more.
// Uses mostly pure unsigned char* buffers


// Copies <amnt> wind values from src to destination.
// Assumes sufficient space.
int WindVal_copy(unsigned char* dest, const unsigned char* src, int amnt);


#endif
