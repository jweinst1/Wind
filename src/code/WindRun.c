#include "WindRun.h"

int WindRun_exec(WindStream* ws, const char** code)
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
        }
        WindStream_reset(ws, BufKey_load);
        ws->state = StreamState_command;
        return 1;
}

int WindRun_load(WindStream* ws, const char** code)
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
                case '|':
                        // pipe sep found
                        *code += 1;
                        goto TRANS_TO_EXEC;
                case '-':
                        if((*code)[1] == '>')
                        {
                                *code += 2;
                                goto TRANS_TO_EXEC;
                        }
                        else
                        {
                                WindStream_write_err(ws, "Expected separator ->, found '-%c'", (*code)[1]);
                                return 0;   // error
                        }
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
                                                WindStream_put(ws, BufKey_load, WindType_None);
                                                continue;
                                        default:
                                                WindStream_write_err(ws, "Expected argument or value, found 'Non%c'", *code[3]);
                                                return 0;
                                        }
                                        break;
                                default:
                                        WindStream_write_err(ws, "Expected argument or value, found 'No%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindStream_write_err(ws, "Expected argument or value, found 'N%c'", *code[1]);
                                return 0;
                        }
                        break;
                case '\0':
                        // source code ends
                        goto TRANS_TO_EXEC;
                default:
                        WindStream_write_err(ws, "Expected argument or value, found '%c'", **code);
                        return 0;
                }
        }
        goto TRANS_TO_EXEC;
TRANS_TO_EXEC:
        ws->state = StreamState_exec;
        return 1;
}

int WindRun_command(WindStream* ws, const char** code)
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
                case 'o':
                        switch((*code)[1])
                        {
                        case 'u':
                                switch((*code)[2])
                                {
                                case 't':
                                        // exec out
                                        *code += 3;
                                        ws->command = WindCommand_out;
                                        goto TRANS_TO_LOAD;
                                default:
                                        WindStream_write_err(ws, "Expected command symbol, found 'ou%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindStream_write_err(ws, "Expected command symbol, found 'o%c'", *code[1]);
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
                                                ws->command = WindCommand_push;
                                                goto TRANS_TO_LOAD;
                                        default:
                                                WindStream_write_err(ws, "Expected command symbol, found 'pus%c'", *code[3]);
                                                return 0;
                                        }
                                        break;
                                default:
                                        WindStream_write_err(ws, "Expected command symbol, found 'pu%c'", *code[2]);
                                        return 0;
                                }
                                break;
                        default:
                                WindStream_write_err(ws, "Expected command symbol, found 'p%c'", *code[1]);
                                return 0;
                        }
                        break;
                case '\0':
                        goto TRANS_TO_LOAD;
                default:
                        WindStream_write_err(ws, "Expected command symbol, found '%c'", **code);
                        return 0;
                }
        }
        goto TRANS_TO_LOAD;
TRANS_TO_LOAD:
        ws->state = StreamState_load;
        return 1;
}

void WindRun_code(WindStream* ws, const char* code)
{
        while(*code)
        {
                if(ws->hasErr)
                {
                        WindStream_print_err(ws);
                        return;
                }
                switch(ws->state)
                {
                case StreamState_command:
                        WindRun_command(ws, &code);
                        break;
                case StreamState_load:
                        WindRun_load(ws, &code);
                        break;
                case StreamState_exec:
                        WindRun_exec(ws, &code);
                        break;
                }
        }
        // Executes any lasting commands, if null char is reached first.
        if(ws->state == StreamState_exec) WindRun_exec(ws, &code);
}
