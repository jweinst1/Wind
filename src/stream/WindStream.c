#include "WindStream.h"

WindStream* WindStream_new(void)
{
        WindStream* newstream = malloc(sizeof(WindStream));
        newstream->activeBuf = WindBuf_new(WindStream_BUF_SIZE);
        newstream->altBuf = WindBuf_new(WindStream_BUF_SIZE);
        newstream->loadBuf = WindBuf_new(WindStream_BUF_SIZE);
        newstream->activeIndex = 0;
        newstream->hasErr = 0;
        newstream->err[0] = '\0';
        return newstream;
}

void WindStream_expand(WindStream* ws, BufKey bkey, size_t amount)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        WindBuf_EXPAND(expBuf, amount);
}

void WindStream_reset(WindStream* ws, BufKey bkey)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        expBuf->len = 0;
}


void WindStream_put(WindStream* ws, BufKey bkey, unsigned char byte)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        if(WindBuf_FULL(expBuf)) WindBuf_EXPAND(expBuf, 20);
        WindBuf_PUT(expBuf, byte);
}

void WindStream_put_c(WindStream* ws, BufKey bkey, char ch)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        if(WindBuf_FULL(expBuf)) WindBuf_EXPAND(expBuf, 30);
        WindBuf_PUTC(expBuf, ch);
}

void WindStream_put_ptr(WindStream* ws, BufKey bkey, void* ptr, size_t n)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        if(!(WindStream_FITS(ws, n))) WindBuf_EXPAND(expBuf, n + 30);
        memcpy(expBuf->data + expBuf->len, ptr, n);
        expBuf->len += n;
}

void WindStream_put_int(WindStream* ws, BufKey bkey, int num)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        if(!(WindStream_FITS(ws, sizeof(int)))) WindBuf_EXPAND(expBuf, sizeof(int) + 30);
        *(int*)(expBuf->data + expBuf->len) = num;
        expBuf->len += sizeof(int);
}

void WindStream_put_long(WindStream* ws, BufKey bkey, long num)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        if(!(WindStream_FITS(ws, sizeof(long)))) WindBuf_EXPAND(expBuf, sizeof(long) + 30);
        *(long*)(expBuf->data + expBuf->len) = num;
        expBuf->len += sizeof(long);
}

void WindStream_put_string(WindStream* ws, BufKey bkey, const char* string)
{
        WindBuf* expBuf;
        WindStream_GET_BUF(ws, expBuf, bkey);
        unsigned long length = strlen(string);
        *(unsigned long*)WindStream_REF(ws) = length;
        expBuf->len += sizeof(unsigned long);

        if(!(WindStream_FITS(ws, length))) WindBuf_EXPAND(expBuf, length + 30);
        char* writer = (char*)WindStream_REF(ws);
        while(*string) *writer++ = *string++;
        expBuf->len += length;
}

void WindStream_del(WindStream* ws)
{
        free(ws->activeBuf);
        free(ws->altBuf);
        free(ws->loadBuf);
        free(ws);
}

void WindStream_write_err(WindStream* ws, const char* fmt, ...)
{
        va_list err_args;
        va_start(err_args, fmt);
        vsprintf(ws->err, fmt, err_args);
        ws->hasErr = 1;
        va_end(err_args);
}

void WindStream_print_err(WindStream* ws)
{
        if(ws->hasErr)
        {
                printf("Error: %s \n", ws->err);
                ws->hasErr = 0;
                ws->err[0] = '\0';
        }
}

void WindStream_swap_buf(WindStream* ws)
{
        // flips the active index, to indicate if the buffer is the alt or original active.
        ws->activeIndex = ws->activeIndex ? 0 : 1;
        WindBuf* temp = ws->activeBuf;
        ws->activeBuf = ws->altBuf;
        ws->altBuf = temp;
}
