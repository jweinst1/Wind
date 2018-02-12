#include "Compiler.h"

WindObject* Compiler_compile(const char* srcCode)
{
        WindObject* compiledCode = WindObject_new_n(COMPILER_DEF_SIZE);
        return compiledCode;
}
