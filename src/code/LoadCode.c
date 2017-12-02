#include "LoadCode.h"


void LoadCode_str_null(WindObject* wobj, char* srcCode)
{
        char* codeBuf = wobj->code;
        strncpy(codeBuf, srcCode, WindObject_CB_SPACE(wobj));
}
