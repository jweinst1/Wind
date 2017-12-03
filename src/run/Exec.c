#include "Exec.h"
#include <stdlib.h>
#include <string.h>

void Exec_add(WindObject* wobj, unsigned char** ins)
{
        unsigned char mode = 1;
        unsigned char* addPtr = *ins;
        size_t sizeHolder = 0;
        while(mode)
        {
                switch(*addPtr)
                {
                case WindInstruc_Int:
                        addPtr++;
                        if(wobj->type != WindType_Int)
                        {
                                wobj->error.active = 1;
                                sprintf(wobj->error.mes, "Type Error: Invalid type for '+'.\n");
                                return;
                        }
                        wobj->value._int += *((long*)(addPtr));
                        addPtr += sizeof(long);
                        break;
                case WindInstruc_Str:
                        if(wobj->type != WindType_Int)
                        {
                                wobj->error.active = 1;
                                sprintf(wobj->error.mes, "Type Error: Invalid type for '+'.\n");
                                return;
                        }
                        addPtr++;
                        sizeHolder = *(size_t*)addPtr;
                        addPtr += sizeof(size_t);

                        break;
                default:
                        wobj->error.active = 1;
                        sprintf(wobj->error.mes, "Type Error: Invalid type for '+'.\n");
                        return;
                }
        }
}

void Exec_in(WindObject* wobj, unsigned char** ins)
{
        // temp var to store size
        size_t inSizeVal = 0;
        switch (**ins)
        {
        case WindInstruc_Int:
                *ins +=1;
                wobj->type = WindType_Int;
                wobj->value._int = *((long*)(*ins));
                *ins += sizeof(long);
                return;
        case WindInstruc_Str:
                *ins += 1;
                inSizeVal = *((size_t*)(*ins));
                *ins += sizeof(size_t);
                WindStr_INIT_L(wobj->value._str, inSizeVal);

                // copies instruction bytes to windstr
                memcpy(wobj->value._str.begin, *ins, inSizeVal);
                *ins += inSizeVal;
                inSizeVal = 0;

                wobj->type = WindType_Str;
                break;
        default:
                wobj->error.active = 1;
                sprintf(wobj->error.mes, "Argument Error: Invalid argument for 'in'.\n");
                return;
        }
}

void Exec_out(WindObject* wobj, unsigned char** ins)
{
        switch(**ins)
        {
        //handling of optional arguments, reserved
        default:
                switch(wobj->type)
                {
                case WindType_None:
                        puts("None");
                        return;
                case WindType_Int:
                        printf("%ld\n", wobj->value._int);
                        return;
                case WindType_Str:
                        printf("\"%.*s\"\n", (int)WindStr_LEN_L(wobj->value._str), wobj->value._str.begin);
                        return;
                }
                return;
        }
}


void Exec_free(WindObject* wobj)
{
        switch(wobj->type)
        {
        case WindType_Str:
                WindStr_FREE_L(wobj->value._str);
                break;
        default:
                return;
        }
}


//top level executing function
int Exec_exec(WindObject* wobj)
{
        unsigned char* bytePtr = wobj->instructions;
        while(bytePtr != wobj->insEnd)
        {
                switch(*bytePtr)
                {
                case WindInstruc_In:
                        bytePtr++;
                        Exec_free(wobj);
                        Exec_in(wobj, &bytePtr);
                        break;
                case WindInstruc_Out:
                        bytePtr++;
                        Exec_out(wobj, &bytePtr);
                        break;
                case WindInstruc_Add:
                        bytePtr++;
                        Exec_add(wobj, &bytePtr);
                        break;
                case WindInstruc_Stop:
                        Exec_RESET_INS(wobj);
                        return 1;
                        break;
                default:
                        wobj->error.active = 1;
                        sprintf(wobj->error.mes, "Runtime Error: Invalid byte %u.\n", *bytePtr);
                        return 0; //error
                }
        }
        //resets instruction buffer for next translation
        Exec_RESET_INS(wobj);
        return 1;
}
