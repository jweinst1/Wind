#include "WindComp.h"

static unsigned char WindComp_BUF[WindComp_BUF_SIZE];

static const unsigned char* WindComp_END = WindComp_BUF + WindComp_BUF_SIZE;

static unsigned WindComp_ITEM_LEN = 0;


unsigned char* WindComp_begin(void)
{
        return WindComp_BUF;
}

const unsigned char* WindComp_end(void)
{
        return WindComp_END;
}

unsigned WindComp_get_len(void)
{
        return WindComp_ITEM_LEN;
}
void WindComp_set_len(unsigned length)
{
        WindComp_ITEM_LEN = length;
}

unsigned char WindComp_get_head(void)
{
        return WindComp_BUF[0];
}

void WindComp_write(void* item, unsigned length)
{
        if(length > WindComp_BUF_SIZE)
        {
                fprintf(stderr, "Memory Error: Cannot fit item at (%p) into size %u\n", item, WindComp_BUF_SIZE);
                exit(1);
        }
        else
        {
                WindComp_ITEM_LEN = length;
                memcpy(WindComp_BUF, item, length);
        }
}

void WindComp_apply_not(void)
{
        switch(WindComp_BUF[0])
        {
        case WindType_Bool:
                WindComp_BUF[1] = !(WindComp_BUF[1]);
                return;
        default:
                // If type is not bool, writes a false boolean. may change this.
                WindComp_BUF[0] = WindType_Bool;
                WindComp_BUF[1] = 0;
                return;
        }
}
