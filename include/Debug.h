#ifndef WIND_DEBUG_H
#define WIND_DEBUG_H

#include "WindStream.h"

// Header that can print debug info for stream

// prints out debug styled info about data in a wind buf.
void Debug_buf(WindBuf* wb);

// prints a command string
void Debug_cmd(WindCommand cmd);

void Debug_stream(WindStream* ws);

#endif
