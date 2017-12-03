#include "Debug.h"

void Debug_obj(WindObject* wobj)
{
        Debug_START;
        puts("Error: ");
        if(wobj->error.active) printf("%s\n", wobj->error.mes);
        else puts("No Error");
        unsigned char* insPtr = wobj->instructions;
        Debug_END;
}
