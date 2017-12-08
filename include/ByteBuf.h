#ifndef WIND_BYTE_BUF_H
#define WIND_BYTE_BUF_H
//util byte buffer type

#include "SafeAlloc.h"
#include <stdlib.h>
#include <string.h>

#define ByteBuf_SPACE(bbuf) (bbuf->end - bbuf->mark)

#define ByteBuf_LEN(bbuf) (bbuf->mark - bbuf->begin)

#define ByteBuf_CAP(bbuf) (bbuf->end - bbuf->begin)

struct ByteBuf
{
        unsigned char* begin;
        unsigned char* mark;
        unsigned char* end;
};

typedef struct ByteBuf ByteBuf;

//allocates a new byte buffer
ByteBuf* ByteBuf_new(size_t bufSize);

//writes to, and expands existing byte buffer if neccesary
void ByteBuf_write(ByteBuf* buf, unsigned char* data, size_t amount);

inline void
ByteBuf_copy_to(ByteBuf* buf, unsigned char* dst)
{
        memcpy(dst, buf->begin, ByteBuf_LEN(buf));
}

//frees a byte buffer
inline void
ByteBuf_free(ByteBuf* buf)
{
        free(buf->begin);
        free(buf);
}


#endif
