#include "Compiler.h"

void Compiler_process(WindObject* compiledCode, const char** srcCode)
{
        while(**srcCode)
        {
                switch(**srcCode)
                {

                }
        }
}

void Compiler_compile(WindObject* compiledCode, const char* srcCode)
{
        //signifies this is an instruction containing object.
        WindObject_PUT_BYTE(compiledCode, WindObjType_Instruction);
        while(*srcCode)
        {
                switch(*srcCode)
                {
                case ' ':
                case '\n':
                case '\t':
                case '\v':
                        srcCode++;
                        break;
                case '\0':
                        // Stops compiling at null char.
                        return;
                case '{':
                        // process handling.
                        srcCode++;
                        Compiler_process(compiledCode, &srcCode);
                        break;
                default:
                        // Needs error handling
                        return;
                }
        }
}
