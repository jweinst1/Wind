#include "ProcCompile.h"
#include "ByteBuf.h"

void ProcCompileErr_print(ProcCompileErr* prcErr)
{
        fprintf(stderr, "%s\n", prcErr->mes);
        prcErr->errState = 0;
        prcErr->mes[0] = '\0';
}

unsigned char* ProcCompile_compile(const char** code)
{
        ByteBuf insBuf;
        ByteBuf_MAKE(insBuf);
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
                case ProcCompile_ENDC:
                        ByteBuf_write_byte(&insBuf, WindPrcIns_End);

                        break;
                }
        }
        // Returns the heap allocated buffer of instructions.
        return insBuf->begin;
}
