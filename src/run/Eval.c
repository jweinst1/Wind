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
                break;
        case WindInstruc_Add:
                *data += 1;
                //evals the nested expression then loads it
                Eval_add(other, data);

                break;
        default:
                return; // needs error handling
        }
        // needs to load the first int
        while(**data != WindInstruc_ExpEnd)
        {
                switch(**data)
                {
                case WindInstruc_Int:
                        break;
                default:
                        break;
                }
        }
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
                        Eval_add(target, &reader);
                        break;
                default:
                        sprintf(err.mes, "Instruc Error: Unknown instruction %u\n", *reader);
                        goto EVAL_ERROR;
                }
        }
EVAL_ERROR:
        fprintf(stderr, err.mes);
        exit(1);
}
