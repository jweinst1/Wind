#include "WindObjectMethods.h"
#include "SafeAlloc.h"

void WindObject_make_str(WindObject* wobj, unsigned char* string, size_t n)
{
        wobj->type = WindType_Str;
        SAFE_ALLOC_M(wobj->value._str.begin, n);
        memcpy(wobj->value._str.begin, string, n);
        wobj->value._str.end = wobj->value._str.begin + n;
}

void WindObject_add(WindObject* wobj1, WindObject* wobj2)
{
        switch(wobj1->type)
        {
        case WindType_Int:
                switch(wobj2->type)
                {
                case WindType_Int:
                        wobj1->value._int += wobj2->value._int;
                        break;
                case WindType_Str:
                        break;
                default:
                        return;
                }
                break;
        case WindType_Str:
                switch(wobj2->type)
                {
                case WindType_Int:
                        break;
                case WindType_Str:
                        break;
                default:
                        return;
                }
                break;
        default:
                return;
        }
}
