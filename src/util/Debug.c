#include "Debug.h"

void Debug_buf(WindBuf* wb)
{
        puts("......Buf..Data............");
        for(size_t i = 0; i < wb->len; i++)
        {
                printf("Item: %lu\n", i);
                switch(wb->data[i])
                {
                case WindType_None:
                        puts("None");
                        break;
                default:
                        printf("Unknown: %u\n", wb->data[i]);
                }
        }
}

void Debug_stream(WindStream* ws)
{
        puts("_____Wind_Stream_Debug_____");
        puts("...........Errors..........");
        printf("Has Error: %s\n", ws->hasErr ? "true" : "false");
        puts("........ActiveBuf..........");
        printf("@ = %p\nlen = %lu\ncap = %lu\n", ws->activeBuf, ws->activeBuf->len, ws->activeBuf->cap);
        Debug_buf(ws->activeBuf);
        puts("........AltBuf..........");
        printf("@ = %p\nlen = %lu\ncap = %lu\n", ws->altBuf, ws->altBuf->len, ws->altBuf->cap);
        Debug_buf(ws->altBuf);
        puts("........LoadBuf..........");
        printf("@ = %p\nlen = %lu\ncap = %lu\n", ws->loadBuf, ws->loadBuf->len, ws->loadBuf->cap);
        Debug_buf(ws->loadBuf);
        puts("___________________________");
}
