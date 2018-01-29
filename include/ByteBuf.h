#ifndef BYTE_BUF_H
#define BYTE_BUF_H
// Util header for byte buf object

#include <stdlib.h>

#define ByteBuf_START_SIZE 100
#define ByteBuf_EXP_FACTOR 2

#define ByteBuf_DEL(buf) do { \
                free(buf->begin); \
                buf->mark = NULL; \
                buf->end = NULL; \
} while(0)

#define ByteBuf_LEN(buf) (buf->mark - buf->begin)
#define ByteBuf_SPACE(buf) (buf->end - buf->mark)
#define ByteBuf_CAP(buf) (buf->end - buf->begin)

#define ByteBuf_FITS(buf, size) ((buf->end - buf->mark) > size)
#define ByteBuf_FULL(buf) (buf->end - buf->mark) == 0

typedef struct
{
        unsigned char* begin;
        unsigned char* mark;
        unsigned char* end;
} ByteBuf;

void ByteBuf_init(ByteBuf* buf);

void ByteBuf_expand(ByteBuf* buf);

static inline void
ByteBuf_write_byte(ByteBuf* buf, unsigned char byte)
{
        if(ByteBuf_FULL(buf)) ByteBuf_expand(buf);
        *(buf->mark++) = byte;
}

void ByteBuf_write_data(ByteBuf* buf, unsigned char* data, size_t n);

#endif // BYTE_BUF_H
