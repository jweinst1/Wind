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

// Macro that adds two binary fmt numbers together.
#define WindComp_PLUS_NUM(val1, val2) *(double*)(val1) += *(double*)(val2)

#define WindComp_MINUS_NUM(val1, val2) *(double*)(val1) -= *(double*)(val2)

#define WindComp_MULTIPLY_NUM(val1, val2) *(double*)(val1) *= *(double*)(val2)

#define WindComp_LT_NUM(val1, val2) *(double*)(val1) < *(double*)(val2)

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
unsigned WindComp_write_typed(const unsigned char* item);

// Copies the entire item length to dest.
// Does not check for size of dest.
// Returns number of bytes written to dest.
unsigned WindComp_read(void* dest);

/*Operation Methods*/
void WindComp_apply_not(void);

unsigned WindComp_apply_plus(unsigned char* args, const unsigned char* argsEnd);

unsigned WindComp_apply_minus(unsigned char* args, const unsigned char* argsEnd);

unsigned WindComp_apply_multiply(unsigned char* args, const unsigned char* argsEnd);

/*/ filtering functions /*/

// Checks if item in comp buffer is true or false after NOT
int WindComp_check_not(void);

// Checks if item in comp buffer is less than arg.
// Unlike apply functions, this only supports a single argument.
int WindComp_check_lt(unsigned char** arg);

// Maps an array of instructions onto the item in the comp buffer.
// Returns zero if error.
int WindComp_map(unsigned char* ins, const unsigned char* insEnd);

// Filters the current active buffer values against a series of boolean conditions
// in the load buffer. The value is cleared from comp buffer if it fails filter test.
int WindComp_filter(unsigned char* ins, const unsigned char* insEnd);

#endif
