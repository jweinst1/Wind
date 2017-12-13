#ifndef WIND_EXEC_H
#define WIND_EXEC_H
// header for executing code on WindTuring

#include "WindTuring.h"
#include "ByteBuf.h"


typedef enum
{
        ExecState_Stop,
        ExecState_Go,
        ExecState_Next,
        ExecState_Err
} ExecState;

int Exec_load_ins(WindCell* cell, unsigned char* data);

void Exec_code(unsigned char* begin, unsigned char* end);


#endif
