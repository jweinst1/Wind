#include "WindLoad.h"
#include "WindBuf.h"

// Used as default initalizer for moved C-string result.
static char* NUM_RESULT_INIT = "";

void WindLoad_bool(WindStream* ws, BufKey bkey, int b)
{
        WindBuf* buf = WindStream_get_buf(ws, bkey);
        unsigned char* boolp = b ? WIND_BOOL_T : WIND_BOOL_F;
        // size of bool buf is same for true and false.
        WindBuf_check(&buf, sizeof(WIND_BOOL_T), 10);
        buf->data[buf->len++] = boolp[0];
        buf->data[buf->len++] = boolp[1];

}

void WindLoad_number(WindBuf* wb, const char** code)
{
        char** movedStr = &NUM_RESULT_INIT;
        double numResult = strtod(*code, movedStr);
        WindBuf_write_mark(wb, WindType_Number, &numResult, sizeof(double));
        // Sets the code to new location after number ends.
        *code = *movedStr;
}
