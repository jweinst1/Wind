#ifndef WIND_TYPE_H
#define WIND_TYPE_H

// Header defines wind type enum and related utilities

// Type Marker for Wind Values
typedef enum
{
        WindType_None,
        WindType_Bool,
        WindType_Number,
        WindType_String,
        WindType_Not,
        WindType_Assign,
        WindType_Plus,
        WindType_Minus,
        WindType_Multiply,
        WindType_Divide,
        WindType_Lt,
        WindType_Gt,
        WindType_Del,
        WindType_Sep
} WindType;

// An enum to track the kinds of Wind Commands.
typedef enum
{
        WindCommand_null, // abscence of a command
        WindCommand_out,
        WindCommand_push,
        WindCommand_clr,
        WindCommand_map,
        WindCommand_filter,
        WindCommand_reduce,
        WindCommand_save
} WindCommand;

const char* WindType_get_str(WindType type);

#endif
