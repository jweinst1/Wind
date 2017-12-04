#include "WindStr.h"
#include <string.h>


void WindStr_concat(WindStr* ws1, WindStr* ws2)
{
        size_t oldSize = ws1->end - ws1->begin;
        size_t catSize = oldSize + (ws2->end - ws2->begin);
        SAFE_ALLOC_RE(ws1->begin, catSize);
        memcpy(ws1->begin + oldSize, ws2->begin, (ws2->end - ws2->begin));
}
