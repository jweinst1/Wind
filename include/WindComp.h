#ifndef WIND_COMP_H
#define WIND_COMP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "WindType.h"
#include "WindState.h"

#ifndef WindComp_BUF_SIZE
#define WindComp_BUF_SIZE 5000
#endif

unsigned char* WindComp_begin(void);
const unsigned char* WindComp_end(void);

unsigned WindComp_get_len(void);
void WindComp_set_len(unsigned length);

// Returns head byte marker of comp buffer.
unsigned char WindComp_get_head(void);

void WindComp_write(void* item, unsigned length);

/*Operation Methods*/
void WindComp_apply_not(void);

#endif
