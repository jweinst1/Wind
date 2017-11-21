#ifndef WIND_EXECUTOR_H
#define WIND_EXECUTOR_H

#include <stdio.h>
#include "WindObject.h"

#define Executor_INS_SIZE 3000

#define Executor_INS_SPACE(exec) (exec->insEnd - exec->insMark)

#define Executor_OBJ_TYPE(exec) exec->object->type


enum ExecutorState
{
        ExecutorState_Err,
        ExecutorState_Unit,
        ExecutorState_Arrow
};

typedef enum ExecutorState ExecutorState;

// top level translation struct
// keeps track of the state of Wind execution, objects, and states
struct Executor
{
        unsigned char instructions[Executor_INS_SIZE];
        char err[256];
        unsigned char* insMark;
        unsigned char* insEnd;
        WindObject object;
        ExecutorState state;
};

typedef struct Executor Executor;




#endif
