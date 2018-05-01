#include "WindStream.h"

WindStream* WindStream_new(void)
{
        WindStream* newstream = malloc(sizeof(WindStream));
        for(int i = 0; i < WindStream_BUF_CNT; i++)
        {
                newstream->bufs[i] = WindBuf_new(WindStream_BUF_SIZE);
        }
        newstream->activeIndex = 0;
        newstream->activeBuf = newstream->bufs[newstream->activeIndex];
        return newstream;
}

void WindStream_put(WindStream* ws, unsigned char byte)
{
        if(WindBuf_FULL(ws->activeBuf)) WindBuf_EXPAND(ws->activeBuf, 20);
        WindBuf_PUT(ws->activeBuf, byte);
}

void WindStream_put_ptr(WindStream* ws, void* ptr, size_t n)
{
        if(!(WindStream_FITS(ws, n))) WindBuf_EXPAND(ws->activeBuf, n + 30);
        memcpy(ws->activeBuf->data, ptr, n);
        ws->activeBuf->len += n;
}

void WindStream_del(WindStream* ws)
{
        for(int i = 0; i<WindStream_BUF_CNT; i++) free(ws->bufs[i]);
        free(ws);
}
