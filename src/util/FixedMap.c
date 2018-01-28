#include "FixedMap.h"

void FixedMap_init(FixedMap* fmap)
{
        fmap->len = 0;
        for(int i = 0; i< FIXEDMAP_ITEM_LEN; i++)
        {
                fmap->items[i].val = NULL;
                fmap->items[i].key[0] = '\0';
        }
}

void FixedMap_set(FixedMap* fmap, const char* key, void* value)
{
        if(!FixedMap_FULL(fmap))
        {
                FixedMapNode* fmnode = fmap->items + fmap->len;
                fmnode->val = value;
                int copyN = FIXEDMAP_KEY_LEN - 1;
                char* writer = fmnode->key;
                while(*key && copyN--) *writer++ = *key++;
                // Appends null character to end of key.
                *writer = '\0';
                fmap->len++;
        }
}
