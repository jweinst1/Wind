#ifndef WIND_DATA_H
#define WIND_DATA_H

#include <stdio.h>
#include <stdlib.h>
// Header that defines static memory buffers for Wind language.
// These buffers are configurable in size depending on the platform Wind is needed for.

// defines size for the loading buffer.
#ifndef WindData_LOAD_SIZE
#define WindData_LOAD_SIZE 100000
#endif

//defines size for the computational buffers.
#ifndef WindData_BUF_SIZE
#define WindData_BUF_SIZE 100000
#endif

int WindData_active_state(void);
void WindData_active_switch(void);

const unsigned char*
WindData_load_begin(void);

const unsigned char*
WindData_load_end(void);

unsigned char*
WindData_load_ptr(void);

size_t WindData_load_space(void);
void WindData_load_reset(void);
void WindData_load_adv_safe(size_t amount);




#endif
