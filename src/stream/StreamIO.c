#include "StreamIO.h"

void WindStream_out(WindStream* wstream)
{
        printf("[ ");
        WindObject* objPtr = wstream->front;
        while(objPtr != NULL)
        {
                switch(objPtr->type)
                {
                case WindType_None:
                        printf("%s ", "None");
                        break;
                }
                objPtr = objPtr->next;
        }
        puts("]");
}
