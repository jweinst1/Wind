#include "ExecLoad.h"

void ExecLoad_list(WindObject* wobj, unsigned char** ins)
{
        int state = 1;
        WindList* wlst = wobj->value._lst;
        while(state)
        {
                switch(**ins)
                {
                default:
                        return;
                }
        }
}
