#ifndef WIND_OBJECT_METHODS_H
#define WIND_OBJECT_METHODS_H
//main file for WindObject methods

#include <string.h>
#include "WindObject.h"

inline void
WindObject_make_int(WindObject* wobj, long num)
{
        wobj->type = WindType_Int;
        wobj->value._int = num;
}

void WindObject_make_str(WindObject* wobj, unsigned char* string, size_t n);

#endif
