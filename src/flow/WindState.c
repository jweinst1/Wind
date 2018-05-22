#include "WindState.h"

// Buffer to keep error messages
static char WindState_ERROR[256];
// boolean to track whether or not an error is active.
static int WindState_HAS_ERR = 0;
// Currently loaded command
static WindCommand WindState_COMMAND = WindCommand_null;
// Current program state
static WindMode WindState_MODE = WindMode_command;

void WindState_write_err(const char* fmt, ...)
{
        va_list err_args;
        va_start(err_args, fmt);
        vsprintf(WindState_ERROR, fmt, err_args);
        WindState_HAS_ERR = 1;
        va_end(err_args);
}
