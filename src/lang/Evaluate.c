#include "Evaluate.h"

void Evaluate_out(WindStream* wstream, const char** code, EvalState* state)
{
        WindStream_out(wstream);
}

void Evaluate_command(WindStream* wstream, const char** code, EvalState* state)
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
                case '#':
                        //comment handler
                        while(**code != '\n') *code += 1;
                        break;
                case 'o':
                        switch((*code)[1])
                        {
                        case 'u':
                                switch((*code)[2])
                                {
                                case 't':
                                        *code += 3;
                                        Evaluate_out(wstream, code, state);
                                        *state = EvalState_Separator;
                                        break;
                                default:
                                        // syntax error
                                        return;
                                }
                                break;
                        default:
                                //syntax error
                                return;
                        }
                        break;
                default:
                        return; // syntax error
                }
        }
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
                        while(**code != '\n') *code += 1;
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
                else Evaluate_command(wstream, &code, state);
        }

}
