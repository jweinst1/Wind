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

void WindComp_clear(void)
{
        WindComp_ITEM_LEN = 0;
        WindComp_BUF[0] = 0;
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

unsigned WindComp_write_typed(unsigned char* item)
{
        switch(*item)
        {
        case WindType_Not:
        case WindType_Sep:
        case WindType_Assign:
        case WindType_None:
                WindComp_BUF[0] = *item;
                WindComp_ITEM_LEN = sizeof(unsigned char);
                return WindComp_ITEM_LEN;
        case WindType_Bool:
                WindComp_BUF[0] = item[0];
                WindComp_BUF[1] = item[1];
                WindComp_ITEM_LEN = sizeof(unsigned char) * 2;
                return WindComp_ITEM_LEN;
        case WindType_Number:
                WindComp_BUF[0] = *item++;
                for(size_t ds = 1; ds < sizeof(double) + 1; ds++)
                        WindComp_BUF[ds] = *item++;
                WindComp_ITEM_LEN = sizeof(unsigned char) + sizeof(double);
                return WindComp_ITEM_LEN;
        default:
                return 0;
        }
}

unsigned WindComp_read(void* dest)
{
        memcpy(dest, WindComp_BUF, WindComp_ITEM_LEN);
        return WindComp_ITEM_LEN;
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
/*Applies series of operations to item in comp*/
int WindComp_map(unsigned char* ins, const unsigned char* insEnd)
{
        unsigned assignMove = 0;
        while(ins != insEnd)
        {
                switch(*ins)
                {
                case WindType_Not:
                        ins++;
                        WindComp_apply_not();
                        break;
                case WindType_Assign:
                        ins++;
                        assignMove = WindComp_write_typed(ins);
                        if(assignMove) ins += assignMove;
                        else return 0;
                        break;
                case WindType_Sep:
                        ins++;
                        break;
                default:
                        return 0;
                }
        }
        return 1;
}
