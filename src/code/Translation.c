#include "Translation.h"

int Translate_src_command(const char** code, WindStream* ws)
{
        while(**code)
        {
                switch(**code)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        *code += 1;   //white space
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


int Translate_src_sep(const char** code, WindStream* ws)
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
                        ws->state = StreamState_command;
                        return 1;
                case '-':
                        if((*code)[1] == '>')
                        {
                                *code += 2;
                                ws->state = StreamState_command;
                                return 1;
                        }
                        else
                        {
                                WindStream_write_err(ws, "Expected separator ->, found '-%c'", (*code)[1]);
                                return 0; // error
                        }
                        break;
                default:
                        WindStream_write_err(ws, "Expected separator ->, found '%c'", (*code)[0]);
                        return 0;
                }
        }
        return 1;
}

void Translate_src_code(const char* code, WindStream* ws)
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
                case StreamState_sep:
                        Translate_src_sep(&code, ws);
                        break;
                case StreamState_command:
                        Translate_src_command(&code, ws);
                        break;
                }
        }
}
