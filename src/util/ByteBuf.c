#include "ByteBuf.h"

ByteBuf* ByteBuf_new(size_t bufSize)
{
        ByteBuf* newbuf;
        SAFE_ALLOC_M(newbuf, sizeof(ByteBuf));
        SAFE_ALLOC_M(newbuf->begin, (sizeof(unsigned char) * bufSize));
        newbuf->mark = newbuf->begin;
        newbuf->end = newbuf->begin + bufSize;
        return newbuf;
}


void ByteBuf_write(ByteBuf* buf, unsigned char* data, size_t amount)
{
        if(amount > ByteBuf_SPACE(buf))
        {
                size_t oldLen = ByteBuf_LEN(buf);
                size_t newCap = amount + ByteBuf_CAP(buf);
                SAFE_ALLOC_RE(buf->begin, newCap);
                buf->mark = buf->begin + oldLen;
                buf->end = buf->begin + newCap;
        }
        else
        {
                memcpy(buf->mark, data, amount);
                buf->mark += amount;
        }
}
