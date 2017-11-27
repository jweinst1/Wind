#include "Exec.h"
#include <stdlib.h>
#include <string.h>

void Exec_in(WindExecutor* wExec, unsigned char** ins)
{
        // temp var to store size
        size_t inSizeVal = 0;
        switch (**ins)
        {
        case WindInstruc_Int:
                *ins +=1;
                wExec->object.type = WindType_Int;
                wExec->object.value._int = *((long*)(*ins));
                *ins += sizeof(long);
                return;
        case WindInstruc_Str:
                *ins += 1;
                inSizeVal = *((size_t*)(*ins));
                *ins += sizeof(size_t);
                WindStr_INIT_L(wExec->object.value._str, inSizeVal);

                // copies instruction bytes to windstr
                memcpy(wExec->object.value._str.begin, *ins, inSizeVal);
                *ins += inSizeVal;
                inSizeVal = 0;

                wExec->object.type = WindType_Str;
                break;
        default:
                wExec->errMode = ExecutorError_active;
                sprintf(wExec->err, "Argument Error: Invalid argument for 'in'.\n");
                return;
        }
}

void Exec_out(WindExecutor* wExec, unsigned char** ins)
{
        switch(**ins)
        {
        //handling of optional arguments, reserved
        default:
                switch(wExec->object.type)
                {
                case WindType_None:
                        puts("None");
                        return;
                case WindType_Int:
                        printf("%d\n", wExec->object.value._int);
                        return;
                case WindType_Str:
                        printf("\"%.*s\"\n", (int)WindStr_LEN_L(wExec->object.value._str), wExec->object.value._str.begin);
                        return;
                }
                return;
        }
}


void Exec_free(WindExecutor* wExec)
{
        switch(wExec->object.type)
        {
        case WindType_Str:
                WindStr_FREE_L(wExec->object.value._str);
                break;
        default:
                return;
        }
}


//top level executing function
int Exec_exec(WindExecutor* wExec)
{
        unsigned char* bytePtr = wExec->instructions;
        while(bytePtr != wExec->insEnd)
        {
                switch(*bytePtr)
                {
                case WindInstruc_In:
                        bytePtr++;
                        Exec_free(wExec);
                        Exec_in(wExec, &bytePtr);
                        break;
                case WindInstruc_Out:
                        bytePtr++;
                        Exec_out(wExec, &bytePtr);
                        break;
                case WindInstruc_Stop:
                        Exec_RESET_INS(wExec);
                        return 1;
                        break;
                default:
                        wExec->errMode = ExecutorError_active;
                        sprintf(wExec->err, "Runtime Error: Invalid byte %u.\n", *bytePtr);
                        return 0; //error
                }
        }
        //resets instruction buffer for next translation
        Exec_RESET_INS(wExec);
        return 1;
}
