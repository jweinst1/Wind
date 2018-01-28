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

void* FixedMap_get(FixedMap* fmap, const char* key)
{
        const char* cmpKey1;
        const char* cmpKey2;
        for(int i = 0; i < FIXEDMAP_ITEM_LEN; i++)
        {
                cmpKey1 = fmap->items[i].key;
                cmpKey2 = key;
                while(*cmpKey1 == *cmpKey2)
                {
                        if(*cmpKey1 == '\0' && *cmpKey2 == '\0') return fmap->items[i].val;
                        else
                        {
                                cmpKey1++;
                                cmpKey2++;
                        }
                }
        }
        return NULL;
}
