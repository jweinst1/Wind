#ifndef WIND_LOAD_H
#define WIND_LOAD_H

#include "WindStream.h"

// This header takes care of loading items onto buffers in the stream
// It also handles parsing of text or code to extract values.


// Fast function to check if sep
static inline int
WindLoad_is_sep(const char* string)
{
        return *string == '|' || (*string == '-' && string[1] == '>')
}

// Function to parse argument segments of strings, after a command name
// example: push 5 4 True ->
// parses until ->
int WindLoad_values(WindStream* ws, int alt, const char** code);

#endif
