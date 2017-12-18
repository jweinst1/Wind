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

void Eval_cleanup(WindObject* obj)
{
        switch(obj->type)
        {
        case WindType_Str:
                free(obj->value._str.begin);
                obj->value._str.begin = NULL;
                return;
        case WindType_List:
                free(obj->value._lst.begin);
                obj->value._lst.begin = NULL;
                return;
        default:
                return;
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
        case WindInstruc_String:
                *data += 1;
                WindStr_from_ins(obj, data);
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
                        switch(obj->type)
                        {
                        case WindType_Int:
                                if(other.type == WindType_Int) obj->value._int += other.value._int;
                                else ErrMessage_write("Type Error: Can only add int to to type int.");
                                break; // needs error handle
                        case WindType_Str:
                                if(other.type == WindType_Str) WindStr_append(obj, &other);
                                else ErrMessage_write("Type Error: Can only add str to to type str.");
                                break; // needs error handle
                        default:
                                break;
                        }
                }
                *data += 1;
                return;
        case WindInstruc_Sub:
                *data += 1;
                Eval_validate_exp(data);
                if(!applState) Eval_load(obj, data);
                while(**data != WindInstruc_ExpEnd)
                {
                        Eval_load(&other, data);
                        obj->value._int -= other.value._int;
                }
                *data += 1; // moves past expend
                return;
        case WindInstruc_Mul:
                *data += 1;
                Eval_validate_exp(data);
                if(!applState) Eval_load(obj, data);
                while(**data != WindInstruc_ExpEnd)
                {
                        Eval_load(&other, data);
                        obj->value._int *= other.value._int;
                }
                *data += 1;         // moves past expend
                return;
        case WindInstruc_Div:
                *data += 1;
                Eval_validate_exp(data);
                if(!applState) Eval_load(obj, data);
                while(**data != WindInstruc_ExpEnd)
                {
                        Eval_load(&other, data);
                        // prevents divide by zero
                        obj->value._int /= (other.value._int == 0 ? 1 : other.value._int);
                }
                *data += 1;
                return;
        case WindInstruc_Print:
                // needs special object specific function for printing
                // only works for ints now
                *data += 1;
                Eval_validate_exp(data);
                if(!applState) Eval_load(obj, data);
                WindIO_print(obj); // receiving printed first due to apply possibility
                while(**data != WindInstruc_ExpEnd)
                {
                        Eval_load(&other, data);
                        WindIO_print(&other);
                }
                *data += 1;         // moves past expend
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
        // Cleans up other object used for computation
        Eval_cleanup(&other);
}


// Main function for eval/executing instructions

void Eval_code(WindObject* target, unsigned char* begin, unsigned char* end)
{
        target->type = WindType_None;
        unsigned char* reader = begin;
        unsigned char** readHolder = &reader;
        while(*readHolder != end)
        {
                if(ErrMessage_active()) ErrMessage_terminate();
                Eval_load(target, readHolder);
        }
}
