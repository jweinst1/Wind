#include "Debug.h"

void Debug_object(WindObject* wobj)
{
        switch(wobj->type)
        {
        case WindType_None:
                printf("Object[None]:{self = %p, next = %p, prev = %p}\n",
                       wobj, wobj->next, wobj->prev);
                break;
        }
}
