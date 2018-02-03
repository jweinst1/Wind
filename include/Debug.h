#ifndef WIND_DEBUG_H
#define WIND_DEBUG_H

#include "WindStream.h"
#include "WindBool.h"

void Debug_object(WindObject* wobj);

void Debug_stream(WindStream* wstream);

// Prints out a selection of bytes as an enumerated seqauence, e.g
// 0 -> 55
// 1 -> 100
// etc.....
void Debug_bytes(unsigned char* bytes, int amount);

#endif // WIND_DEBUG_H
