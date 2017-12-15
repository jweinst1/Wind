#include "Exec.h"


void Exec_add(WindObject* obj, unsigned char** data)
{
        WindObject other;
        if(**data != WindInstruc_ExpStart) return; //needs error handling
        *data += 1;
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

void Exec_code(unsigned char* begin, unsigned char* end)
{
        WindError err;
        WindObject result;
        result->type = WindType_None;

        unsigned char* reader = begin;
        while(reader != end)
        {
                switch(*reader)
                {
                case WindInstruc_Add:
                        Exec_add(&result, &reader);
                        break;
                default:
                        sprintf(err.mes, "Instruc Error: Unknown instruction %u\n", *reader);
                        goto EXEC_ERROR;
                }
        }
EXEC_ERROR:
        fprintf(stderr, err.mes);
        exit(1);
}
