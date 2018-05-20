#ifndef WIND_DATA_H
#define WIND_DATA_H

#include <stdio.h>
#include <stdlib.h>
// Header that defines static memory buffers for Wind language.
// These buffers are configurable in size depending on the platform Wind is needed for.

// defines size for the loading buffer.
// Can override during compile.
#ifndef WindData_LOAD_SIZE
#define WindData_LOAD_SIZE 100000
#endif

//defines size for the computational buffers.
// Can override during compile.
#ifndef WindData_BUF_SIZE
#define WindData_BUF_SIZE 100000
#endif

int WindData_active_state(void);
void WindData_active_switch(void);

const unsigned char*
WindData_active_begin(void);

const unsigned char*
WindData_active_end(void);

unsigned char* WindData_active_ptr(void);
// Non const pointer to beginning of active buffer.
unsigned char* WindData_active_start(void);

size_t WindData_active_space(void);
int WindData_active_is_full(void);
void WindData_active_reset(void);

// Returns a non-const pointer to start of load buffer.
// Can be used for reading or writing the contained data.
unsigned char* WindData_load_start(void);

const unsigned char*
WindData_load_begin(void);

const unsigned char*
WindData_load_end(void);

unsigned char*
WindData_load_ptr(void);

size_t WindData_load_space(void);
int WindData_load_is_full(void);
void WindData_load_reset(void);

// Safely advances the load ptr.
// If amount is larger than space available, advances to end of laod buffer.
void WindData_load_adv_safe(size_t amount);

// If amount is more than available space, prints error and exits.
void WindData_load_adv(size_t amount);

// Sets load ptr to place if place is valid address on load buffer range.
void WindData_load_set(unsigned char* place);






#endif
