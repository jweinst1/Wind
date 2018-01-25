#ifndef WIND_ERR_H
#define WIND_ERR_H
// Header that handles errors.

#include <stdarg.h>
#include "WindStream.h"


void WindErr_write(WindStream* wstream, const char* fmt, ...);

void WindErr_print(WindStream* wstream);

void WindErr_clear(WindStream* wstream);

#endif // WIND_ERR_H
