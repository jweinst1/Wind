#ifndef WIND_DEBUG_H
#define WIND_DEBUG_H
//has a debug function for debugging a windobject

#include <stdio.h>
#include "WindObject.h"

#define Debug_START puts("_____WindObject________")

#define Debug_END puts("_____Debug_End________")

void Debug_obj(WindObject* wobj);

#endif
