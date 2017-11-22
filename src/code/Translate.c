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
                                *srcCode += 2;
                                break;
                        default:
                                sprintf(exec->err, "Syntax Error: Unexpected token 'i%c'.\n", **srcCode);
                                exec->errMode = ExecutorError_active;
                                return;
                        }
                        break;
                case 'o':
                        break;
                default:
                        sprintf(exec->err, "Syntax Error: Unexpected token '%c'.\n", **srcCode);
                        exec->errMode = ExecutorError_active;
                        return;
                }
        }
}
