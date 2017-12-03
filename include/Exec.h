#ifndef WIND_EXEC_H
#define WIND_EXEC_H
// deals with translating and running code

#include <stdio.h>
#include "WindObject.h"
#include "Instruction.h"

//resets instruction buffer for next translation
#define Exec_RESET_INS(wobj) wobj->insMark = wobj->instructions

//executes an add instruction
void Exec_add(WindObject* wobj, unsigned char** ins);

//executes an in instruction
void Exec_in(WindObject* wobj, unsigned char** ins);

//executes an out instruction
void Exec_out(WindObject* wobj, unsigned char** ins);

// frees the current value
void Exec_free(WindObject* wobj);

//main level exec function
int Exec_exec(WindObject* wobj);


#endif
