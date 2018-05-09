#ifndef WIND_TYPE_H
#define WIND_TYPE_H

// Header defines wind type enum and related utilities

typedef enum
{
        WindType_None
} WindType;

// An enum to track the kinds of Wind Commands.
typedef enum
{
        WindCommand_null, // abscence of a command
        WindCommand_out,
        WindCommand_push,
        WindCommand_clr
} WindCommand;

#endif
