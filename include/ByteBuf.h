#ifndef BYTE_BUF_H
#define BYTE_BUF_H
// Util header for byte buf object

#include <stdlib.h>

#define ByteBuf_START_SIZE 100

typedef struct
{
        unsigned char* begin;
        unsigned char* mark;
        unsigned char* end;
} ByteBuf;



#endif // BYTE_BUF_H
