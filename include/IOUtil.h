#ifndef IO_UTIL_H
#define IO_UTIL_H

#include "WindData.h"
#include "WindState.h"
#include "WindComp.h"
#include "WindRun.h"

#define IOUtil_REPL_PROMPT "wind> "

#ifndef IOUtil_REPL_SIZE
#define IOUtil_REPL_SIZE 512
#endif


// Prints a byte-marked sequence of Wind Values from start to end.
int IOUtil_print(const unsigned char* start, const unsigned char* end);

// Prints debug info about the state and data of Wind.
// Allows visualization of the buffers, error, state, command
void IOUtil_debug(void);

// Starts a read eval print loop.
void IOUtil_repl(void);


#endif
