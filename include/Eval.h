#ifndef WIND_EVAL_H
#define WIND_EVAL_H
// header for executing code on WindTuring

#include "WindObject.h"
#include "ByteBuf.h"
#include "Instruction.h"





// Enum bool to indicate whether or not the apply route is taken.
typedef enum
{
        EvalApply_False,
        EvalApply_True
} EvalApply;

// Validates start of expression call '()'
void Eval_validate_exp(unsigned char** data);

/*void Eval_sub(WindObject* obj, unsigned char** data, EvalApply apply);

   void Eval_add(WindObject* obj, unsigned char** data, EvalApply apply);*/

void Eval_load(WindObject* obj, unsigned char** data);

void Eval_code(WindObject* target, unsigned char* begin, unsigned char* end);


#endif
