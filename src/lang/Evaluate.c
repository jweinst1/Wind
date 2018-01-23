#include "Evaluate.h"


int Evaluate_separator(WindStream* wstream, const char** code, EvalState* state)
{
        const char* codePtr = *code;
        while(*codePtr)
        {
                switch(*codePtr)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        codePtr++;
                        break;
                case '-':
                        if(codePtr[1] == '>')
                        {
                                codePtr += 2;
                                // Moves source code pointer
                                *code = codePtr;
                                return 1;
                        }
                        else
                        {
                                *code = codePtr;
                                return 0;
                        }
                        break;
                default:
                        *code = codePtr;
                        return 0;
                }
        }
        return 0;
}

void Evaluate_code(WindStream* wstream, const char* code, EvalState* state)
{
        while(*code)
        {
                if(*state == EvalState_Separator) ;
        }

}
