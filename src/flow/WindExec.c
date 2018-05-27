#include "WindExec.h"


int WindExec_out(void)
{
        unsigned char* start = WindData_active_start();
        unsigned char* end = WindData_active_ptr();
        printf("[ ");
        while(start != end)
        {
                switch(*start)
                {
                case WindType_None:
                        start++;
                        printf("None ");
                        break;
                case WindType_Bool:
                        start++;
                        printf(*start++ ? "True " : "False ");
                        break;
                case WindType_Number:
                        start++;
                        if(WindVal_fl_is_int(start)) printf("%ld ", (long)(*(double*)start));
                        else printf("%.3f ", *(double*)start);
                        start += sizeof(double);
                        break;
                case WindType_Assign:
                        start++;
                        printf("= ");
                        break;
                case WindType_Not:
                        start++;
                        printf("! ");
                        break;
                case WindType_Sep:
                        start++;
                        printf("| ");
                        break;
                default:
                        return 0;         // error case.
                }
        }
        puts("]");
        return 1;
}

int WindExec_push(void)
{
        size_t pushLen = WindData_load_len();
        WindData_active_write(WindData_load_start(), pushLen);
        return 1;
}

void WindExec_clr(void)
{
        WindData_active_reset();
}

int WindExec_map(void)
{
        /* This allows for copying between buffers to be done without size checks
           WindBuf_equalize(ws->activeBuf, &(ws->altBuf));
           // allows for writing of larger values from load buf.
           WindBuf_equalize_cap(ws->loadBuf, &(ws->altBuf));

           // Traversing Pointers
           unsigned char* loadPtr;
           unsigned char* loadEnd;

           unsigned char* activePtr = ws->activeBuf->data;
           unsigned char* activeEnd = activePtr + ws->activeBuf->len;

           WindBuf* target = ws->altBuf;
           unsigned char* copyAlt = target->data;
           WindBuf_HEAD_RE(target);
           while(activePtr != activeEnd)
           {
                // needs movable head.
                WindVal_copy(&copyAlt, &activePtr, 1);
                // These are restarted each loop since entire map seq
                // is applied to one value at a time.
                loadPtr = ws->loadBuf->data;
                loadEnd = loadPtr + ws->loadBuf->len;
                while(loadPtr != loadEnd)
                {
                        switch(*loadPtr)
                        {
                        case WindType_Not:
                                loadPtr++;
                                WindVal_apply_not(target->head);
                                break;
                        case WindType_Assign:
                                loadPtr++;
                                WindVal_apply_assign(target->head, loadPtr);
                                WindVal_move(&loadPtr, 1);
                                break;
                        case WindType_Sep:
                                loadPtr++;
                                break;
                        default:
                                WindStream_write_err(ws, "Unrecognized map argument %u", *loadPtr);
                                return 0;
                        }
                }
                WindVal_move(&(target->head), 1);
           }
           // If mapping resulted in shrink operation, levels head with len.
           WindBuf_HEAD_LEN(target);
           WindStream_swap_buf(ws);*/

        return 1;
}
