#include "StreamCore.h"

void WindStream_push(WindStream* wstream, WindObject* wobj)
{
        if(wstream->len)
        {
                wstream->len++;
                WindObject_CONNECT(wstream->back, wobj);
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
                WindObject_CONNECT(wobj, wstream->front);
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

void WindStream_remove_begin(WindStream* wstream)
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
                        free(wstream->front);
                        wstream->front = wstream->front->next;
                        wstream->front->prev = NULL;
                        wstream->len--;
                }
        }
}

void WindStream_clear(WindStream* wstream)
{
        // Needs to be updated with a free mechanism
        WindObject* curObj = wstream->front;
        while(curObj != NULL)
        {
                free(curObj);
                curObj = curObj->next;
        }
        wstream->front = NULL;
        wstream->back = NULL;
        wstream->len = 0;
}
