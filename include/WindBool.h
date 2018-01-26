#ifndef WIND_BOOL_H
#define WIND_BOOL_H

#include "WindObject.h"

typedef struct
{
        WindObject_BASE
        int state;
} WindBool;

// Creates a new WindBool object.
// @state: must be 0 or 1, false or true.
WindBool* WindBool_new(int state);

#endif // WIND_BOOL_H
