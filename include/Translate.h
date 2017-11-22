#ifndef WIND_TRANSLATE_H
#define WIND_TRANSLATE_H
//translates source code to instructions

#include <stdlib.h>
#include <ctype.h>
#include "Executor.h"

typedef enum {
        TransState_Off,
        TransState_On
} TransState;


void Translate_conv(WindExecutor* exec, char* srcCode);

#endif
