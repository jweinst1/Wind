#ifndef WIND_FUNCTION_H
#define WIND_FUNCTION_H
// Header that handles handles the wind function object

#include "WindObject.h"
#include "FixedMap.h"

// Enumuration over byte instructions
typedef enum
{
        WindInstruc_Add,
        WindInstruc_Sub
} WindInstruc;

// Wind Functional Object
typedef struct
{
        WindObject_BASE
} WindFunction;

#endif // WIND_FUNCTION_H
