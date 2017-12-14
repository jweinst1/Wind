#ifndef WIND_EXEC_H
#define WIND_EXEC_H
// header for executing code on WindTuring

#include "WindTuring.h"
#include "ByteBuf.h"
#include "WindInfo.h"



// Determines if the next instruction is nested or not.
int Exec_is_nested(unsigned char* data);

int Exec_load(WindCell* cell, unsigned char** data);


void Exec_code(unsigned char* begin, unsigned char* end);


#endif
