#ifndef WIND_EXEC_H
#define WIND_EXEC_H
// deals with translating and running code

#include <stdio.h>
#include "Executor.h"
#include "Instruction.h"

//resets instruction buffer for next translation
#define Exec_RESET_INS(wExec) wExec->insMark = wExec->instructions

//executes an in instruction
void Exec_in(WindExecutor* wExec, unsigned char** ins);

//executes an out instruction
void Exec_out(WindExecutor* wExec, unsigned char** ins);

// frees the current value
void Exec_free(WindExecutor* wExec);

//main level exec function
int Exec_exec(WindExecutor* wExec);


#endif
