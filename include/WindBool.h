#ifndef WIND_BOOL_H
#define WIND_BOOL_H

#include "WindObject.h"

// Macro that casts a regular object to a boolean.
#define WindBool_CAST(wobj) ((WindBool*)wobj)

// Casts to WindBool then gets the state.
#define WindBool_STATE(wobj) ((WindBool*)wobj)->state

typedef struct
{
        WindObject_BASE
        int state;
} WindBool;

// Creates a new WindBool object.
// @state: must be 0 or 1, false or true.
WindBool* WindBool_new(int state);

#endif // WIND_BOOL_H
