#ifndef WIND_STREAM_H
#define WIND_STREAM_H

#include "WindBuf.h"
#include "WindType.h"

// Header which defines Wind Stream struct, and functionality,

//Indicates the number of buffers that the stream holds.
// 2 buffers are used for now to switch between for copy operations like map.
#define WindStream_BUF_CNT 2

// The initial buffer size allocated
#define WindStream_BUF_SIZE 100

// Evaluates to the currently active buffer
#define WindStream_ACTIVE(ws) (ws->bufs[ws->activeBuf])
// Gets space of active buffer
#define WindStream_SPACE(ws) (ws->activeBuf->cap - ws->activeBuf->len)

#define WindStream_FITS(ws, size) (ws->activeBuf->cap - ws->activeBuf->len) > size

typedef struct
{
        WindBuf* bufs[WindStream_BUF_CNT];
        WindBuf* activeBuf;
        // Indicates which stream is active, while the other(s) is reserved for copy operations
        int activeIndex;
} WindStream;

WindStream* WindStream_new(void);

// Writes one byte to the stream.
void WindStream_put(WindStream* ws, unsigned char byte);

void WindStream_put_ptr(WindStream* ws, void* ptr, size_t n);

void WindStream_del(WindStream* ws);

#endif
