#include "Exec.h"


//top level executing function
int Exec_exec(WindExecutor* wExec)
{
        unsigned char* bytePtr = wExec->instructions;
        while(bytePtr != wExec->insEnd)
        {
                switch(*bytePtr)
                {
                case WindInstruc_In:
                        break;
                default:
                        return 0; //error
                }
        }
        //resets instruction buffer for next translation
        Exec_RESET_INS(wExec);
        return 1;
}
