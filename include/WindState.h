#ifndef WIND_STATE_H
#define WIND_STATE_H

#include <stdio.h>
#include <stdarg.h>
#include "WindType.h"

// Header that handles errors and states of wind.

// Type that denotes state of data stream/flow
typedef enum
{
        WindMode_command,
        WindMode_load,
        WindMode_exec
} WindMode;

void WindState_write_err(const char* fmt, ...);
int WindState_has_err(void);
void WindState_print_err(void);

void WindState_set_mode(WindMode mode);
WindMode WindState_get_mode(void);
void WindState_print_mode(void);

void WindState_set_cmd(WindCommand cmd);
WindCommand WindState_get_cmd(void);
int WindState_has_cmd(void);
void WindState_print_cmd(void);

#endif
