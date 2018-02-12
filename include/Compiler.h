#ifndef WIND_COMPILER_H
#define WIND_COMPILER_H
// Header that is responsible for compiling source code into instructions.

#include "WindObject.h"
#include "WindTypes.h"

#define COMPILER_DEF_SIZE 300

// Compiles a string of source code into instructions, loaded onto a WindObject.
WindObject* Compiler_compile(const char* srcCode);

#endif
