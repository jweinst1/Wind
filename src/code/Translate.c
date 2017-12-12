#include "Translate.h"
#include <ctype.h>

ByteBuf* Translate_code(char* srcCode)
{
        ByteBuf* insBuf = ByteBuf_new(TRANS_BUF_SIZE);
        char* reader = srcCode;
        while (*reader)
        {
                switch(*reader)
                {
                // white space
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        reader++;
                        break;
                case '-':
                        if(reader[1] == '>')
                        {
                                ByteBuf_write_byte(insBuf, WindInstruc_Continue);
                                reader += 2;
                                break;
                        }
                        else if(isdigit(reader[1]))
                        {
                                ByteBuf_write_byte(insBuf, WindInstruc_Int);
                                ByteBuf_write_long(insBuf, strtol(reader, &reader, 10));
                                break;
                        }
                        else
                        {
                                fprintf(stderr, "Syntax Error: Unexpected token: '-%c'\n", *(reader + 1));
                                exit(1);
                                return NULL;
                        }
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
                        ByteBuf_write_byte(insBuf, WindInstruc_Int);
                        ByteBuf_write_long(insBuf, strtol(reader, &reader, 10));
                        break;
                case '(':
                        ByteBuf_write_byte(insBuf, WindInstruc_ExpStart);
                        reader++;
                        break;
                case ')':
                        ByteBuf_write_byte(insBuf, WindInstruc_ExpEnd);
                        reader++;
                        break;
                case '[':
                        ByteBuf_write_byte(insBuf, WindInstruc_ListStart);
                        reader++;
                        break;
                case ']':
                        ByteBuf_write_byte(insBuf, WindInstruc_ListEnd);
                        reader++;
                        break;
                case '"':
                        reader++;
                        ByteBuf_write_str(insBuf, &reader, WindInstruc_String);
                        break;
                case '.':
                        reader++;
                        ByteBuf_write_byte(insBuf, WindInstruc_Apply);
                        break;

                default:
                        fprintf(stderr, "Syntax Error: Unexpected token: '%c'\n", *reader);
                        exit(1);
                        return NULL;
                }
        }
        ByteBuf_write_byte(insBuf, WindInstruc_Stop);
        return insBuf;
}
