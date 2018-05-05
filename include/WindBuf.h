#ifndef WIND_BUF_H
#define WIND_BUF_H

#include <stdlib.h>
#include <string.h>

// Buffer for Wind Stream

// Macros that deal with size and space of buf
#define WindBuf_SPACE(wb) (wb->cap - wb->len)
#define WindBuf_FITS(wb, size) (wb->cap - wb->len) > size
#define WindBuf_SIZE(wb) (wb->cap + sizeof(WindBuf))
#define WindBuf_FULL(wb) (wb->cap == wb->len)
#define WindBuf_EMPTY(wb) (wb->len == 0)

//Macros that reset or clean the buffer
#define WindBuf_RESET(wb) (wb->len = 0)
#define WindBuf_CLEAN(wb) for(size_t i =0; i< wb->cap; i++) wb->data[i] = 0

//Checks if index is in the range of the buffer.
#define WindBuf_IN(wb, index) (index < wb->len && index >= 0)

// Macro handles expansion of buffer due to memory allocated in place.
#define WindBuf_EXPAND(wb, amount) do { \
                wb->cap += amount; \
                wb = realloc(wb, WindBuf_SIZE(wb)); \
} while (0)

// Shrinks the capacity of the buffer if neccesary
#define WindBuf_SHRINK(wb, newsize) if(newsize > wb->len) { \
                wb->cap = newsize; \
                wb = realloc(wb, WindBuf_SIZE(wb)); \
}

// Gets a typed pointer to some area of the buffer.
#define WindBuf_TPTR(wb, index, type) ((type*)(wb->data + index))

#define WindBuf_PUT(wb, byte) (wb->data[wb->len++] = byte)

#define WindBuf_PUTC(wb, ch) (wb->data[wb->len++] = (unsigned char)ch)

// Buffer is an in-place allocated memory chunk that reserves additional capacity.
typedef struct
{
        size_t cap;
        size_t len;
        unsigned char data[0];
} WindBuf;

WindBuf* WindBuf_new(size_t size);

#endif
