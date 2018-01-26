#include "WindStream.h"

WindStream* WindStream_new(void)
{
        WindStream* stream = malloc(sizeof(WindStream));
        stream->front = NULL;
        stream->back = NULL;
        stream->len = 0;
        stream->hasErr = 0;
        return stream;
}

void WindStream_del(WindStream* wstream)
{
        WindObject* curObj = wstream->front;
        while(curObj != NULL)
        {
                free(curObj); // Need to be changed for sized types.
                curObj = curObj->next;
        }
        free(wstream);
}
