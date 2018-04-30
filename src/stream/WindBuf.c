#include "WindBuf.h"

WindBuf* WindBuf_new(size_t size)
{
        WindBuf* newbuf = malloc(sizeof(WindBuf) + (sizeof(unsigned char) * size));
        newbuf->len = 0;
        newbuf->cap = size;
        return newbuf;
}
