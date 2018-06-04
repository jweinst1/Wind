#ifndef WIND_VAL_H
#define WIND_VAL_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "WindType.h"

// Header that handles transformation of binary objects for mapping,
// filtering, reducing, copying, and more.
// Also provides utilities for moving WindType pointers
// Uses mostly pure unsigned char* buffers

// Tool function to check if double is whole integer



// Copies binary wind values from src to dest, and moves pointers.
int WindVal_copy(unsigned char** dest, unsigned char** src, int amnt);

// Applies not operation to binary item.
// Accepts a double bytes pointer so it can be moved.
int WindVal_apply_not(unsigned char* item);

// Here inst is the load buffers loaded instructions.
int WindVal_apply_assign(unsigned char* item, unsigned char* inst);

// Advances the pointer pointer some amount of times, according to the WindType code.
int WindVal_move(unsigned char** item, int amnt);


#endif
