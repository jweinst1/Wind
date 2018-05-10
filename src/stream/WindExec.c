#include "WindExec.h"

int WindExec_out(WindStream* ws, BufKey bkey)
{
        WindBuf* sbuf;
        WindStream_GET_BUF(ws, sbuf, bkey);
        printf("[ ");
        for(size_t i = 0; i < sbuf->len; i++)
        {
                switch(sbuf->data[i])
                {
                case WindType_None:
                        printf("None ");
                        break;
                case WindType_Bool:
                        i++;
                        printf(sbuf->data[i] ? "True " : "False ");
                        break;
                case WindType_Not:
                        printf("! ");
                        break;
                case WindType_Sep:
                        printf("| ");
                        break;
                default:
                        WindStream_write_err(ws, "Cannot recognize item with byte %u", sbuf->data[i]);
                        return 0;
                }
        }
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

        return 1;
}
