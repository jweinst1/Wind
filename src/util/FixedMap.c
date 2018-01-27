#include "FixedMap.h"

void FixedMap_init(FixedMap* fmap)
{
        fmap->len = 0;
        for(int i = 0; i< FIXEDMAP_ITEM_LEN; i++)
        {
                fmap->items[i].item = NULL;
                fmap->items[i].key[0] = '\0';
        }
}
