#ifndef WIND_LOAD_H
#define WIND_LOAD_H

#include "WindType.h"
#include "WindData.h"


// Writes false bool to load buffer.
void WindLoad_false(void);

// Writes true bool to load buffer.
void WindLoad_true(void);

// Loads number onto load buffer.
void WindLoad_number(const char** code);

#endif
