#ifndef WIND_EXEC_H
#define WIND_EXEC_H
// header for executing code on WindTuring

#include "WindTuring.h"
#include "ByteBuf.h"
#include "WindInfo.h"


#define Exec_CELL_EVAL(cell, state, data) while (state) { \
                switch(state) { \
                default: \
                } \
}


typedef enum
{
        ExecState_Stop,
        ExecState_Load,
        ExecState_NextIns,
        ExecState_Exec,
        ExecState_Adv,
        ExecState_Done
} ExecState;



int Exec_load(WindCell* cell, unsigned char** data);


void Exec_code(unsigned char* begin, unsigned char* end);


#endif
