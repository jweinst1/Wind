#ifndef WIND_RUN_H
#define WIND_RUN_H

#include <stdio.h>
#include "WindStream.h"
#include "WindExec.h"

// central header that handles running of code


int WindRun_exec(WindStream* ws, const char** code);

int WindRun_load(WindStream* ws, const char** code);

// Parses the source code for a command name.
// When found, does a goto to TRANS_TO_LOAD to switch state.
int WindRun_command(WindStream* ws, const char** code);

// Top level function that takes a stream and runs textual source code on it.
void WindRun_code(WindStream* ws, const char* code);

#endif
