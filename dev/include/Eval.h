#ifndef WIND_EVAL_H
#define WIND_EVAL_H
// header for executing code on WindTuring

#include "WindObject.h"
#include "ByteBuf.h"
#include "Instruction.h"
#include "ErrMessage.h"
#include "WindStr.h"
#include "WindIO.h"





// Enum bool to indicate whether or not the apply route is taken.
typedef enum
{
        EvalApply_False,
        EvalApply_True
} EvalApply;

// Validates start of expression call '()'
void Eval_validate_exp(unsigned char** data);

void Eval_cleanup(WindObject* obj);
// copies obj2 into obj1.
void Eval_copy(WindObject* obj1, WindObject* obj2);

// makes a copy of the highest parent of obj2 into obj1.
void Eval_self(WindObject* obj1, WindObject* obj2);

void Eval_load(WindObject* obj, unsigned char** data);

void Eval_code(WindObject* target, unsigned char* begin, unsigned char* end);


#endif
