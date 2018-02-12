#ifndef WIND_NONE_H
#define WIND_NONE_H
// Wind None Header

#include "WindObject.h"

// Wind type that represents a None object.
typedef struct
{
        WindObject_BASE
} WindNone;

WindNone* WindNone_new(void);

WindNone* WindNone_new_arr(int amount);


#endif
