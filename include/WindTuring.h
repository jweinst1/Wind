#ifndef WIND_TURING_H
#define WIND_TURING_H

#include "WindObject.h"

#define WindTuring_CELL_SIZE 4000

WindObject* WindTuring_begin(void);
const WindObject* WindTuring_end(void);

void WindTuring_head_up(void);
void WindTuring_head_down(void);


#endif
