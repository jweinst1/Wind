#ifndef WIND_STREAM_H
#define WIND_STREAM_H

#include "WindObject.h"

// Macro that creates a stack-allocated stream.
#define WindStream_INIT(name) \
        WindStream name; \
        name.front = NULL; \
        name.back = NULL; \
        name.len = 0;

#define WindStream_IS_EMPTY(wstream) (wstream->len == 0)

// Main stream structure for Wind
// @len, number of objects in the stream.
typedef struct
{
        struct WindObject* front;
        struct WindObject* back;
        size_t len;
} WindStream;

// Creates a new dynamically allocated stream.
WindStream* WindStream_new(void);

void WindStream_del(WindStream* wstream);

void WindStream_push(WindObject* wobj);

#endif // WIND_STREAM_H
