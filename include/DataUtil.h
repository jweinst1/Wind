#ifndef DATA_UTIL_H
#define DATA_UTIL_H

#include <string.h>
#include "WindType.h"

// This header handles utils to copy, move, and transport data from one unsigned char*
// to another

// Copies data from src to dest, until src End is reached.
int DataUtil_copy(unsigned char* dest,
                  const unsigned char* src,
                  const unsigned char* srcEnd);

#endif
