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
        default:
                return;
        }
}

void Eval_copy(WindObject* obj1, WindObject* obj2)
{
        switch(obj2->type)
        {
        case WindType_Int:
                obj1->type = WindType_Int;
                obj1->value._int = obj2->value._int;
                return;
        case WindType_Str:
                WindStr_from_size(obj1, WindStr_CAP(obj2));
                WindStr_over_write(obj1, WindStr_BEGIN(obj2), WindStr_LEN(obj2) + 1);
                return;
        default:
                return;
        }
}

void Eval_self(WindObject* obj1, WindObject* obj2)
{
        while(obj2->parent != NULL) obj2 = (WindObject*)obj2->parent;
        switch(obj2->type)
        {
        case WindType_Int:
                obj1->type = WindType_Int;
                obj1->value._int = obj2->value._int;
                return;
        case WindType_Str:
                WindStr_from_size(obj1, WindStr_CAP(obj2));
                WindStr_over_write(obj1, WindStr_BEGIN(obj2), WindStr_LEN(obj2) + 1);
                return;
        default:
                return;
        }
}

void Eval_load(WindObject* obj, unsigned char** data)
{
        EvalApply applState = EvalApply_False;
        WindObject other; // used for computation
        other.type = WindType_None;
        other.parent = (struct WindObject*)obj;
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
                *data+=1;
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
                                return; // needs error handle
                        default:
                                break;
                        }
                }
                *data += 1;
                break;
        case WindInstruc_Sub:
                *data += 1;
                Eval_validate_exp(data);
                if(!applState) Eval_load(obj, data);
                while(**data != WindInstruc_ExpEnd)
                {
                        Eval_load(&other, data);
                        if(other.type == WindType_Int) obj->value._int -= other.value._int;
                        else ErrMessage_write("Type Error: Can only call '-', sub on integers.");
                }
                *data += 1; // moves past expend
                break;
        case WindInstruc_Mul:
                *data += 1;
                Eval_validate_exp(data);
                if(!applState) Eval_load(obj, data);
                while(**data != WindInstruc_ExpEnd)
                {
                        Eval_load(&other, data);
                        if(other.type == WindType_Int) obj->value._int *= other.value._int;
                        else ErrMessage_write("Type Error: Can only call '*', mul on integers.");
                }
                *data += 1;         // moves past expend
                break;
        case WindInstruc_Div:
                *data += 1;
                Eval_validate_exp(data);
                if(!applState) Eval_load(obj, data);
                while(**data != WindInstruc_ExpEnd)
                {
                        Eval_load(&other, data);
                        // prevents divide by zero
                        if(other.type == WindType_Int) obj->value._int /= (other.value._int == 0 ? 1 : other.value._int);
                        else ErrMessage_write("Type Error: Can only call '/', div on integers.");
                }
                *data += 1;
                break;
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
                break;
        case WindInstruc_Self:
                *data += 1;
                //*obj = *(obj->parent);
                Eval_self(obj, (WindObject*)obj->parent);
                break;
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
        unsigned char* reader = begin;
        unsigned char** readHolder = &reader;
        while(*readHolder != end)
        {
                if(ErrMessage_active()) ErrMessage_terminate();
                Eval_load(target, readHolder);
        }
}
