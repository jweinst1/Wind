#ifndef WIND_STR_H
#define WIND_STR_H
// Header for string functions

#include "WindObject.h"
#include "SafeAlloc.h"
#include "Instruction.h"
#include <stdlib.h>

#define WindStr_DEF_CAP 30

#define WindStr_BEGIN(obj) (obj->value._str.begin)
#define WindStr_MARK(obj) (obj->value._str.mark)
#define WindStr_END(obj) (obj->value._str.end)

#define WindStr_LEN(obj) (obj->value._str.mark - obj->value._str.begin)
#define WindStr_SPACE(obj) (obj->value._str.end - obj->value._str.mark)
#define WindStr_CAP(obj) (obj->value._str.end - obj->value._str.begin)
#define WindStr_FITS(obj, size) ((obj->value._str.end - obj->value._str.mark) < size)

#define WindStr_INIT(obj) do { \
                SAFE_ALLOC_M(obj->value._str.begin, WindStr_DEF_CAP); \
                WindStr_MARK(obj) = WindStr_BEGIN(obj); \
                WindStr_END(obj) = WindStr_BEGIN(obj) + WindStr_DEF_CAP; \
                *WindStr_MARK(obj) = '\0'; \
} while(0)

// Expands the string to double the size if no space is left.
#define WindStr_EXP2_IF(obj) if( WindStr_SPACE(obj) < 2) { \
                size_t oldLen = WindStr_LEN(obj); \
                size_t newCap = WindStr_CAP(obj) * 2; \
                SAFE_ALLOC_RE(obj->value._str.begin, newCap); \
                obj->value._str.mark = WindStr_BEGIN(obj) + oldLen; \
                obj->value._str.end = WindStr_BEGIN(obj) + newCap; \
}

// Initalizes a string onto on object from instructions
void WindStr_from_ins(WindObject* obj, unsigned char** data);




#endif
