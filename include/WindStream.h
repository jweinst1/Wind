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

#define WindStream_RESET_LOAD(ws) ws->loadBuf->len = 0

#define WindStream_GET_BUF(ws, var, key) switch(key) { \
        case BufKey_active: var = ws->activeBuf; break; \
        case BufKey_alt: var = ws->altBuf; break; \
        case BufKey_load: var = ws->loadBuf; break; \
}
// Special macro to check for a non-null command.
#define WindStream_HAS_CMD(ws) (ws->command != WindCommand_null)

// enum that acts as way of specifying which buffer you want to perform action on.
typedef enum
{
        BufKey_active,
        BufKey_alt,
        BufKey_load
} BufKey;

//enum to track what tokens the stream will accept next.
typedef enum
{
        StreamState_command,
        StreamState_load,
        StreamState_exec
} StreamState;

typedef struct
{
        char err[256];
        StreamState state;
        WindCommand command;
        WindCommand cmd;
        int hasErr;
        WindBuf* altBuf;
        WindBuf* activeBuf;
        WindBuf* loadBuf; // for loading args or values.
        // Indicates which stream is active, while the other(s) is reserved for copy operations
        int activeIndex;
} WindStream;

WindStream* WindStream_new(void);

// expands internal buffer.
// if alt, expands the alternative buffer instead.
void WindStream_expand(WindStream* ws, BufKey bkey, size_t amount);

// Resets specified buffer of stream.
void WindStream_reset(WindStream* ws, BufKey bkey);

// Gets and returns buffer that corresponds to key.
WindBuf* WindStream_get_buf(WindStream* ws, BufKey bkey);

// Writes one byte to the stream.
void WindStream_put(WindStream* ws, BufKey bkey, unsigned char byte);

void WindStream_put_c(WindStream* ws, BufKey bkey, char ch);

void WindStream_put_ptr(WindStream* ws, BufKey bkey, void* ptr, size_t n);

void WindStream_put_int(WindStream* ws, BufKey bkey, int num);

void WindStream_put_long(WindStream* ws, BufKey bkey, long num);

// Copies a single value from a bytes pointer onto the specified buffer.
void WindStream_copy_val(WindStream* ws, BufKey bkey, unsigned char* bufPtr);

// Gets the buffer at the ith item specified in index.
// If index is out of range returns NULL.
unsigned char* WindStream_get(WindStream* ws, BufKey bkey, size_t index);

// Puts string in format [size, data].
// Does not include typed marker.
void WindStream_put_string(WindStream* ws, BufKey bkey, const char* string);

void WindStream_del(WindStream* ws);

void WindStream_write_err(WindStream* ws, const char* fmt, ...);

void WindStream_print_err(WindStream* ws);

void WindStream_swap_buf(WindStream* ws);

#endif
