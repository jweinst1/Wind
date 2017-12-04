#ifndef WIND_STR_H
#define WIND_STR_H
//definition for string object in wind.

#include "SafeAlloc.h"

// inits str with safe alloc
#define WindStr_INIT(wstr, strSize) do { \
                SAFE_ALLOC_M(wstr->begin, strSize); \
                wstr->end = wstr->begin + strSize; \
} while(0)

#define WindStr_INIT_L(wstr, strSize) do { \
                SAFE_ALLOC_M(wstr.begin, strSize); \
                wstr.end = wstr.begin + strSize; \
} while(0)

#define WindStr_RESIZE_L(wstr, strSize) do { \
                SAFE_ALLOC_RE(wstr.begin, strSize); \
                wstr.end = wstr.begin + strSize; \
} while(0)

//frees windstr
#define WindStr_FREE(wstr) free(wstr->begin)

// frees non-ptr windstr
#define WindStr_FREE_L(wstr) free(wstr.begin)

#define WindStr_LEN(wstr) wstr->end - wstr->begin

#define WindStr_LEN_L(wstr) (wstr.end - wstr.begin)


struct WindStr
{
        char* begin;
        char* end;
};

typedef struct WindStr WindStr;

void WindStr_concat(WindStr* ws1, WindStr* ws2);

#endif
