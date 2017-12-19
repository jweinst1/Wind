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
                                ByteBuf_write_byte(insBuf, WindInstruc_Apply);
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
                                ByteBuf_write_byte(insBuf, WindInstruc_Sub);
                                reader++;
                                break;
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
                case '#': // comments
                        reader++;
                        while(*reader != '\n') reader++;
                        break;
                case '@':
                        reader++;
                        ByteBuf_write_byte(insBuf, WindInstruc_Self);
                        break;
                case '"':
                        reader++;
                        ByteBuf_write_str(insBuf, &reader, WindInstruc_String);
                        break;
                case '.':
                        reader++;
                        ByteBuf_write_byte(insBuf, WindInstruc_Apply);
                        break;
                case '+':
                        reader++;
                        ByteBuf_write_byte(insBuf, WindInstruc_Add);
                        break;
                case '*':
                        reader++;
                        ByteBuf_write_byte(insBuf, WindInstruc_Mul);
                        break;
                case '/':
                        reader++;
                        ByteBuf_write_byte(insBuf, WindInstruc_Div);
                        break;
                case 'o':
                        if(reader[1] == 'u' && reader[2] == 't')
                        {
                                reader += 3;
                                ByteBuf_write_byte(insBuf, WindInstruc_Print);
                                break;
                        }
                        else
                        {
                                fprintf(stderr, "Syntax Error: Unexpected token: '%c%c%c'\n", *reader, reader[1], reader[2]);
                                exit(1);
                                return NULL;
                        }
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
