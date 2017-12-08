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

void WindList_print(WindList* wlst)
{
        WindItem* witem;
        printf("[ ");
        for(witem = wlst->begin; witem != wlst->end; witem++)
        {
                switch(witem->type)
                {
                case WindType_Int:
                        printf("%ld ", witem->value._int);
                        break;
                case WindType_None:
                        printf("None ");
                        break;
                case WindType_Str:
                        printf("\"%.*s\" ", (int)(witem->value._str.end - witem->value._str.begin), witem->value._str.begin);
                        break;
                case WindType_List:
                        // recursive call for nested lists
                        WindList_print(witem->value._lst);
                        break;
                }
        }
        puts("]");
}
