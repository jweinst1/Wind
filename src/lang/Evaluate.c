#include "Evaluate.h"

void Evaluate_code(WindStream* wstream, const char* code, EvalState* state)
{
        switch(*state)
        {
        case EvalState_Command:
                break;
        case EvalState_Separator:
                break;
        }
        while(*code)
        {
                switch(*code)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        // White Space
                        code++;
                        break;
                case '-':
                        break;
                }
        }
}
