#ifndef WIND_LIST_H
#define WIND_LIST_H
//wind list header

#include "WindObject.h"
#include "SafeAlloc.h"
#include <stdlib.h>

//initializes a WindList*
#define WindList_INIT(wlst, listSize) do { \
                SAFE_ALLOC_M(wlst, sizeof(WindList)); \
                SAFE_ALLOC_M(wlst->begin, (sizeof(WindItem) * listSize)); \
                wlst->mark = wlst->begin; \
                wlst->end = wlst->mark + listSize; \
} while(0)

// doubles a windlist in size
#define WindList_EXPAND_2(wlst) do { \
                size_t oldLen = wlst->mark - wlst->begin; \
                size_t newCap = (wlst->end - wlst->begin) * 2; \
                SAFE_ALLOC_RE(wlst->begin, newCap * sizeof(WindItem)); \
                wlst->mark = wlst->begin + oldLen; \
                wlst->end = wlst->begin + newCap; \
} while(0)

#define WindList_LEN(wlst) (wlst->mark - wlst->begin)

#define WindList_SPACE(wlst) (wlst->end - wlst->mark)

#define WindList_SIZE(wlst) (wlst->end - wlst->begin)


void WindList_free(WindList* wlst);

WindList* WindList_new(size_t listSize);


#endif
