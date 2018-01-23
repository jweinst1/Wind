#include "WindNone.h"


WindNone* WindNone_new(void)
{
        WindNone* newNone = malloc(sizeof(WindNone));
        newNone->type = WindType_None;
        newNone->next = NULL;
        newNone->prev = NULL;
        return newNone;
}


WindNone* WindNone_new_arr(int amount)
{
        WindNone* newNone = malloc(sizeof(WindNone) * amount);
        // Types all the objects in the Array.
        WindNone* writer = newNone;
        while(amount--)
        {
                writer->type = WindType_None;
                WindObject_NULLIFY(writer);
                writer++;
        }
        return newNone;
}
