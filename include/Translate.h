#ifndef WIND_TRANSLATE_H
#define WIND_TRANSLATE_H
//translates source code to instructions

#include <stdlib.h>
#include <ctype.h>
#include "Executor.h"

#define Translate_BUF_CHECK(exec) exec->insMark > (exec->insEnd - 10)

// helper
typedef enum {
        TransState_Off,
        TransState_On
} TransState;

//processes and prints a translation-time error
void Translate_err(WindExecutor* exec);

//function responsible for transitioning to execution
void Translate_transition(WindExecutor* exec, char** srcCode);

// Helper function that gets length of string.
size_t Translate_str_len(WindExecutor* exec, char** srcCode);

//function that translates src code from a unit into instructions
void Translate_unit(WindExecutor* exec, char** srcCode);

#endif
