#include "WindErr.h"

void WindErr_write(WindStream* wstream, const char* fmt, ...)
{
        wstream->hasErr = 1;
        va_list args;
        va_start (args, fmt);
        vsprintf (wstream->err,fmt, args);
        va_end (args);
}

void WindErr_clear(WindStream* wstream)
{
        for(size_t i = 0; i < WindStream_ERRSIZE; i++) wstream->err[i] = '\0';
}
