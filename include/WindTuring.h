#ifndef WIND_TURING_H
#define WIND_TURING_H

#include "WindObject.h"
#include "Instruction.h"

// Size of tape for machine.
// Limits the maximum nested depth that can be computed.
#define WindTuring_CELL_SIZE 4000

typedef struct
{
        WindObject obj;
        WindInstruc ins;
} WindCell;

WindCell* WindTuring_begin(void);
const WindCell* WindTuring_end(void);
WindCell* WindTuring_head(void);

void WindTuring_head_up(void);
void WindTuring_head_down(void);

int WindTuring_full(void);


#endif
