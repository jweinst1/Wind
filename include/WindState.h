#ifndef WIND_STATE_H
#define WIND_STATE_H

#include <stdio.h>
#include "WindType.h"

// Header that handles errors and states of wind.

// Type that denotes state of data stream/flow
typedef enum
{
        WindState_command,
        WindState_load,
        WindState_exec
} WindState;

#endif
