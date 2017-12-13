#ifndef WIND_INFO_H
#define WIND_INFO_H
//struct type to contain errors and execution info (variables)

#include "Instruction.h"

typedef struct
{
        char err[256];
        WindInstruc inst;
} WindInfo;



#endif
