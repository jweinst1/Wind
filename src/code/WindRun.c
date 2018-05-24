#include <ctype.h>
#include "WindRun.h"

int WindRun_exec(const char** code)
{
        switch(ws->command)
        {
        case WindCommand_null:
                break;
        case WindCommand_out:
                WindExec_out(ws, BufKey_active);
                break;
        case WindCommand_push:
                WindExec_push(ws);
                break;
        case WindCommand_clr:
                WindExec_clr(ws);
                break;
        case WindCommand_map:
                WindExec_map(ws);
                break;
        }
        WindState_set_cmd(WindCommand_out);
        WindState_set_mode(WindMode_command);
        return 1;
}

int WindRun_load(const char** code)
{
        while(**code)
        {
                switch(**code)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        *code += 1; //white space
                        break;
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
                        WindLoad_number(ws->loadBuf, code);
                        continue;
                case '-':
                        if((*code)[1] == '>')
                        {
                                *code += 2;
                                goto TRANS_TO_EXEC;
                        }
                        else if(isdigit((*code)[1]))
                        {
                                WindLoad_number(ws->loadBuf, code);
                        }
                        else
                        {
                                WindState_write_err("Expected separator ->, found '-%c'", (*code)[1]);
                                return 0;   // error
                        }
                        continue;
                case '|':
                        *code += 1;
                        WindStream_put(ws, BufKey_load, WindType_Sep);
                        continue;
                case '!':
                        // not :symbol
                        *code += 1;
                        WindStream_put(ws, BufKey_load, WindType_Not);
                        continue;
                case '=':
                        // assign :symbol
                        *code += 1;
                        WindStream_put(ws, BufKey_load, WindType_Assign);
                        continue;
                case 'T':
                        if((*code)[1] == 'r' && (*code)[2] == 'u' && (*code)[3] == 'e')
                        {
                                *code += 4;
                                WindLoad_bool(ws, BufKey_load, 1);
                                continue;
                        }
                        else
                        {
                                WindState_write_err("Expected argument or value, found 'T%c'", *code[1]);
                                return 0;
                        }
                        break;
                case 'F':
                        if((*code)[1] == 'a' && (*code)[2] == 'l' && (*code)[3] == 's' && (*code)[4] == 'e')
                        {
                                *code += 5;
                                WindLoad_bool(ws, BufKey_load, 0);
                                continue;
                        }
                        else
                        {
                                WindState_write_err("Expected argument or value, found 'F%c'", *code[1]);
                                return 0;
                        }
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
                                                //WindStream_put(ws, BufKey_load, WindType_None);
                                                continue;
                                        default:
                                                WindState_write_err("Expected argument or value, found 'Non%c'", *code[3]);
                                                return 0;
                                        }
                                        break;
                                default:
                                        WindState_write_err("Expected argument or value, found 'No%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindState_write_err( "Expected argument or value, found 'N%c'", *code[1]);
                                return 0;
                        }
                        break;
                case '\0':
                        // source code ends
                        goto TRANS_TO_EXEC;
                default:
                        WindState_write_err("Expected argument or value, found '%c'", **code);
                        return 0;
                }
        }
        goto TRANS_TO_EXEC;
TRANS_TO_EXEC:
        ws->state = StreamState_exec;
        return 1;
}

int WindRun_command(const char** code)
{
        while(**code)
        {
                switch(**code)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        *code += 1; //white space
                        break;
                case 'c':
                        switch((*code)[1])
                        {
                        case 'l':
                                switch((*code)[2])
                                {
                                case 'r':
                                        // exec out
                                        *code += 3;
                                        WindState_set_cmd(WindCommand_clr);
                                        goto TRANS_TO_LOAD;
                                default:
                                        WindState_write_err("Expected command symbol, found 'cl%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindState_write_err("Expected command symbol, found 'c%c'", *code[1]);
                                return 0;
                        }
                        break;
                case 'm':
                        switch((*code)[1])
                        {
                        case 'a':
                                switch((*code)[2])
                                {
                                case 'p':
                                        // exec out
                                        *code += 3;
                                        WindState_set_cmd(WindCommand_map);
                                        goto TRANS_TO_LOAD;
                                default:
                                        WindState_write_err("Expected command symbol, found 'ma%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindState_write_err("Expected command symbol, found 'm%c'", *code[1]);
                                return 0;
                        }
                        break;
                case 'o':
                        switch((*code)[1])
                        {
                        case 'u':
                                switch((*code)[2])
                                {
                                case 't':
                                        // exec out
                                        *code += 3;
                                        WindState_set_cmd(WindCommand_out);
                                        goto TRANS_TO_LOAD;
                                default:
                                        WindState_write_err("Expected command symbol, found 'ou%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindState_write_err("Expected command symbol, found 'o%c'", *code[1]);
                                return 0;
                        }
                        break;
                case 'p':
                        switch((*code)[1])
                        {
                        case 'u':
                                switch((*code)[2])
                                {
                                case 's':
                                        switch((*code)[3])
                                        {
                                        case 'h':
                                                *code += 4;
                                                WindState_set_cmd(WindCommand_push);
                                                goto TRANS_TO_LOAD;
                                        default:
                                                WindState_write_err("Expected command symbol, found 'pus%c'", *code[3]);
                                                return 0;
                                        }
                                        break;
                                default:
                                        WindState_write_err("Expected command symbol, found 'pu%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindState_write_err("Expected command symbol, found 'p%c'", *code[1]);
                                return 0;
                        }
                        break;

                case '\0':
                        goto TRANS_TO_LOAD;
                default:
                        WindState_write_err("Expected command symbol, found '%c'", **code);
                        return 0;
                }
        }
        goto TRANS_TO_LOAD;
TRANS_TO_LOAD:
        WindState_set_mode(WindMode_load);
        return 1;
}

void WindRun_code(const char* code)
{
        while(*code)
        {
                if(WindState_has_err())
                {
                        WindState_print_err();
                        return;
                }
                switch(WindState_get_cmd())
                {
                case WindMode_command:
                        WindRun_command(ws, &code);
                        break;
                case WindMode_load:
                        WindRun_load(ws, &code);
                        break;
                case WindMode_exec:
                        WindRun_exec(ws, &code);
                        break;
                }
        }
        // Executes any lasting commands, if null char is reached first.
        if(WindState_has_cmd()) WindRun_exec(ws, &code);
        if(WindState_has_err())
        {
                WindState_print_err();
                return;
        }
}
