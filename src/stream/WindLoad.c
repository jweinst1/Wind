#include "WindLoad.h"

void WindLoad_none(WindStream* ws, BufKey bkey)
{
        WindStream_put(ws, bkey, WindType_None);
}

int WindLoad_from_str(WindStream* ws, BufKey bkey, const char** code)
{
        while(**code)
        {
                switch(**code)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        *code += 1;     //white space
                        break;
                case 'N':
                        switch(*code[1])
                        {
                        case 'o':
                                switch(*code[2])
                                {
                                case 'n':
                                        switch(*code[3])
                                        {
                                        case 'e':
                                                *code += 4;
                                                WindLoad_none(ws, bkey);
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

                        return 1;
                default:
                        WindStream_write_err(ws, "Expected argument or value, found '%c'", **code);
                        return 0;
                }
        }
        return 1;
}
