#include "ProcCompile.h"

void ProcCompile_compile(const char* code, unsigned char* buf, size_t bufSize)
{
        unsigned char* bufEnd = buf + bufSize;
        while(*code)
        {
                switch(*code)
                {
                case ProcCompile_ENDC:
                        break;
                }
        }
}
