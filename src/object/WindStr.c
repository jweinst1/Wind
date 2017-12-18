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
        // Appends null character
        *WindStr_MARK(obj) = '\0';
        *data += 1; // moves past the other string ins.
}

void WindStr_append(WindObject* obj1, WindObject* obj2)
{
        if(!WindStr_FITS(obj1, WindStr_LEN(obj2))) WindStr_RESERVE(obj1, WindStr_LEN(obj2));
        char* cPtr = WindStr_BEGIN(obj2);
        while(*cPtr)
        {
                *WindStr_MARK(obj1)++ = *cPtr++;
        }
        // Appends null character
        *WindStr_MARK(obj1) = '\0';
}
