#ifndef WIND_EXEC_H
#define WIND_EXEC_H
// header for executing code on WindTuring

#include "WindTuring.h"
#include "ByteBuf.h"


typedef enum
{
        ExecState_Stop,
        ExecState_Load,
        ExecState_NextIns,
        ExecState_Exec,
        ExecState_Adv,
        ExecState_Done
} ExecState;



int Exec_load_ins(WindCell* cell, unsigned char** data);


void Exec_code(unsigned char* begin, unsigned char* end);


#endif
