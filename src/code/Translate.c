#include "Translate.h"
#include <string.h>

void Translate_err(WindObject* wobj)
{
        fprintf(stderr, "%s", wobj->error.mes);
        wobj->error.active = 0;
}
// will be handled in compile function
void Translate_transition(WindObject* wobj, char** srcCode)
{
        if(wobj->state == WindState_Transition)
        {
                *(wobj->insMark) = WindInstruc_Stop;
                wobj->insMark++;
                wobj->state = WindState_Execution;
        }

}

size_t Translate_str_len(WindObject* wobj, char** srcCode)
{
        size_t total = 0;
        unsigned char state = 1;
        char* srcPtr = *srcCode;
        while(state)
        {
                switch(*srcPtr)
                {
                case '"':
                        if(total > WindObject_INS_SIZE)
                        {
                                sprintf(wobj->error.mes, "String Error: String size of %lu too large as literal string.\n", total);
                                wobj->error.active = 1;
                                state = 0;
                                return 0;
                        }
                        return total;
                case '\0':
                        sprintf(wobj->error.mes, "String Error: Unexpected null found in string.\n");
                        wobj->error.active = 1;
                        state = 0;
                        return 0;
                default:
                        total++;
                        srcPtr++;
                }
        }
        return 0;
}

void Translate_cmd(WindObject* wobj, char** srcCode)
{
        size_t strSizeBlock = 0;
        TransState state = TransState_On;
        while(state)
        {
                if(Translate_BUF_CHECK(wobj))
                {
                        wobj->state = WindState_Transition;
                        state = TransState_Off;
                        return;
                }
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
                                *srcCode += 2; //moves in front of arrow
                                wobj->state = WindState_Transition;
                                state = TransState_Off;
                                return;
                        }
                        else
                        {
                                *srcCode += 1;
                                *(wobj->insMark) = WindInstruc_Sub;
                                wobj->insMark++;
                                break;
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
                        *(wobj->insMark) = WindInstruc_Int;
                        wobj->insMark++;
                        *(long*)(wobj->insMark) = strtol(*srcCode, srcCode, 10);
                        wobj->insMark += sizeof(long);
                        break;
                case '"':
                        // for string translation
                        *srcCode += 1;
                        *(wobj->insMark) = WindInstruc_Str;
                        wobj->insMark++;
                        strSizeBlock = Translate_str_len(wobj, srcCode);
                        if(wobj->error.active) return;
                        //writes size of string
                        memcpy(wobj->insMark, &strSizeBlock, sizeof(size_t));
                        wobj->insMark += sizeof(size_t);
                        //writes string data
                        memcpy(wobj->insMark, *srcCode, strSizeBlock);
                        *srcCode += strSizeBlock + 1;
                        wobj->insMark += strSizeBlock;

                        //writes null char
                        /**(wobj->insMark) = '\0';
                           wobj->insMark++;*/
                        break;
                case '+':
                        *srcCode += 1;
                        *(wobj->insMark) = WindInstruc_Add;
                        wobj->insMark++;
                        break;
                case '*':
                        *srcCode += 1;
                        *(wobj->insMark) = WindInstruc_Mul;
                        wobj->insMark++;
                        break;
                case 'i':
                        switch( *(*srcCode + 1) )
                        {
                        case 'n':
                                *srcCode += 2;
                                *(wobj->insMark) = WindInstruc_In;
                                wobj->insMark++;
                                break;
                        default:
                                sprintf(wobj->error.mes, "Syntax Error: Unexpected token 'i%c'.\n", *(*srcCode + 1));
                                wobj->error.active = 1;
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
                                        *(wobj->insMark) = WindInstruc_Out;
                                        wobj->insMark++;
                                        break;
                                default:
                                        sprintf(wobj->error.mes, "Syntax Error: Unexpected token 'ou%c'.\n", *(*srcCode + 2));
                                        wobj->error.active = 1;
                                        return;
                                }
                                break;
                        default:
                                sprintf(wobj->error.mes, "Syntax Error: Unexpected token 'o%c'.\n", *(*srcCode + 1));
                                wobj->error.active = 1;
                                return;
                        }
                        break;
                case '\0':
                        //end of src code reached
                        wobj->state = WindState_Done;
                        return;
                default:
                        sprintf(wobj->error.mes, "Syntax Error: Unexpected token '%c'.\n", **srcCode);
                        wobj->error.active = 1;
                        return;
                }
        }
}
