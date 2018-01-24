#include "Evaluate.h"

int Evaluate_Command(WindStream* wstream, const char** code, EvalState* state)
{
        return 0;
}


int Evaluate_separator(WindStream* wstream, const char** code, EvalState* state)
{
        while(**code)
        {
                switch(**code)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        *code += 1;
                        break;
                case '-':
                        if((*code)[1] == '>')
                        {
                                *code += 2;
                                *state = EvalState_Command;
                                return 1;
                        }
                        else
                        {
                                // bad syntax error
                                return 0;
                        }
                        break;
                case '#':
                        //comment handler
                        break;
                default:
                        //bad syntax error or code is done
                        return 0;
                }
        }
        return 0;
}

void Evaluate_code(WindStream* wstream, const char* code, EvalState* state)
{
        while(*code)
        {
                if(*state == EvalState_Separator) Evaluate_separator(wstream, &code, state);
        }

}
