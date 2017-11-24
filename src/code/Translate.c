#include "Translate.h"
#include <string.h>

void Translate_err(WindExecutor* exec)
{
        fprintf(stderr, "%s", exec->err);
        exec->errMode = ExecutorError_dead;
}

void Translate_arrow(WindExecutor* exec, char** srcCode)
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
                        *srcCode += 1;
                        break;
                case '-':
                        if(*(*srcCode + 1) == '>')
                        {
                                // arrow found, state transition
                                *srcCode += 2;
                                //writes stop ins
                                *(exec->insMark) = WindInstruc_Stop;
                                exec->insMark++;

                                exec->state = ExecutorState_Translation;
                                state = TransState_Off;
                                return;
                        }
                        else
                        {
                                exec->errMode = ExecutorError_active;
                                sprintf(exec->err, "Syntax Error: Expected ->, found '-%c'.\n", **srcCode);
                                return;
                        }
                default:
                        exec->errMode = ExecutorError_active;
                        sprintf(exec->err, "Syntax Error: Expected ->, found '%c'.\n", **srcCode);
                        return;
                }
        }
}

size_t Translate_str_len(WindExecutor* exec, char** srcCode)
{
        size_t total = 0;
        unsigned char state = 1;
        char* srcPtr = *srcCode;
        while(state)
        {
                switch(*srcPtr)
                {
                case '"':
                        return total;
                case '\0':
                        sprintf(exec->err, "String Error: Unexpected null found in string.\n");
                        exec->errMode = ExecutorError_active;
                        state = 0;
                        return 0;
                default:
                        total++;
                        srcPtr++;
                }
        }
        return 0;
}

void Translate_unit(WindExecutor* exec, char** srcCode)
{
        size_t strSizeBlock = 0;
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
                // number or stop
                case '-':
                        if( *(*srcCode + 1) == '>')
                        {
                                state = TransState_Off;
                                return;
                        }
                // numbers
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                        *(exec->insMark) = WindInstruc_Int;
                        exec->insMark++;
                        WindExecutor_DEREF_INS(exec, long) = strtol(*srcCode, srcCode, 10);
                        exec->insMark += sizeof(long);
                        break;
                case '"':
                        *srcCode += 1;
                        *(exec->insMark) = WindInstruc_Str;
                        exec->insMark++;

                        strSizeBlock = Translate_str_len(exec, srcCode);
                        if(exec->errMode) return;
                        memcpy(exec->insMark, *srcCode, strSizeBlock);

                        *srcCode += strSizeBlock + 1;
                        exec->insMark += strSizeBlock;
                        *(exec->insMark) = '\0';
                        exec->insMark++;
                        break;
                case 'i':
                        switch( *(*srcCode + 1) )
                        {
                        case 'n':
                                *srcCode += 2;
                                *(exec->insMark) = WindInstruc_In;
                                exec->insMark++;
                                break;
                        default:
                                sprintf(exec->err, "Syntax Error: Unexpected token 'i%c'.\n", *(*srcCode + 1));
                                exec->errMode = ExecutorError_active;
                                return;
                        }
                        break;
                case 'o':
                        switch( *(*srcCode + 1) )
                        {
                        case 'u':
                                switch( *(*srcCode + 2) )
                                {
                                case 't':
                                        *srcCode += 3;
                                        *(exec->insMark) = WindInstruc_Out;
                                        exec->insMark++;
                                        break;
                                default:
                                        sprintf(exec->err, "Syntax Error: Unexpected token 'ou%c'.\n", *(*srcCode + 2));
                                        exec->errMode = ExecutorError_active;
                                        return;
                                }
                                break;
                        default:
                                sprintf(exec->err, "Syntax Error: Unexpected token 'o%c'.\n", *(*srcCode + 1));
                                exec->errMode = ExecutorError_active;
                                return;
                        }
                        break;
                case '\0':
                        //end of srcCode reached.
                        return;
                default:
                        sprintf(exec->err, "Syntax Error: Unexpected token '%c'.\n", **srcCode);
                        exec->errMode = ExecutorError_active;
                        return;
                }
        }
}
