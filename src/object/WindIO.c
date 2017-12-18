#include "WindIO.h"
#include <stdio.h>


void WindIO_print(WindObject* obj)
{
        switch(obj->type)
        {
        case WindType_None:
                puts("None");
                break;
        case WindType_Int:
                printf("%ld\n", obj->value._int);
                break;
        case WindType_Str:
                printf("\"%s\"\n", obj->value._str.begin);
                break;
        case WindType_List:
                // not implemented
                puts("[]");
                break;
        }
}
