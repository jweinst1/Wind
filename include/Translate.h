#ifndef WIND_TRANSLATE_H
#define WIND_TRANSLATE_H
//translates source code to instructions

#include <stdlib.h>
#include <ctype.h>
#include "Executor.h"

typedef enum {
        TransState_Off,
        TransState_On
} TransState;

//processes and prints a translation-time error
void Translate_err(WindExecutor* exec);

//function that finds the transition arrow and moves the src code there
void Translate_arrow(WindExecutor* exec, char** srcCode);

// Helper function that gets length of string.
size_t Translate_str_len(WindExecutor* exec, char** srcCode);

//function that translates src code from a unit into instructions
void Translate_unit(WindExecutor* exec, char** srcCode);

#endif
