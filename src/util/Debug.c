#include "Debug.h"

void Debug_stream(WindStream* ws)
{
        puts("_____Wind_Stream_Debug_____");
        puts("...........Errors..........");
        printf("Has Error: %s\n", ws->hasErr ? "true" : "false");
        puts("........ActiveBuf..........");
        printf("@ = %p\nlen = %lu\ncap = %lu\n", ws->activeBuf, ws->activeBuf->len, ws->activeBuf->cap);
        puts("........AltBuf..........");
        printf("@ = %p\nlen = %lu\ncap = %lu\n", ws->altBuf, ws->altBuf->len, ws->altBuf->cap);
        puts("___________________________");
}
