#ifndef INSTRUCTION_BUF_H
#define INSTRUCTION_BUF_H
// Header that defines the instruction buffer used with the Wind Compiler.
// Uses a more specialized implementation than a generic byte array.

#include <stdlib.h>
#include <string.h>
#include "WindTypes.h"

// Starting size for the instruction buffer.
#define InstructionBuf_DEF_SIZE 200

#define InstructionBuf_ADDSPC 30

// Macro for allocating a default size of instruction buffer.
#define InstructionBuf_ALLOC malloc(sizeof(InstructionBuf) + (InstructionBuf_DEF_SIZE * sizeof(unsigned char)))
// Macro for creating a new ins buffer.
#define InstructionBuf_NEW(name) \
        InstructionBuf* name = InstructionBuf_ALLOC; \
        name->cap = InstructionBuf_DEF_SIZE; \
        name->len = 0

#define InstructionBuf_SIZE(ibuf) (ibuf->cap + (2* sizeof(size_t)))

#define InstructionBuf_SPACE(ibuf) (ibuf->cap - ibuf->len)
#define InstructionBuf_FULL(ibuf) (ibuf->cap == ibuf->len)
#define InstructionBuf_FITS(ibuf, size) ((ibuf->cap == ibuf->len) > size)

#define InstructionBuf_EXPAND(ibuf, amount) do { \
                ibuf = realloc(ibuf, ibuf->cap + amount + InstructionBuf_ADDSPC); \
                ibuf->cap += amount + InstructionBuf_ADDSPC; \
} while (0)

#define InstructionBuf_DEL(ibuf) free(ibuf)

// Writable pointer for ins buf.
#define InstructionBuf_WRITER(ibuf) (ibuf->ins + ibuf->len)



typedef struct
{
        size_t len;
        size_t cap;
        unsigned char ins[0];
} InstructionBuf;

#endif
