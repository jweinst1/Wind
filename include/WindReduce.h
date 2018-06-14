#ifndef WIND_REDUCE_H
#define WIND_REDUCE_H
// Header handles reducing functionality.

#include "WindData.h"
#include "WindState.h"
#include "WindComp.h"

// Handles reducing for + operation
int WindReduce_plus(void);

// Top level reduce function that is to be called by Windrun_command()
int WindReduce_reduce(void);

#endif
