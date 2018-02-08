#include "WindProcess.h"

WindProcess* WindProcess_new_empty(void)
{
        WindProcess* newProc = malloc(sizeof(WindProcess));
        newProc->next = NULL;
        newProc->prev = NULL;
        newProc->ins = NULL;
        newProc->insSize = 0;
        return newProc;
}
