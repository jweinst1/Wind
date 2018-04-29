#ifndef WIND_COMPILER_H
#define WIND_COMPILER_H
// Header that is responsible for compiling source code into instructions.

#include "WindObject.h"
#include "WindTypes.h"
#include "Intmap.h"

#define COMPILER_DEF_SIZE 300

// Handles the compilation of a Wind Process.
void Compiler_process(WindObject* compiledCode, const char** srcCode);

// Compiles a string of source code into instructions, loaded onto a WindObject.
void Compiler_compile(WindObject* compiledCode, const char* srcCode);

#endif
