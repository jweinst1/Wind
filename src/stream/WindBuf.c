#include "WindBuf.h"

WindBuf* WindBuf_new(size_t size)
{
        WindBuf* newbuf = malloc(sizeof(WindBuf) + (sizeof(unsigned char) * size));
        newbuf->len = 0;
        newbuf->cap = size;
        return newbuf;
}

unsigned char* WindBuf_get(WindBuf* wb, size_t index)
{
        unsigned char* startPtr = wb->data;
        unsigned char* endPtr = wb->data + wb->len;
        while(startPtr != endPtr && index--)
        {
                // Advances pointer based on type and it's offset.
                switch(*startPtr)
                {
                case WindType_None:
                        startPtr++;
                        break;
                default:
                        return NULL;
                }
        }
        if(index) return NULL;
        else return startPtr;
}

long WindBuf_count(WindBuf* wb)
{
        long total = 0;
        unsigned char* startPtr = wb->data;
        unsigned char* endPtr = wb->data + wb->len;
        while(startPtr != endPtr)
        {
                switch(*startPtr)
                {
                case WindType_None:
                        total++;
                        startPtr++;
                        break;
                default:
                        return -1;
                }
        }
        return total;
}
