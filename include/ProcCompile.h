#ifndef PROC_COMPILE_H
#define PROC_COMPILE_H
//Header that compiles processes into instruction code.

#include <stdlib.h>
#include <stdio.h>
#include "Instructions.h"
#include "IntMap.h"

// Starting size for internal buffer made by prc compiler.
#define ProcCompile_BUF_SIZE 1000 * sizeof(unsigned char)

#define ProcCompile_STARTC '{'
#define ProcCompile_ENDC '}'

// Declares and initializes the byte buffer
#define ProcCompile_BUF(name) \
        unsigned char* name; \
        if((name = malloc(ProcCompile_BUF_SIZE) == NULL) { \
                fprintf(stderr, "%s\n", "Process Compile Error: Cannot allocate memory. Exiting"); \
                exit(1); \
        }


// macro used for resizing byte buffer
#define ProcCompile_RESIZE(buf, newSize) if((buf = realloc(buf, newSize)) == NULL) { \
        fprintf(stderr, "%s\n", "Process Compile Error: Cannot allocate memory. Exiting"); \
        exit(1); \
}

// Struct that captures error messages for the process compiler.
typedef struct
{
        char mes[256];
        int errState;
} ProcCompileErr;

// prints and resets the error of a process compile.
void ProcCompileErr_print(ProcCompileErr* prcErr);

// Compiles source code of process into byte instructions.
// Expands buf, but does not free or allocate it.
void ProcCompile_compile(const char** code);

#endif // PROC_COMPILE_H
