#ifndef WIND_STREAMCORE_H
#define WIND_STREAMCORE_H
// Header that contains core methods for stream, like push, remove, etc.

#include "WindStream.h"

void WindStream_push(WindStream* wstream, WindObject* wobj);

void WindStream_push_left(WindStream* wstream, WindObject* wobj);

// Removes the last item in the stream
void WindStream_remove_end(WindStream* wstream);

// Removes the first item in the stream.
void WindStream_remove_begin(WindStream* wstream);

// Clears and destroys all the items in the stream.
void WindStream_clear(WindStream* wstream);


#endif // WIND_STREAMCORE_H
