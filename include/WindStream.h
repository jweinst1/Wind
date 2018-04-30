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

typedef struct
{
        WindBuf* bufs[WindStream_BUF_CNT];
        // Indicates which stream is active, while the other(s) is reserved for copy operations
        int activeBuf;
} WindStream;

WindStream* WindStream_new(void);

#endif
