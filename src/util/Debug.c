#include "Debug.h"

void Debug_object(WindObject* wobj)
{
        switch(wobj->type)
        {
        case WindType_None:
                printf("Object[None]:{self = %p, next = %p, prev = %p}\n",
                       wobj, wobj->next, wobj->prev);
                break;
        case WindType_Bool:
                printf("Object[Bool]:{state = %d,  self = %p, next = %p, prev = %p}\n",
                       ((WindBool*)wobj)->state,
                       wobj,
                       wobj->next,
                       wobj->prev);
                break;
        }
}

void Debug_stream(WindStream* wstream)
{
        puts("____Wind_Stream____");
        printf("* Length: %lu\n", wstream->len);
        printf("* Front: %p\n", wstream->front);
        printf("* Back: %p\n", wstream->back);
        puts("___________________");
        puts("****Objects*****");
        WindObject* curObj = wstream->front;
        while(curObj != NULL)
        {
                Debug_object(curObj);
                curObj = curObj->next;
        }
        puts("___________________");
}

void Debug_process(unsigned char* bytes, int amount)
{
// not implemented yet.
        puts("______Process_Instructions_______");
}

void Debug_bytes(unsigned char* bytes, int amount)
{
        int enumerate = 0;
        puts("_______Bytes_______");
        while(amount--) printf("(%d.) -> %u\n", enumerate++, *bytes++);
        puts("_____Bytes_End_____");
}
