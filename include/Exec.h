#ifndef WIND_EXEC_H
#define WIND_EXEC_H
// header for executing code on WindTuring

#include "WindObject.h"
#include "ByteBuf.h"
#include "Instruction.h"

// Wind's Error Type.
typedef struct
{
        char mes[256];
        int active;
} WindError;


void Exec_add(WindObject* obj, unsigned char** data);

void Exec_code(unsigned char* begin, unsigned char* end);


#endif
