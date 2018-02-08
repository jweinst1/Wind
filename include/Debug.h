#ifndef WIND_DEBUG_H
#define WIND_DEBUG_H

#include <stdio.h>

// Prints out an enumerated selection of Process Instructions.
void Debug_process(unsigned char* bytes, int amount);

// Prints out an enumerated selection of raw bytes.
void Debug_bytes(unsigned char* bytes, int amount);


#endif // WIND_DEBUG_H
