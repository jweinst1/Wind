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

void WindStream_put(WindStream* ws, int alt, unsigned char byte)
{
        WindBuf* expBuf = alt ? ws->altBuf : ws->activeBuf;
        if(WindBuf_FULL(expBuf)) WindBuf_EXPAND(expBuf, 20);
        WindBuf_PUT(expBuf, byte);
}

void WindStream_put_c(WindStream* ws, int alt, char ch)
{
        WindBuf* expBuf = alt ? ws->altBuf : ws->activeBuf;
        if(WindBuf_FULL(expBuf)) WindBuf_EXPAND(expBuf, 30);
        WindBuf_PUTC(expBuf, ch);
}

void WindStream_put_ptr(WindStream* ws, int alt, void* ptr, size_t n)
{
        WindBuf* expBuf = alt ? ws->altBuf : ws->activeBuf;
        if(!(WindStream_FITS(ws, n))) WindBuf_EXPAND(expBuf, n + 30);
        memcpy(expBuf->data + expBuf->len, ptr, n);
        expBuf->len += n;
}

void WindStream_put_int(WindStream* ws, int alt, int num)
{
        WindBuf* expBuf = alt ? ws->altBuf : ws->activeBuf;
        if(!(WindStream_FITS(ws, sizeof(int)))) WindBuf_EXPAND(expBuf, sizeof(int) + 30);
        *(int*)(expBuf->data + expBuf->len) = num;
        expBuf->len += sizeof(int);
}

void WindStream_put_string(WindStream* ws, int alt, const char* string)
{
        WindBuf* expBuf = alt ? ws->altBuf : ws->activeBuf;
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
