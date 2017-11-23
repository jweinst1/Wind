#include "Exec.h"

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
        default:
                wExec->errMode = ExecutorError_active;
                sprintf(wExec->err, "Argument Error: Invalid argument for 'in'.\n");
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
                        Exec_in(wExec, &bytePtr);
                        break;
                default:
                        return 0; //error
                }
        }
        //resets instruction buffer for next translation
        Exec_RESET_INS(wExec);
        return 1;
}
