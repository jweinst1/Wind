#ifndef WIND_LOAD_H
#define WIND_LOAD_H

#include "WindType.h"
#include "WindData.h"


// Writes false bool to load buffer.
void WindLoad_false(void);

// Writes true bool to load buffer.
void WindLoad_true(void);

void WindLoad_none(void);

void WindLoad_sep(void);
void WindLoad_not(void);
void WindLoad_assign(void);
void WindLoad_plus(void);
void WindLoad_minus(void);
void WindLoad_del(void);
void WindLoad_lt(void);

// Loads number onto load buffer.
void WindLoad_number(const char** code);

#endif
