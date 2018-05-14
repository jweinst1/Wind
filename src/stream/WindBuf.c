#include "WindBuf.h"

WindBuf* WindBuf_new(size_t size)
{
        WindBuf* newbuf = malloc(sizeof(WindBuf) + (sizeof(unsigned char) * size));
        newbuf->len = 0;
        newbuf->cap = size;
        newbuf->head = newbuf->data;
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
                // needs more types handled.
                default:
                        return NULL;
                }
        }
        if(index) return NULL;
        else return startPtr;
}

unsigned char* WindBuf_place(WindBuf* wb, void* item, size_t size)
{
        WindBuf_CHECK(wb, size, size + 5);
        unsigned char* reader = item;
        unsigned char* placed = wb->data + wb->len;
        for(size_t i = 0; i < size; i++) wb->data[wb->len++] = reader[i];
        return placed;
}

long WindBuf_count(WindBuf* wb)
{
        // Needs updating
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


void WindBuf_equalize(WindBuf* wb, WindBuf** other)
{
        (*other)->len = wb->len;
        if(wb->cap > (*other)->cap)
        {
                size_t newCap = wb->cap + WindBuf_EQ_SPACE;
                WindBuf_EXPAND((*other), newCap);
        }
}
