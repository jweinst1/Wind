#ifndef WIND_STREAM_H
#define WIND_STREAM_H

#include <stdio.h>
#include "WindObject.h"

#define WindStream_ERRSIZE 256

// Macro that creates a stack-allocated stream.
#define WindStream_INIT(name) \
        WindStream name; \
        name.front = NULL; \
        name.back = NULL; \
        name.len = 0; \
        name.hasErr = 0;

#define WindStream_IS_EMPTY(wstream) (wstream->len == 0)

// Main stream structure for Wind
// @len, number of objects in the stream.
typedef struct
{
        char err[WindStream_ERRSIZE];
        struct WindObject* front;
        struct WindObject* back;
        size_t len;
        int hasErr;
} WindStream;

// Creates a new dynamically allocated stream.
WindStream* WindStream_new(void);

// Inlined function to fuse objects
static inline void
WindStream_connect(WindObject* wobj1, WindObject* wobj2)
{
        wobj1->next = wobj2;
        wobj2->prev = wobj1;
}

// Inline function to disconnect objects
static inline void
WindStream_disconnect(WindObject* wobj1, WindObject* wobj2)
{
        wobj1->next = NULL;
        wobj2->prev = NULL;
}


// Deletes a Stream
void WindStream_del(WindStream* wstream);


void WindStream_out(WindStream* wstream);



#endif // WIND_STREAM_H
