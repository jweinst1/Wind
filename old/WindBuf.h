#ifndef WIND_BUF_H
#define WIND_BUF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WindType.h"

// Buffer for Wind Stream

#define WindBuf_EQ_SPACE 10

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

// This sets the len of the buffer equal to the space that head was moved.
#define WindBuf_HEAD_LEN(wb) (wb->len = (wb->head - wb->data))
#define WindBuf_HEAD_RE(wb) (wb->head = wb->data)
// Determines if the head is at the length point.
#define WindBuf_HEAD_AT_L(wb) (wb->head == (wb->data + wb->len))

#define WindBuf_HEAD_FULL(wb) (wb->head == (wb->data + wb->cap))
#define WindBuf_HEAD_FITS(wb, size) (wb->head + size) > (wb->data + wb->cap)

// Macro handles expansion of buffer due to memory allocated in place.
#define WindBuf_EXPAND(wb, amount) do { \
                wb->cap += amount; \
                wb = realloc(wb, WindBuf_SIZE(wb)); \
                wb->head = wb->data; \
} while (0)

// Shrinks the capacity of the buffer if neccesary
#define WindBuf_SHRINK(wb, newsize) if(newsize > wb->len) { \
                wb->cap = newsize; \
                wb = realloc(wb, WindBuf_SIZE(wb)); \
                wb->head = wb->data; \
}

// Macro that checks if a size can fit in the buffer, and if it doesn't
// expands buffer by add
#define WindBuf_CHECK(wb, size, add) if((wb->cap - wb->len) < size) { \
                wb->cap += add; \
                wb = realloc(wb, WindBuf_SIZE(wb)); \
                wb->head = wb->data; \
}

// Gets a typed pointer to some area of the buffer.
#define WindBuf_TPTR(wb, index, type) ((type*)(wb->data + index))

#define WindBuf_PUT(wb, byte) (wb->data[wb->len++] = byte)

#define WindBuf_PUTC(wb, ch) (wb->data[wb->len++] = (unsigned char)ch)

// safe macro to copy memory into buffer.
#define WindBuf_WRITE(wb, ptr, n) if((wb->cap - wb->len) > n) memcpy(wb->data, ptr, n)

// Buffer is an in-place allocated memory chunk that reserves additional capacity.
// head serves as a movable writer or reader for iterating across a buffer.
typedef struct
{
        size_t cap;
        size_t len;
        unsigned char* head;
        unsigned char data[0];
} WindBuf;

WindBuf* WindBuf_new(size_t size);

void WindBuf_check(WindBuf** wb, size_t size, size_t add);

// Low level get function
unsigned char* WindBuf_get(WindBuf* wb, size_t index);

// appends item to end of buffer, but returns pointer to place where item
// begins in buffer after appending.
unsigned char* WindBuf_place(WindBuf* wb, void* item, size_t size);


// Makes buffer 2 the same capacity as buffer 1, if it's smaller than buffer 1
// other buffer must be double pointer due to direct allocation of WindBuf
void WindBuf_equalize(WindBuf* wb, WindBuf** other);

// Does the same as equalize but does not change the length;
void WindBuf_equalize_cap(WindBuf* wb, WindBuf** other);

// Generic write function directly for buffers.
void WindBuf_write(WindBuf** wb, void* item, size_t size);

// Writes a pointer to the beginning of the buffer, also resetting
// the len of the buffer to size of the pointer.
void WindBuf_write_begin(WindBuf* wb, void* item, size_t size);

// Same as Windbuf_write but writes a byte mark before the incoming item.
void WindBuf_write_mark(WindBuf* wb, unsigned char mark, void* item, size_t size);

#endif
