#ifndef WIND_DEBUG_H
#define WIND_DEBUG_H

#include "WindStream.h"
#include "WindBool.h"
#include "Instructions.h"

void Debug_object(WindObject* wobj);

void Debug_stream(WindStream* wstream);

// Prints out an enumerated selection of Process Instructions.
void Debug_process(unsigned char* bytes, int amount);

// Prints out an enumerated selection of raw bytes.
void Debug_bytes(unsigned char* bytes, int amount);


#endif // WIND_DEBUG_H
