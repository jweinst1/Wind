#include "WindBool.h"

WindBool* WindBool_new(int state)
{
        WindBool* newBool = malloc(sizeof(WindBool));
        newBool->state = state % 2;
        newBool->type = WindType_Bool;
        newBool->next = NULL;
        newBool->prev = NULL;
        return newBool;
}
