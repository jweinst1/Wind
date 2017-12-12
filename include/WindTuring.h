#ifndef WIND_TURING_H
#define WIND_TURING_H

#include "WindObject.h"
#include "Instruction.h"

// Size of tape for machine.
// Limits the maximum nested depth that can be computed.
#define WindTuring_CELL_SIZE 3000

#define WindCell_MAKE(cell, object, inst, state) do { \
                cell->obj = object; \
                cell->ins = inst; \
                cell->active = state; \
} while(0)


// Structure for the machine's cells.
// @active = indicates whether or not the current
typedef struct
{
        WindObject obj;
        WindInstruc ins;
        int active;
} WindCell;

WindCell* WindTuring_begin(void);
const WindCell* WindTuring_end(void);
WindCell* WindTuring_head(void);

void WindTuring_head_up(void);
void WindTuring_head_down(void);

int WindTuring_full(void);


#endif
