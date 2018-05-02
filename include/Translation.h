#ifndef WIND_TRANSLATION_H
#define WIND_TRANSLATION_H

#include <stdio.h>

// header that defines translation functions and utils

//enum to track what tokens the stream will accept next.
typedef enum
{
        StreamState_command,
        StreamState_sep
} StreamState;

int Translate_src_sep(const char** code, WindStream* ws, StreamState* state);

void Translate_src_code(const char* code, WindStream* ws, StreamState* state);


#endif
