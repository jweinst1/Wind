#ifndef WIND_RUN_H
#define WIND_RUN_H

#include <stdio.h>
#include "WindStream.h"

// central header that handles running of code


int WindRun_exec(WindStream* ws, const char** code);

int WindRun_load(WindStream* ws, const char** code);

int WindRun_command(WindStream* ws, const char** code);

// Top level function that takes a stream and runs textual source code on it.
void WindRun_code(WindStream* ws, const char* code);

#endif
