#include "WindRun.h"

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
                        ws->state = StreamState_exec;
                        return 1;
                case '-':
                        if((*code)[1] == '>')
                        {
                                *code += 2;
                                ws->state = StreamState_exec;
                                return 1;
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
                                                //WindLoad_none(ws, bkey);
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
                        ws->state = StreamState_exec;
                        return 1;
                default:
                        WindStream_write_err(ws, "Expected argument or value, found '%c'", **code);
                        return 0;
                }
        }
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
                                        if(!WindExec_out(ws, BufKey_active)) return 0;
                                        ws->state = StreamState_sep;
                                        return 1;
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
                                                if(!WindLoad_from_str(ws, BufKey_active, code)) return 0;
                                                return 1;
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
                        // end of source code
                        return 1;
                default:
                        WindStream_write_err(ws, "Expected command symbol, found '%c'", **code);
                        return 0;
                }
        }
        return 1;
}

void WindRun_code(WindStream* ws, const char* code)
{
        while(*code)
        {
                switch(ws->state)
                {
                case StreamState_command:
                        break;
                case StreamState_load:
                        break;
                case StreamState_exec:
                        break;
                }
        }
}
