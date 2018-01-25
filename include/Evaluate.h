#ifndef WIND_EVALUATE_H
#define WIND_EVALUATE_H
// Header that houses functions to evaluate source code into stream instructions.

#include <ctype.h>
#include "WindStream.h"
#include "WindErr.h"

// Macro to advance past whitespace.
#define Evaluate_WSPACE_ADV(string) while(isspace(*string)) string++

// State used for evaluating code on a stream.
typedef enum
{
        EvalState_Command,
        EvalState_Separator
} EvalState;

void Evaluate_out(WindStream* wstream, const char** code, EvalState* state);

// Handles the command evaluation state.
void Evaluate_command(WindStream* wstream, const char** code, EvalState* state);

// Handles the Sep evaluation state.
int Evaluate_separator(WindStream* wstream, const char** code, EvalState* state);

// Top level evaluator function
// Evaluates a string of code onto a stream.
void Evaluate_code(WindStream* wstream, const char* code, EvalState* state);

#endif // WIND_EVALUATE_H
