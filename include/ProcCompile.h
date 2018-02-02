#ifndef PROC_COMPILE_H
#define PROC_COMPILE_H
//Header that compiles processes into instruction code.

#include <stdlib.h>
#include <stdio.h>
#include "Instructions.h"
#include "IntMap.h"

#define ProcCompile_STARTC '{'
#define ProcCompile_ENDC '}'

// macro used for resizing byte buffer
#define ProcCompile_RESIZE(buf, newSize) if((buf = realloc(buf, newSize)) == NULL) { \
                fprintf(stderr, "%s\n", "Process Compile Error: Cannot allocate memory. Exiting"); \
                exit(1); \
}

// Compiles source code of process into byte instructions.
// Expands buf, but does not free or allocate it.
void ProcCompile_compile(const char** code, unsigned char* buf, size_t bufSize);

#endif // PROC_COMPILE_H
