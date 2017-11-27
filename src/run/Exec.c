#include "Exec.h"
#include <stdlib.h>
#include <string.h>

void Exec_in(WindExecutor* wExec, unsigned char** ins)
{
        switch (**ins)
        {
        case WindInstruc_Int:
                *ins +=1;
                wExec->object.type = WindType_Int;
                wExec->object.value._int = *((long*)(*ins));
                *ins += sizeof(long);
                return;
        /*case WindInstruc_Str:
         * ins += 1;
                wExec->object.type = WindType_Str;
                wExec->object.value._str = malloc(*((size_t*)(*ins)));
         * ins += sizeof(size_t);
                memcpy(&(wExec->object.value._str), (*ins + *((size_t*)(*ins))), *((size_t*)(*ins)));
         */
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
                        printf("\"%s\"\n", wExec->object.value._str);
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
                free(wExec->object.value._str);
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
