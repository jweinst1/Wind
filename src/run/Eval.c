#include "Eval.h"


void Eval_add(WindObject* obj, unsigned char** data)
{
        WindObject other;
        if(**data != WindInstruc_ExpStart) return; //needs error handling
        *data += 1;
        //loading

        switch(**data)
        {
        case WindInstruc_Int:
                obj->type = WindType_Int;
                *data += 1;
                obj->value._int = *(long*)(*data);
                *data += sizeof(long);
                goto EVAL_ADD_CALL;
        case WindInstruc_Add:
                *data += 1;
                //evals the nested expression then loads it
                Eval_add(&other, data);
                goto EVAL_ADD_LOAD_OTHER;
        default:
                return; // needs error handling
        }
EVAL_ADD_LOAD_OTHER:
        switch(other.type)
        {
        case WindType_Int:
                obj->type = WindType_Int;
                obj->value._int = other.value._int;
                goto EVAL_ADD_CALL;
        default:
                return;
        }
EVAL_ADD_CALL:
        // needs to load the first int
        while(**data != WindInstruc_ExpEnd)
        {
                switch(**data)
                {
                case WindInstruc_Int:
                        *data += 1;
                        obj->value._int += *(long*)(*data);
                        *data += sizeof(long);
                        break;
                case WindInstruc_Add:
                        *data += 1;
                        Eval_add(&other, data);
                        obj->type = other.type;
                        obj->value._int += other.value._int;
                        break;
                default:
                        return; // needs error handling.
                }
        }
        *data += 1;
        return;
}



// Main function for eval/executing instructions

void Eval_code(WindObject* target, unsigned char* begin, unsigned char* end)
{
        WindError err;
        target->type = WindType_None;

        unsigned char* reader = begin;
        while(reader != end)
        {
                switch(*reader)
                {
                case WindInstruc_Add:
                        reader++;
                        Eval_add(target, &reader);
                        break;
                case WindInstruc_Stop:
                        return;
                default:
                        sprintf(err.mes, "Instruc Error: Unknown instruction %u\n", *reader);
                        goto EVAL_ERROR;
                }
        }
EVAL_ERROR:
        fputs(err.mes, stderr);
        exit(1);
}
