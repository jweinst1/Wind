#include "ExecLoad.h"
#include <stdlib.h>

void ExecLoad_list(WindObject* wobj, unsigned char** ins)
{
        int state = 1;
        size_t inSizeVal = 0;
        WindList* wlst = wobj->value._lst;
        WindItem* curItem = wlst->mark;
        while(state)
        {
                if(curItem == wlst->end) WindList_EXPAND_2(wlst);
                switch(**ins)
                {
                case WindInstruc_ListEnd:
                        *ins += 1;
                        wobj->value._lst->mark = curItem;
                        return;
                case WindInstruc_Int:
                        *ins +=1;
                        curItem->type = WindType_Int;
                        curItem->value._int = *((long*)(*ins));
                        curItem++;
                        *ins += sizeof(long);
                        break;
                case WindInstruc_Str:
                        *ins += 1;
                        inSizeVal = *((size_t*)(*ins));
                        *ins += sizeof(size_t);
                        WindStr_INIT_L(curItem->value._str, inSizeVal);

                        // copies instruction bytes to windstr
                        memcpy(curItem->value._str.begin, *ins, inSizeVal);
                        *ins += inSizeVal;
                        inSizeVal = 0;

                        curItem->type = WindType_Str;
                        break;
                default:
                        wobj->error.active = 1;
                        sprintf(wobj->error.mes, "List Error: Invalid Byte %u for list.\n", **ins);
                        return;
                }
        }
}
