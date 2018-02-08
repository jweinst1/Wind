#include "Debug.h"



void Debug_process(unsigned char* bytes, int amount)
{
// not implemented yet.
        puts("______Process_Instructions_______");
}

void Debug_bytes(unsigned char* bytes, int amount)
{
        int enumerate = 0;
        puts("_______Bytes_______");
        while(amount--) printf("(%d.) -> %u\n", enumerate++, *bytes++);
        puts("_____Bytes_End_____");
}
