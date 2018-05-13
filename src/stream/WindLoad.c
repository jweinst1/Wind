#include "WindLoad.h"

void WindLoad_bool(WindStream* ws, BufKey bkey, int b)
{
        WindBuf* buf = WindStream_get_buf(ws, bkey);
        unsigned char* boolp = b ? WIND_BOOL_T : WIND_BOOL_F;
        // size of bool buf is same for true and false.
        WindBuf_CHECK(buf, sizeof(WIND_BOOL_T), 10);
        buf->data[buf->len++] = boolp[0];
        buf->data[buf->len++] = boolp[1];

}
