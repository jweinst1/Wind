#ifndef WIND_EXECUTOR_H
#define WIND_EXECUTOR_H

#include <stdio.h>
#include "WindObject.h"
#include "Instruction.h"

#define WindExecutor_INS_SIZE 3000

#define WindExecutor_INS_SPACE(exec) (exec->insEnd - exec->insMark)

#define WindExecutor_OBJ_TYPE(exec) exec->object->type

#define WindExecutor_INIT(name) \
        WindExecutor name; \
        name.insMark = name.instructions; \
        name.insEnd = name.insMark + WindExecutor_INS_SIZE; \
        name.object.type = WindType_None; \
        name.state = ExecutorState_Unit; \
        name.lastIns = WindInstruc_Nil;


enum ExecutorState
{
        ExecutorState_Err,
        ExecutorState_Unit,
        ExecutorState_Arrow
};

typedef enum ExecutorState ExecutorState;

// top level translation struct
// keeps track of the state of Wind execution, objects, and states
struct WindExecutor
{
        unsigned char instructions[WindExecutor_INS_SIZE];
        char err[256];
        unsigned char* insMark;
        unsigned char* insEnd;
        WindObject object;
        ExecutorState state;
        WindInstruc lastIns;
};

typedef struct WindExecutor WindExecutor;




#endif
