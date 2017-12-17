#ifndef WIND_TRNASLATE_H
#define WIND_TRNASLATE_H

#include <stdlib.h>
#include "Instruction.h"
#include "ByteBuf.h"

// default size for byte buf
#define TRANS_BUF_SIZE 2000

ByteBuf* Translate_code(char* srcCode);



#endif
