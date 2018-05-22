#ifndef WIND_STATE_H
#define WIND_STATE_H

#include <stdio.h>
#include <stdarg.h>
#include "WindType.h"

// Header that handles errors and states of wind.

// Type that denotes state of data stream/flow
typedef enum
{
        WindModecommand,
        WindMode_load,
        WindMode_exec
} WindMode;

void WindState_write_err(const char* fmt, ...);

#endif
