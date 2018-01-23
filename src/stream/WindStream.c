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
                free(curObj); // Need to be changed for sized types.
                curObj = curObj->next;
        }
        free(wstream);
}


void WindStream_push(WindStream* wstream, WindObject* wobj)
{
        if(wstream->len)
        {
                wstream->len++;
                WindStream_connect(wstream->back, wobj);
                wstream->back = wobj;
        }
        else
        {
                wstream->len++;
                wstream->front = wobj;
                wstream->back = wstream->front;
        }
}

void WindStream_push_left(WindStream* wstream, WindObject* wobj)
{
        if(wstream->len)
        {
                wstream->len++;
                WindStream_connect(wobj, wstream->front);
                wstream->front = wobj;
        }
        else
        {
                wstream->len++;
                wstream->front = wobj;
                wstream->back = wstream->front;
        }
}

void WindStream_remove_end(WindStream* wstream)
{
        // todo:: Free mechanism needs replace for sized types
        if(wstream->len)
        {
                if(wstream->len == 1)
                {
                        free(wstream->front);
                        wstream->front = NULL;
                        wstream->back = NULL;
                        wstream->len--;
                }
                else
                {
                        free(wstream->back);
                        wstream->back = wstream->back->prev;
                        wstream->back->next = NULL;
                        wstream->len--;
                }
        }
}
