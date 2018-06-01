#ifndef WIND_COMP_H
#define WIND_COMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "WindType.h"
#include "WindState.h"

#ifndef WindComp_BUF_SIZE
#define WindComp_BUF_SIZE 500
#endif

unsigned char* WindComp_begin(void);
const unsigned char* WindComp_end(void);

unsigned WindComp_get_len(void);
void WindComp_set_len(unsigned length);

// Returns head byte marker of comp buffer.
unsigned char WindComp_get_head(void);

void WindComp_clear(void);
// Writes amount of length bytes from item
void WindComp_write(void* item, unsigned length);

// Writes a typed WindValue from item to the comp buffer.
// Returns amount of data written to comp.
// Returns 0 if an error.
unsigned WindComp_write_typed(unsigned char* item);

// Copies the entire item length to dest.
// Does not check for size of dest.
// Returns number of bytes written to dest.
unsigned WindComp_read(void* dest);

/*Operation Methods*/
void WindComp_apply_not(void);

// Maps an array of instructions onto the item in the comp buffer.
// Returns zero if error.
int WindComp_map(unsigned char* ins, const unsigned char* insEnd);

#endif
