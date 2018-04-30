#ifndef WIND_BUF_H
#define WIND_BUF_H

#include <stdlib.h>

// Buffer for Wind Stream

// Macros that deal with size and space of buf
#define WindBuf_SPACE(wb) (wb->cap - wb->len)
#define WindBuf_FITS(wb, size) (wb->cap - wb->len) > size
#define WindBuf_SIZE(wb) (wb->cap + sizeof(WindBuf))

//Checks if index is in the range of the buffer.
#define WindBuf_IN(wb, index) (index < wb->len && index >= 0)

// Macro handles expansion of buffer due to memory allocated in place.
#define WindBuf_EXPAND(wb, amount) do { \
                wb->cap += amount; \
                wb = realloc(wb, WindBuf_SIZE(wb)); \
} while (0)

// Gets a typed pointer to some area of the buffer.
#define WindBuf_TPTR(wb, index, type) ((type*)(wb->data + index))

// Buffer is an in-place allocated memory chunk that reserves additional capacity.
typedef struct
{
        size_t cap;
        size_t len;
        unsigned char data[0];
} WindBuf;

WindBuf* WindBuf_new(size_t size);

#endif
