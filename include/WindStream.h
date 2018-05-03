#ifndef WIND_STREAM_H
#define WIND_STREAM_H

#include <stdio.h>
#include <stdarg.h>
#include "WindBuf.h"
#include "WindType.h"

// Header which defines Wind Stream struct, and functionality,

//Indicates the number of buffers that the stream holds.
// 2 buffers are used for now to switch between for copy operations like map.
#define WindStream_BUF_CNT 2

// The initial buffer size allocated
#define WindStream_BUF_SIZE 100

// Evaluates to the currently active buffer
#define WindStream_ACTIVE(ws) (ws->activeBuf)

#define WindStream_ALT(ws) (ws->altBuf)
// Gets space of active buffer
#define WindStream_SPACE(ws) (ws->activeBuf->cap - ws->activeBuf->len)

#define WindStream_FITS(ws, size) (ws->activeBuf->cap - ws->activeBuf->len) > size

// Evaluates to a reference to the address to write more data to the buffer.
#define WindStream_REF(ws) (ws->activeBuf->data + ws->activeBuf->len)

#define WindStream_INC_LEN(ws, amount) (ws->activeBuf->len += amount)

typedef struct
{
        char err[256];
        int hasErr;
        WindBuf* altBuf;
        WindBuf* activeBuf;
        // Indicates which stream is active, while the other(s) is reserved for copy operations
        int activeIndex;
} WindStream;

WindStream* WindStream_new(void);

// expands internal buffer.
// if alt, expands the alternative buffer instead.
void WindStream_expand(WindStream* ws, int alt, size_t amount);

// Resets specified buffer of stream.
void WindStream_reset(WindStream* ws, int alt);

// Writes one byte to the stream.
void WindStream_put(WindStream* ws, int alt, unsigned char byte);

void WindStream_put_c(WindStream* ws, int alt, char ch);

void WindStream_put_ptr(WindStream* ws, int alt, void* ptr, size_t n);

void WindStream_put_int(WindStream* ws, int alt, int num);

void WindStream_put_long(WindStream* ws, int alt, long num);

// Puts string in format [size, data].
// Does not include typed marker.
void WindStream_put_string(WindStream* ws, int alt, const char* string);

void WindStream_del(WindStream* ws);

void WindStream_write_err(WindStream* ws, const char* fmt, ...);

void WindStream_print_err(WindStream* ws);

void WindStream_swap_buf(WindStream* ws);

#endif
