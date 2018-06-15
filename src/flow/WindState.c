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

int WindState_has_err(void)
{
        return WindState_HAS_ERR;
}

void WindState_print_err(void)
{
        if(WindState_HAS_ERR)
        {
                WindState_HAS_ERR = 0;
                fprintf(stderr, "Error: %s\n", WindState_ERROR);
                WindState_ERROR[0] = '\0';
        }
}

void WindState_set_mode(WindMode mode)
{
        WindState_MODE = mode;
}

WindMode WindState_get_mode(void)
{
        return WindState_MODE;
}

void WindState_print_mode(void)
{
        switch(WindState_MODE)
        {
        case WindMode_load:
                printf("Load");
                break;
        case WindMode_command:
                printf("Command");
                break;
        case WindMode_exec:
                printf("Execute");
                break;
        }
}

void WindState_set_cmd(WindCommand cmd)
{
        WindState_COMMAND = cmd;
}

WindCommand WindState_get_cmd(void)
{
        return WindState_COMMAND;
}

int WindState_has_cmd(void)
{
        return WindState_COMMAND != WindCommand_null;
}

void WindState_print_cmd(void)
{
        switch(WindState_COMMAND)
        {
        case WindCommand_null:
                printf("null");
                break;
        case WindCommand_out:
                printf("out");
                break;
        case WindCommand_push:
                printf("push");
                break;
        case WindCommand_clr:
                printf("clr");
                break;
        case WindCommand_map:
                printf("map");
                break;
        case WindCommand_filter:
                printf("filter");
                break;
        case WindCommand_reduce:
                printf("reduce");
                break;
        case WindCommand_save:
                printf("save");
                break;
        }
}
