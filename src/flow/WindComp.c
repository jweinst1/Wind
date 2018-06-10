#include "WindComp.h"

static unsigned char WindComp_BUF[WindComp_BUF_SIZE];

// Access to body chunk of comp item.
static unsigned char* WindComp_BODY = WindComp_BUF + 1;
// End of comp item.
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

unsigned WindComp_write_typed(const unsigned char* item)
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

unsigned WindComp_apply_plus(unsigned char* args, const unsigned char* argsEnd)
{
        if(WindComp_BUF[0] != WindType_Number)
        {
                WindState_write_err("Attempted to use + operator on type: '%s'", WindType_get_str(WindComp_BUF[0]));
                return 0;
        }
        unsigned char* mover = args;
        while(mover != argsEnd)
        {
                switch(*mover)
                {
                case WindType_Number:
                        mover++;
                        WindComp_PLUS_NUM(WindComp_BODY, mover);
                        mover += sizeof(double);
                        break;
                case WindType_Bool:
                        // Adds 1 for true, 0 for False.
                        mover++;
                        *(double*)(WindComp_BODY) += *mover++;
                        break;
                case WindType_Sep:
                        return mover - args;
                default:
                        WindState_write_err("Attempted to use + operator on arg with type: '%s'", WindType_get_str(*mover));
                        return 0;
                }
        }
        return mover - args;
}

unsigned WindComp_apply_minus(unsigned char* args, const unsigned char* argsEnd)
{
        if(WindComp_BUF[0] != WindType_Number)
        {
                WindState_write_err("Attempted to use - operator on type: '%s'", WindType_get_str(WindComp_BUF[0]));
                return 0;
        }
        unsigned char* mover = args;
        while(mover != argsEnd)
        {
                switch(*mover)
                {
                case WindType_Number:
                        mover++;
                        WindComp_MINUS_NUM(WindComp_BODY, mover);
                        mover += sizeof(double);
                        break;
                case WindType_Bool:
                        // Adds 1 for true, 0 for False.
                        mover++;
                        *(double*)(WindComp_BODY) -= *mover++;
                        break;
                case WindType_Sep:
                        return mover - args;
                default:
                        WindState_write_err("Attempted to use - operator on arg with type: '%s'", WindType_get_str(*mover));
                        return 0;
                }
        }
        return mover - args;
}

unsigned WindComp_apply_multiply(unsigned char* args, const unsigned char* argsEnd)
{
        if(WindComp_BUF[0] != WindType_Number)
        {
                WindState_write_err("Attempted to use * operator on type: '%s'", WindType_get_str(WindComp_BUF[0]));
                return 0;
        }
        unsigned char* mover = args;
        while(mover != argsEnd)
        {
                switch(*mover)
                {
                case WindType_Number:
                        mover++;
                        WindComp_MULTIPLY_NUM(WindComp_BODY, mover);
                        mover += sizeof(double);
                        break;
                case WindType_Bool:
                        // Adds 1 for true, 0 for False.
                        mover++;
                        *(double*)(WindComp_BODY) *= *mover++;
                        break;
                case WindType_Sep:
                        return mover - args;
                default:
                        WindState_write_err("Attempted to use * operator on arg with type: '%s'", WindType_get_str(*mover));
                        return 0;
                }
        }
        return mover - args;
}

int WindComp_check_not(void)
{
        switch(WindComp_BUF[0])
        {
        case WindType_Bool:
                return !(*WindComp_BODY);
        case WindType_None:
                return 1;
        case WindType_Number:
                return !(*(double*)(WindComp_BODY));
        default:
                return 0;
        }
}

int WindComp_check_lt(unsigned char** arg)
{
        int result = 0;
        switch(WindComp_BUF[0])
        {
        case WindType_Number:
                switch(**arg)
                {
                case WindType_Number:
                        *arg += 1;
                        result = WindComp_LT_NUM(WindComp_BODY, *arg);
                        *arg += sizeof(double);
                        return result;
                default:
                        return 0;
                }
        case WindType_Bool:
                switch(**arg)
                {
                case WindType_Bool:
                        result = WindComp_BUF[1] < (*arg)[1];
                        *arg += 2;
                        return result;
                }
        default:
                return 0;
        }
}

int WindComp_check_gt(unsigned char** arg)
{
        int result = 0;
        switch(WindComp_BUF[0])
        {
        case WindType_Number:
                switch(**arg)
                {
                case WindType_Number:
                        *arg += 1;
                        result = WindComp_GT_NUM(WindComp_BODY, *arg);
                        *arg += sizeof(double);
                        return result;
                default:
                        return 0;
                }
        case WindType_Bool:
                switch(**arg)
                {
                case WindType_Bool:
                        result = WindComp_BUF[1] > (*arg)[1];
                        *arg += 2;
                        return result;
                }
        default:
                return 0;
        }
}

/*Applies series of operations to item in comp*/
// THROWS with return of 0
int WindComp_map(unsigned char* ins, const unsigned char* insEnd)
{
        unsigned moveChecker = 0;
        //int boolResult = 0;
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
                        moveChecker = WindComp_write_typed(ins);
                        if(moveChecker) ins += moveChecker;
                        else return 0;
                        break;
                case WindType_Plus:
                        ins++;
                        moveChecker = WindComp_apply_plus(ins, insEnd);
                        if(moveChecker) ins += moveChecker;
                        else return 0;
                        break;
                case WindType_Minus:
                        ins++;
                        moveChecker = WindComp_apply_minus(ins, insEnd);
                        if(moveChecker) ins += moveChecker;
                        else return 0;
                        break;
                case WindType_Multiply:
                        ins++;
                        moveChecker = WindComp_apply_multiply(ins, insEnd);
                        if(moveChecker) ins += moveChecker;
                        else return 0;
                        break;
                case WindType_Del:
                        ins++;
                        WindComp_clear();
                        return 1;
                case WindType_Sep:
                        ins++;
                        break;
                default:
                        WindState_write_err("Cannot map argument of type: '%s'", WindType_get_str(*ins));
                        return 0;
                }
        }
        return 1;
}


int WindComp_filter(unsigned char* ins, const unsigned char* insEnd)
{
        //unsigned moveChecker = 0;
        // Active while object has still not failed a filter.
        while(ins != insEnd)
        {
                switch(*ins)
                {
                case WindType_Not:
                        ins++;
                        if(!WindComp_check_not()) goto FILTER_FAILURE;
                        break;
                case WindType_Lt:
                        ins++;
                        if(!WindComp_check_lt(&ins)) goto FILTER_FAILURE;
                        break;
                case WindType_Gt:
                        ins++;
                        if(!WindComp_check_gt(&ins)) goto FILTER_FAILURE;
                        break;
                case WindType_Sep:
                        ins++;
                        break;
                default:
                        WindState_write_err("Cannot run filter operation with type: '%s'", WindType_get_str(*ins));
                        return 0;
                }
        }
        return 1;
FILTER_FAILURE:
        WindComp_clear();
        return 1;
}
