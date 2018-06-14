#ifndef WIND_RUN_H
#define WIND_RUN_H

#include <stdio.h>
#include "WindData.h"
#include "WindState.h"
#include "WindExec.h"
#include "WindLoad.h"
#include "WindReduce.h"

// central header that handles running of code

#define WindRun_COMMENT_SYM ';'


int WindRun_exec(const char** code);

int WindRun_load(const char** code);

// Parses the source code for a command name.
// When found, does a goto to TRANS_TO_LOAD to switch state.
int WindRun_command(const char** code);

// Runs a string of code
// Will execute any lasting commands and print any errors once
// the end of the string is reached.
void WindRun_code(const char* code);

#endif
