#include "ByteBuf.h"
#include <stdio.h>

void ByteBuf_init(ByteBuf* buf)
{
        buf->begin = malloc(sizeof(unsigned char) * ByteBuf_START_SIZE);
        buf->mark = buf->begin;
        buf->end = buf->begin + ByteBuf_START_SIZE;
}

void ByteBuf_expand(ByteBuf* buf)
{
        size_t oldLen = ByteBuf_LEN(buf);
        size_t newCap = ByteBuf_CAP(buf) * ByteBuf_EXP_FACTOR;
        if( (buf->begin = realloc(buf->begin, newCap)) == NULL)
        {
                fprintf(stderr, "%s\n", "Out of Memory Error: Exiting");
                exit(1);
        }
        buf->mark = buf->begin + oldLen;
        buf->end = buf->begin + newCap;
}

void ByteBuf_write_data(ByteBuf* buf, unsigned char* data, size_t n)
{
        while(!ByteBuf_FITS(buf, n)) ByteBuf_expand(buf);
        while(n--)
        {
                *(buf->mark++) = *data++;
        }
}
