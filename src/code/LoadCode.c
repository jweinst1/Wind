#include "LoadCode.h"


void LoadCode_str_null(WindObject* wobj, char* srcCode)
{
        char* codeBuf = wobj->code;
        strncpy(codeBuf, srcCode, WindObject_CB_SPACE(wobj));
}

void LoadCode_upto_null(WindObject* wobj, char* restrict srcCode)
{
        while(*srcCode)
        {
                if(WindObject_CB_FULL(wobj)) return;
                else *(wobj->codeMark++) = *srcCode++;
        }
}
