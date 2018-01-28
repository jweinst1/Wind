#ifndef WIND_PROCESS_H
#define WIND_PROCESS_H
// Header that handles handles the wind process object

#include "WindObject.h"
#include "FixedMap.h"

// Enumuration over byte instructions
typedef enum
{
        WindInstruc_Add,
        WindInstruc_Sub
} WindInstruc;

// Wind process Object
typedef struct
{
        WindObject_BASE
} WindProcess;

#endif // WIND_PROCESS_H
