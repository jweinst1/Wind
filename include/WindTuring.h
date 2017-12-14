#ifndef WIND_TURING_H
#define WIND_TURING_H

#include "WindObject.h"
#include "Instruction.h"
#include <stdlib.h>

// Size of tape for machine.
// Limits the maximum nested depth that can be computed.
#define WindTuring_CELL_SIZE 3000


typedef enum
{
        WindCellState_Dead,
        WindCellState_Load,
        WindCellState_Eval,
        WindCellState_Pause
} WindCellState;



// Structure for the machine's cells.
// @active = indicates whether or not the current
typedef struct
{
        WindObject obj;
        WindInstruc ins;
} WindCell;

// Functions for getting begin, head, and end of Turing Tape
WindCell* WindTuring_begin(void);
const WindCell* WindTuring_end(void);
WindCell* WindTuring_head(void);

int WindTuring_is_begin(WindCell* cell);
int WindTuring_is_end(WindCell* cell);
int WindTuring_is_head(WindCell* cell);

// Functions to move head up and down the tape.
void WindTuring_head_up(void);
void WindTuring_head_down(void);

void WindTuring_clear(void);

int WindTuring_full(void);

size_t WindTuring_from_begin(WindCell* cell);


#endif
