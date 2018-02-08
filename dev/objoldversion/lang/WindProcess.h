#ifndef WIND_PROCESS_H
#define WIND_PROCESS_H
// Header that handles handles the wind process object

#include <string.h>
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
        unsigned char* ins;
        size_t insSize;
} WindProcess;

WindProcess* WindProcess_new_empty(void);

#endif // WIND_PROCESS_H
