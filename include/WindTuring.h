#ifndef WIND_TURING_H
#define WIND_TURING_H

#include "WindObject.h"
#include "Instruction.h"
#include <stdlib.h>

// Size of tape for machine.
// Limits the maximum nested depth that can be computed.
#define WindTuring_CELL_SIZE 3000



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

int WindTuring_is_begin(WindCell* cell);
int WindTuring_is_end(WindCell* cell);
int WindTuring_is_head(WindCell* cell);

void WindTuring_head_up(void);
void WindTuring_head_down(void);

void WindTuring_clear(void);

int WindTuring_full(void);


#endif
