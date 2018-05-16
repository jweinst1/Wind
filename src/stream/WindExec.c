#include "WindExec.h"

int WindExec_out(WindStream* ws, BufKey bkey)
{
        WindBuf* sbuf;
        WindStream_GET_BUF(ws, sbuf, bkey);
        printf("[ ");
        WindVal_print(sbuf->data, sbuf->data + sbuf->len);
        puts("]");
        return 1;
}

int WindExec_push(WindStream* ws)
{
        size_t pushLen = ws->loadBuf->len;
        WindStream_put_ptr(ws, BufKey_active, ws->loadBuf->data, pushLen);
        return 1;
}

int WindExec_clr(WindStream* ws)
{
        WindStream_reset(ws, BufKey_active);
        return 1;
}

int WindExec_map(WindStream* ws)
{
        // This allows for copying between buffers to be done without size checks
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
        WindStream_swap_buf(ws);

        return 1;
}
