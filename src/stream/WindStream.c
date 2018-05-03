#include "WindStream.h"

WindStream* WindStream_new(void)
{
        WindStream* newstream = malloc(sizeof(WindStream));
        newstream->activeBuf = WindBuf_new(WindStream_BUF_SIZE);
        newstream->altBuf = WindBuf_new(WindStream_BUF_SIZE);
        newstream->activeIndex = 0;
        newstream->hasErr = 0;
        newstream->err[0] = '\0';
        return newstream;
}

void WindStream_expand(WindStream* ws, int alt, size_t amount)
{
        WindBuf* expBuf = alt ? ws->altBuf : ws->activeBuf;
        WindBuf_EXPAND(expBuf, amount);
}

void WindStream_reset(WindStream* ws, int alt)
{
        WindBuf* expBuf = alt ? ws->altBuf : ws->activeBuf;
        expBuf->len = 0;
}

void WindStream_put(WindStream* ws, unsigned char byte)
{
        if(WindBuf_FULL(ws->activeBuf)) WindBuf_EXPAND(ws->activeBuf, 20);
        WindBuf_PUT(ws->activeBuf, byte);
}

void WindStream_put_c(WindStream* ws, char ch)
{
        if(WindBuf_FULL(ws->activeBuf)) WindBuf_EXPAND(ws->activeBuf, 30);
        WindBuf_PUTC(ws->activeBuf, ch);
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
