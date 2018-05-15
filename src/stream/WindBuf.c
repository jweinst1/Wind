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
        // needs moving to windval header
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




void WindBuf_equalize(WindBuf* wb, WindBuf** other)
{
        (*other)->len = wb->len;
        if(wb->cap > (*other)->cap)
        {
                size_t newCap = wb->cap + WindBuf_EQ_SPACE;
                WindBuf_EXPAND((*other), newCap);
        }
}

void WindBuf_equalize_cap(WindBuf* wb, WindBuf** other)
{
        if(wb->cap > (*other)->cap)
        {
                size_t newCap = wb->cap + WindBuf_EQ_SPACE;
                WindBuf_EXPAND((*other), newCap);
        }
}

// Never throws.
void WindBuf_write(WindBuf* wb, void* item, size_t size)
{
        WindBuf_CHECK(wb, size, size + 30);
        memcpy(wb->data, item, size);
}
