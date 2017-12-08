#include "WindList.h"

void WindList_free(WindList* wlst)
{
        free(wlst->begin);
        free(wlst);
}

WindList* WindList_new(size_t listSize)
{
        WindList* wlst = NULL;
        WindList_INIT(wlst, listSize);
        return wlst;
}

WindItem* WindList_get(WindList* wlst, size_t index)
{
        return wlst->begin + index;
}
