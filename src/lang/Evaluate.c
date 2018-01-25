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
                case '\0':
                        return;
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
                                        WindErr_write(wstream, "Syntax Error: Unexpected token 'ou%c'.", (*code)[2]);
                                        return;
                                }
                                break;
                        default:
                                WindErr_write(wstream, "Syntax Error: Unexpected token 'o%c'.", (*code)[1]);
                                return;
                        }
                        break;
                default:
                        WindErr_write(wstream, "Syntax Error: Unexpected token '%c'.", **code);
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
                case '\0':
                        return 0;
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
                                WindErr_write(wstream, "Syntax Error: Unexpected token '-%c'.", (*code)[1]);
                                return 0;
                        }
                        break;
                case '#':
                        //comment handler
                        while(**code != '\n') *code += 1;
                        break;
                default:
                        WindErr_write(wstream, "Syntax Error: Unexpected token '%c'.", **code);
                        return 0;
                }
        }
        return 0;
}

void Evaluate_code(WindStream* wstream, const char* code, EvalState* state)
{
        while(*code)
        {
                // Handles Error
                if(wstream->hasErr)
                {
                        WindErr_print(wstream);
                        return;
                }

                if(*state == EvalState_Separator) Evaluate_separator(wstream, &code, state);
                else Evaluate_command(wstream, &code, state);
        }

}
