#include "Translate.h"

void Translate_arrow(WindExecutor* exec, char** srcCode)
{
        TransState state = TransState_On;
        while(state)
        {

        }
}

void Translate_unit(WindExecutor* exec, char** srcCode)
{
        TransState state = TransState_On;
        while(state)
        {
                switch(**srcCode)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        //white space
                        *srcCode += 1;
                        break;
                case 'i':
                        switch( *(*srcCode + 1) )
                        {
                        case 'n':
                                break;
                        default:
                                exec->state = ExecutorState_Err;
                                return;
                        }
                        break;
                case 'o':
                        break;
                default:
                        exec->state = ExecutorState_Err;
                        return;
                }
        }
}
