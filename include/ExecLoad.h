#ifndef WIND_EXEC_LOAD_H
#define WIND_EXEC_LOAD_H
// header that loads types from instructions into WindObject

#include "WindObject.h"
#include "Instruction.h"
#include "WindList.h"

void ExecLoad_list(WindObject* wobj, unsigned char** ins);

#endif
