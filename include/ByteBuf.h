#ifndef BYTEBUF_H
#define BYTEBUF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ByteBuf_SPACE(buf) (buf->end - buf->mark)

#define ByteBuf_CAP(buf) (buf->end - buf->begin)

#define ByteBuf_LEN(buf) (buf->mark - buf->begin)

#define ByteBuf_EMPTY(buf) (buf->begin == buf->mark)

#define ByteBuf_FULL(buf) (buf->mark == buf->end)

typedef struct
{
        unsigned char* begin;
        unsigned char* mark;
        unsigned char* end;
} ByteBuf;

ByteBuf* ByteBuf_new(size_t cap);

void ByteBuf_del(ByteBuf* buf);

void ByteBuf_expand(ByteBuf* buf, int factor);

void ByteBuf_write_byte(ByteBuf* buf, unsigned char byte);

void ByteBuf_write_long(ByteBuf* buf, long num);

void ByteBuf_write_data(ByteBuf* buf, void* data, size_t amount);

// writes all the chars until a " is found
void ByteBuf_write_str(ByteBuf* buf, char** string, unsigned char bound);

void ByteBuf_to_file(ByteBuf* buf, const char* name);




#endif
