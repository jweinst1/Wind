#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

#include <stdlib.h>
#include "WindStr.h"
#include "WindError.h"

#define WindObject_INS_SIZE 4000
#define WindObject_CODE_SIZE 1000

// getter macro based on type
#define WindObject_INT(wobj) wobj->value._int

#define WindObject_STR(wobj) wobj->value._str.begin

enum WindState
{
        WindState_Translate,
        WindState_Transition,
        WindState_Execution,
        WindState_Done // for end of current source code reached
};

typedef enum WindState WindState;

enum WindType
{
        WindType_None, //None evaluates to zero
        WindType_Int,
        WindType_Str
};

typedef enum WindType WindType;

//main value container for Wind language
union WindValue
{
        long _int;
        WindStr _str;
};

struct WindObject
{
        unsigned char instructions[WindExecutor_INS_SIZE];
        WindError error;
        union WindValue value;
        unsigned char* insMark;
        unsigned char* insEnd;
        WindState state;
        WindType type;
};

typedef struct WindObject WindObject;

#endif
