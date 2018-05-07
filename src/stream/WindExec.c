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
                default:
                        WindStream_write_err(ws, "Cannot recognize item with byte %u", sbuf->data[i]);
                        return 0;
                }
        }
        puts("]");
        return 1;
}
