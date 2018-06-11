#ifndef WIND_RUN_H
#define WIND_RUN_H

#include <stdio.h>
#include "WindData.h"
#include "WindState.h"
#include "WindExec.h"
#include "WindLoad.h"

// central header that handles running of code

#define WindRun_COMMENT_SYM ';'


int WindRun_exec(const char** code);

int WindRun_load(const char** code);

// Parses the source code for a command name.
// When found, does a goto to TRANS_TO_LOAD to switch state.
int WindRun_command(const char** code);

// Runs the code as a complete portion of source code.
// Will execute any lasting commands and print any errors once
// the end of the string is reached.
void WindRun_code(const char* code);

// Runs the code as continuous incoming stream of code chunks
// Does not force lasting commands or print errors once a single code chunk is done.
void WindRun_continuous(const char* code);

#endif
