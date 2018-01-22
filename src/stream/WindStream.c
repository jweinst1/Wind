#include "WindStream.h"

WindStream* WindStream_new(void)
{
        WindStream* stream = malloc(sizeof(WindStream));
        stream->front = NULL;
        stream->back = NULL;
        stream->len = 0;
        return stream;
}

void WindStream_del(WindStream* wstream)
{
        WindObject* curObj = wstream->front;
        while(curObj != NULL)
        {
                free(curObj);
                curObj = curObj->next;
        }
}

void WindStream_push(WindStream* wstream, WindObject* wobj)
{
        if(wstream->len == 0)
        {
                wstream->len++;
                wstream->front = wobj;
                wstream->back = wstream->front;
        }
        else
        {
                wstream->len++;
                wstream->back->next = wobj;
                wstream->back = wstream->back->next;
        }
}
