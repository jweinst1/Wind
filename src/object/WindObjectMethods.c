#include "WindObjectMethods.h"
#include "SafeAlloc.h"

void WindObject_make_str(WindObject* wobj, unsigned char* string, size_t n)
{
        wobj->type = WindType_Str;
        SAFE_ALLOC_M(wobj->value._str.begin, n);
        memcpy(wobj->value._str.begin, string, n);
        wobj->value._str.end = wobj->value._str.begin + n;
}
