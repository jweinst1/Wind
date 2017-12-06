#include "WindList.h"

WindList* WindList_new(WindList* lst, size_t listSize)
{
        WindList* wlst = NULL;
        WindList_INIT(wlst, listSize);
        return wlst;
}
