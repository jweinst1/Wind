#ifndef WIND_OBJECT_H
#define WIND_OBJECT_H

#include <stdlib.h>
#include "WindStr.h"
#include "WindError.h"

// getter macro based on type
#define WindObject_INT(wobj) wobj->value._int

#define WindObject_STR(wobj) wobj->value._str.begin

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
        WindError error;
        union WindValue value;
        WindType type;
};

typedef struct WindObject WindObject;

#endif
