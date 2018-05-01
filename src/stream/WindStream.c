#include "WindStream.h"

WindStream* WindStream_new(void)
{
        WindStream* newstream = malloc(sizeof(WindStream));
        newstream->activeBuf = WindBuf_new(WindStream_BUF_SIZE);
        newstream->altBuf = WindBuf_new(WindStream_BUF_SIZE);
        newstream->activeIndex = 0;
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
        memcpy(ws->activeBuf->data + ws->activeBuf->len, ptr, n);
        ws->activeBuf->len += n;
}

void WindStream_put_int(WindStream* ws, int num)
{
        if(!(WindStream_FITS(ws, sizeof(int)))) WindBuf_EXPAND(ws->activeBuf, sizeof(int) + 30);
        *(int*)(ws->activeBuf->data + ws->activeBuf->len) = num;
        ws->activeBuf->len += sizeof(int);
}

void WindStream_put_string(WindStream* ws, const char* string)
{
        unsigned long length = strlen(string);
        *(unsigned long*)WindStream_REF(ws) = length;
        ws->activeBuf->len += sizeof(unsigned long);

        if(!(WindStream_FITS(ws, length))) WindBuf_EXPAND(ws->activeBuf, length + 30);
        char* writer = (char*)WindStream_REF(ws);
        while(*string) *writer++ = *string++;
        ws->activeBuf->len += length;
}

void WindStream_del(WindStream* ws)
{
        free(ws->activeBuf);
        free(ws->altBuf);
        free(ws);
}
