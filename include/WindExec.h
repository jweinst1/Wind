#ifndef WIND_EXEC_H
#define WIND_EXEC_H

// header for executing commands on the stream.

#include "WindStream.h"

int WindExec_out(WindStream* ws, BufKey bkey);

int WindExec_push(WindStream* ws);

int WindExec_clr(WindStream* ws);

int WindExec_map(WindStream* ws);

#endif
