#ifndef BYTE_BUF_H
#define BYTE_BUF_H
// Util header for byte buf object

#include <stdlib.h>

#define ByteBuf_START_SIZE 200 * sizeof(unsigned char)
#define ByteBuf_EXP_FACTOR 2

// Macro version of bytebuf init
#define ByteBuf_MAKE(name) do { \
                if((name->begin = malloc(ByteBuf_START_SIZE)) == NULL) { \
                        fprintf(stderr, "%s\n", "Memory Error: Out of memory, exiting."); \
                        exit(1); \
                } \
                name->mark = name->begin; \
                name->end = name->begin + ByteBuf_START_SIZE; \
} while(0)

// Frees the unsigned char ptr.
#define ByteBuf_DEL(buf) do { \
                free(buf->begin); \
                buf->mark = NULL; \
                buf->end = NULL; \
} while(0)

//Transfers ownership of unsigned char ptr.
#define ByteBuf_TRANSFER(buf, transBuf) transBuf = buf->begin

#define ByteBuf_LEN(buf) (buf->mark - buf->begin)
#define ByteBuf_SPACE(buf) (buf->end - buf->mark)
#define ByteBuf_CAP(buf) (buf->end - buf->begin)

#define ByteBuf_FITS(buf, size) ((buf->end - buf->mark) > size)
#define ByteBuf_FITS_LONG(buf) ((buf->end - buf->mark) > sizeof(long))
#define ByteBuf_FULL(buf) (buf->end - buf->mark) == 0

// Allows the existing space in a byte buffer to be reused.
#define ByteBuf_RESET(buf) buf->mark = buf->begin

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

static inline void
ByteBuf_write_long(ByteBuf* buf, long number)
{
        if(!ByteBuf_FITS_LONG(buf)) ByteBuf_expand(buf);
        *(long*)(buf->mark) = number;
        buf->mark += sizeof(long);
}



void ByteBuf_write_data(ByteBuf* buf, unsigned char* data, size_t n);

#endif // BYTE_BUF_H
