#include "WindInt.h"

WindObject* WindObject_int(long number)
{
        WindObject* newobj = malloc(sizeof(WindObject));
        newobj->type = WindType_Int;
        newobj->value._int = number;
        return newobj;
}
