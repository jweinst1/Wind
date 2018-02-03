#include "ProcCompile.h"

void ProcCompileErr_print(ProcCompileErr* prcErr)
{
        fprintf(stderr, "%s\n", prcErr->mes);
        prcErr->errState = 0;
        prcErr->mes[0] = '\0';
}

void ProcCompile_compile(const char** code)
{
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
