#ifndef WIND_EXEC_H
#define WIND_EXEC_H

// header for executing commands on the stream.

#include "WindType.h"
#include "WindData.h"
#include "WindVal.h"

int WindExec_out(WindStream* ws, BufKey bkey);

int WindExec_push(WindStream* ws);

void WindExec_clr(void);

int WindExec_map(WindStream* ws);

#endif
