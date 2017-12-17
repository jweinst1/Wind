#include "Eval.h"

void Eval_validate_exp(unsigned char** data)
{
        if(**data == WindInstruc_ExpStart) *data += 1;
        else
        {
                fprintf(stderr, "Call Error: Symbol %c not followed by '('. ", *(*data - 1));
                exit(1);
        }
}

void Eval_load(WindObject* obj, unsigned char** data)
{
        EvalApply applState = EvalApply_False;
        WindObject other; // used for computation
        goto LOAD_BRANCH;
LOAD_BRANCH:
        switch(**data)
        {
        case WindInstruc_Int:
                *data += 1;
                obj->value._int = *(long*)(*data);
                obj->type = WindType_Int;
                *data += sizeof(long);
                return;
        case WindInstruc_Add:
                *data += 1;
                Eval_validate_exp(data);
                // Loads first object into target if apply off
                if(!applState) Eval_load(obj, data);
                // Ensures nothing happens if no arguments to call.
                while(**data != WindInstruc_ExpEnd)
                {
                        // loads nested data onto stack-allocated WindObject
                        Eval_load(&other, data);
                        // Needs a function to facilitate 1 to 1 Add.
                        obj->value._int += other.value._int;
                }
                *data += 1;
                return;
        case WindInstruc_Sub:
                *data += 1;
                Eval_validate_exp(data);
                // Loads first object into target if apply off
                if(!applState) Eval_load(obj, data);
                // Ensures nothing happens if no arguments to call.
                while(**data != WindInstruc_ExpEnd)
                {
                        // loads nested data onto stack-allocated WindObject
                        Eval_load(&other, data);
                        // Needs a function to facilitate 1 to 1 Add.
                        obj->value._int -= other.value._int;
                }
                *data += 1; // moves past expend
                return;
        case WindInstruc_Apply:
                *data += 1;
                applState = EvalApply_True;
                // Turns on apply for the duration of this load call.
                goto LOAD_BRANCH;
        case WindInstruc_Stop:
                *data +=1;
                return;
        default:
                fprintf(stderr, "Load Error: Unknown Instruction %u.\n", **data);
                exit(1);

        }
}


// Main function for eval/executing instructions

void Eval_code(WindObject* target, unsigned char* begin, unsigned char* end)
{
        target->type = WindType_None;
        unsigned char* reader = begin;
        unsigned char** readHolder = &reader;
        while(*readHolder != end)
        {
                Eval_load(target, readHolder);
        }
}
