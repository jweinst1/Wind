#ifndef WIND_EVAL_H
#define WIND_EVAL_H
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

void Eval_sub(WindObject* obj, unsigned char** data);

void Eval_add(WindObject* obj, unsigned char** data);

void Eval_code(WindObject* target, unsigned char* begin, unsigned char* end);


#endif
