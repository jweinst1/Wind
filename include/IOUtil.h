#ifndef IO_UTIL_H
#define IO_UTIL_H

#include "WindData.h"
#include "WindState.h"
#include "WindComp.h"


// Prints a byte-marked sequence of Wind Values from start to end.
int IOUtil_print(const unsigned char* start, const unsigned char* end);


void IOUtil_debug(void);


#endif
