#include "WindStr.h"

void WindStr_from_ins(WindObject* obj, unsigned char** data)
{
        obj->type = WindType_Str;
        WindStr_INIT(obj);
        while(**data != WindInstruc_String)
        {
                WindStr_EXP2_IF(obj);
                *WindStr_MARK(obj)++ = **data;
                *data += 1;
        }
        *data += 1; // moves past the other string ins.
}
