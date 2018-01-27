#ifndef FIXED_MAP_H
#define FIXED_MAP_H
// Header for FIXEDMap Util collection
// Map with fixed sized and stack allocated.

#include <stdlib.h>

// used for static sized keys and items.
#define FIXEDMAP_KEY_LEN 41
#define FIXEDMAP_ITEM_LEN 10

// Macro to reference end pointer of map node key
#define FixedMapNode_END(fmn) (fmn.key + FIXEDMAP_KEY_LEN)

#define FixedMap_FULL(fmap) fmap->len == FIXEDMAP_ITEM_LEN

#define FixedMap_CLEAN(fmap) for(int i = 0; i< FIXEDMAP_ITEM_LEN; i++) { \
                fmap.items[i].item = NULL; \
}


typedef struct
{
        char key[FIXEDMAP_KEY_LEN];
        void* item;
} FixedMapNode;

typedef struct
{
        FixedMapNode items[FIXEDMAP_ITEM_LEN];
        int len;
} FixedMap;

void FixedMap_init(FixedMap* fmap);

#endif //WIND_MAP_H
