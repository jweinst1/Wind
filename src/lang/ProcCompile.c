#include "ProcCompile.h"

void ProcCompile_compile(const char** code, unsigned char* buf, size_t bufSize)
{
        unsigned char* bufEnd = buf + bufSize;
        unsigned char* bufMark = buf;
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

                        break;
                }
        }
}
