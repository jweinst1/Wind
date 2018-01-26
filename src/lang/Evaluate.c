#include "Evaluate.h"

void Evaluate_out(WindStream* wstream, const char** code, EvalState* state)
{
        WindStream_out(wstream);
}

void Evaluate_push(WindStream* wstream, const char** code, EvalPush opt)
{
        while(!Evaluate_isSep(*code))
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
                case 'N':
                        switch((*code)[1])
                        {
                        case 'o':
                                switch((*code)[2])
                                {
                                case 'n':
                                        switch((*code)[3])
                                        {
                                        case 'e':
                                                *code += 4;
                                                if(opt == EvalPush_Right) WindStream_push(wstream, (WindObject*)WindNone_new());
                                                else WindStream_push_left(wstream, (WindObject*)WindNone_new());
                                                continue;
                                        default:
                                                WindErr_write(wstream, "Syntax Error: Unexpected token 'Non%c'.", (*code)[3]);
                                                return;
                                        }
                                        break;
                                default:
                                        WindErr_write(wstream, "Syntax Error: Unexpected token 'No%c'.", (*code)[2]);
                                        return;
                                }
                                break;
                        default:
                                WindErr_write(wstream, "Syntax Error: Unexpected token 'n%c'.", (*code)[1]);
                                return;
                        }
                default:
                        WindErr_write(wstream, "Syntax Error(push): Unexpected token '%c'.", **code);
                        return; // syntax error
                }
        }
}

void Evaluate_pop(WindStream* wstream, const char** code, EvalState* state)
{
        WindStream_remove_end(wstream);
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
                case 'a':
                        switch((*code)[1])
                        {
                        case 'd':
                                switch((*code)[2])
                                {
                                case 'd':
                                        *code += 3;
                                        Evaluate_push(wstream, code, EvalPush_Left);
                                        *state = EvalState_Separator;
                                        return;
                                default:
                                        WindErr_write(wstream, "Syntax Error: Unexpected token 'ad%c'.", (*code)[2]);
                                        return;
                                }
                                break;
                        default:
                                WindErr_write(wstream, "Syntax Error: Unexpected token 'a%c'.", (*code)[1]);
                                return;
                        }
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
                                        return;
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
                case 'p':
                        switch((*code)[1])
                        {
                        case 'o':
                                switch((*code)[2])
                                {
                                case 'p':
                                        *code += 3;
                                        Evaluate_pop(wstream, code, state);
                                        *state = EvalState_Separator;
                                        return;
                                default:
                                        WindErr_write(wstream, "Syntax Error: Unexpected token 'po%c'.", (*code)[2]);
                                        return;
                                }
                                break;
                        case 'u':
                                switch((*code)[2])
                                {
                                case 's':
                                        switch((*code)[3])
                                        {
                                        case 'h':
                                                *code += 4;
                                                Evaluate_push(wstream, code, EvalPush_Right);
                                                *state = EvalState_Separator;
                                                return;
                                        default:
                                                WindErr_write(wstream, "Syntax Error: Unexpected token 'pus%c'.", (*code)[3]);
                                                return;
                                        }
                                        break;
                                default:
                                        WindErr_write(wstream, "Syntax Error: Unexpected token 'pu%c'.", (*code)[2]);
                                        return;
                                }
                                break;
                        default:
                                WindErr_write(wstream, "Syntax Error: Unexpected token 'p%c'.", (*code)[1]);
                                return;
                        }
                        break;
                default:
                        WindErr_write(wstream, "Syntax Error(cmd): Unexpected token '%c'.", **code);
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
                        WindErr_write(wstream, "Syntax Error(sep): Unexpected token '%c'.", **code);
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
