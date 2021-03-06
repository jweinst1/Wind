#ifndef WIND_EXEC_H
#define WIND_EXEC_H

// header for executing commands on the stream.

#include "WindType.h"
#include "WindData.h"
#include "WindState.h"
#include "WindComp.h"
#include "IOUtil.h"



int WindExec_out(void);

int WindExec_push(void);

void WindExec_clr(void);

int WindExec_map(void);

int WindExec_filter(void);

int WindExec_save(void);

int WindExec_load(void);

#endif
