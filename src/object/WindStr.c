#include "WindStr.h"

void WindStr_over_write(WindObject* obj, char* string, size_t n)
{
        if(n > WindStr_CAP(obj)) WindStr_RESERVE(obj, n);
        strncpy(WindStr_BEGIN(obj), string, n);
        WindStr_MARK(obj) = WindStr_BEGIN(obj) + n;
}

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

void WindStr_from_size(WindObject* obj, size_t size)
{
        obj->type = WindType_Str;
        SAFE_ALLOC_M(WindStr_BEGIN(obj), size);
        WindStr_MARK(obj) = WindStr_BEGIN(obj);
        WindStr_END(obj) = WindStr_BEGIN(obj) + size;
        *WindStr_MARK(obj) = '\0';
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
